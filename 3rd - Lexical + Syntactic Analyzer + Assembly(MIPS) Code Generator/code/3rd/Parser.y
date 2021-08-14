%{
          
     #include <stdio.h>
     #include <iostream>
     #include <stdlib.h>
     #include<time.h>
     #include <math.h>
     #include <string.h>
     #include <string>
     #include <unordered_map> 
     #include <algorithm>
     #include <fstream>
     #include<stack>
     #include<vector>



     using namespace std;

     int current_dtype;
     int is_declaration = 0;
     int is_loop = 0;
     int is_func = 0;
     int func_type;
     int out = 0;
     int rhs = 0;
     int scopeNo=0;
     int prevscopeNo=0;
     int clacStart=0;
     int conditionNo=0;
     int loopNo=0;

     struct perScope{
          int type;
          int scope;
          int cnt;
          int stack;
          int stackPlace;
     };
     unordered_map<string, struct perScope> umap; 
     unordered_map<int, int> scopeVars; 
     

     ofstream MyFile("output.out");

     vector<pair<int,int>> scopeVector;

     extern int yylex();
     extern FILE* yyin;
     void yyerror(const char* s);
     void type_check(int,int,int);
     int yyparse();

%}


%define parse.error verbose

%union {
     struct t {
          char*  _val;
          int    _cnt;
          int _datatype; //1:int 2:float 3:char 4:string :void 6:double
          char _byname [2056] ;
          char _byid [2056];
          int _typ; //1:const
          char _asm[2056];
          int _scopeNo;
          int _numVal;
          int _stackPlace;
          int _isVar;
          int _isSingle;
          int _arrParam;
          int _arrVar;
     }token;
}


/*==============================================================types===============================================================*/

%token <token>   TOKEN_ID TOKEN_RETURN TOKEN_STRINGCONST TOKEN_MAINFUNC TOKEN_PRFUNC TOKEN_LOOP TOKEN_ELSECONDITION TOKEN_IFCONDITION TOKEN_CONTINUESTMT TOKEN_BREAKSTMT TOKEN_INTTYPE TOKEN_FLOATTYPE TOKEN_DOUBLETYPE TOKEN_CHARTYPE TOKEN_STRINGTYPE TOKEN_VOIDTYPE;
%token <token>   TOKEN_CHARCONST ;
%token <token>   TOKEN_ASSIGNOP TOKEN_LEFTPAREN TOKEN_RIGHTPAREN TOKEN_LCB TOKEN_RCB TOKEN_SEMICOLON TOKEN_COMMA TOKEN_UNTIL TOKEN_LB TOKEN_RB;
%token <token>   TOKEN_INTCONST;
%token <token>   TOKEN_FLOATCONST;
%token <token>   TOKEN_PLUS TOKEN_MINUS TOKEN_MUL TOKEN_DIV TOKEN_POW;
%token <token>   TOKEN_LOGICAND TOKEN_LOGICOR TOKEN_LOGICNOT  TOKEN_BITWISEAND TOKEN_BITWISEOR;
%token <token>   TOKEN_EQ TOKEN_NOTEQ TOKEN_GR TOKEN_LS TOKEN_LSEQ TOKEN_GREQ



%type <token> constants typeSpecifier  identifier   declaration_list sub_decl  
%type <token> sub_expr program globalVars loopStmt conditionStmt
%type <token> arithmetic_expr stmt
%type <token> assignment_expr
%type <token> functionCall arg argumentList arguments
%type <token> array_access expression singleStmt printFunc statements  array_init array_init_vars
%type <token> lhs compoundStmt  function declaration parameter parameter_list


/*==============================================================precedances===============================================================*/

%left TOKEN_COMMA
%right TOKEN_ASSIGNOP
%left TOKEN_LOGICOR
%left TOKEN_LOGICAND
%left TOKEN_BITWISEOR TOKEN_BITWISEAND
%left TOKEN_EQ TOKEN_NOTEQ
%left TOKEN_GR TOKEN_LS TOKEN_LSEQ TOKEN_GREQ
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MUL TOKEN_DIV
%left TOKEN_POW
%right TOKEN_LOGICNOT

%nonassoc UMINUS



/*==============================================================grammar===============================================================*/

%start program

%%

program:                globalVars  {strcpy($$._byid," PROGRAM ");strcpy($$._byname," PROGRAM ");strcat($$._byid,$1._byid);strcat($$._byname,$1._byname);

                                   strcpy($$._asm,"\n.data");
                                   strcat($$._asm,"\n\tbackn: .asciiz \"\\n\"");
                                   strcat($$._asm,"\n.text");
                                   strcat($$._asm,"\n.globl main");
                                   strcat($$._asm,$1._asm);

                                                                     
                                     if (out==1) {
                                        cout << "\n\n\n[+] Parse : \n\n"<<$$._byid;
                                        cout << endl << endl << endl << "[+] ASM :" << $$._asm << endl;
                                     }
                                     else if (out == 0)
                                          cout << "\n[+] Parse : \n"<<$$._byname;
                                     else
                                        MyFile<<"[-] ERROR IN OUTPUT TYPE : WRONG OPTION";

                                   


                                    }
                        ;


globalVars:              typeSpecifier   identifier   TOKEN_ASSIGNOP   constants TOKEN_SEMICOLON   globalVars {  
                                                                                                                   
                                                                                                                   strcpy($$._byid," globalVars ");
                                                                                                                   //strcat($$._byid,to_string(scopeNo).c_str());
                                                                                                                   strcat($$._byid,$1._byid);
                                                                                                                   strcat($$._byid,$2._byid);
                                                                                                                   strcat($$._byid," = ");
                                                                                                                   strcat($$._byid,$4._byid);
                                                                                                                   strcat($$._byid," ; ");
                                                                                                                   strcat($$._byid,$6._byid);

                                                                                                                     string tmp;
                                                                                                                   tmp ="\n" + string($2._val) +":\t .long \t" + string($4._val);
                                                                                                                   strcat($$._asm,tmp.c_str());

                                                                                                                   strcat($$._asm,$6._asm);

                                                                                                                   strcpy($$._byname," globalVars ");
                                                                                                                   strcat($$._byname,$1._byname);
                                                                                                                   strcat($$._byname,$2._byname);
                                                                                                                   strcat($$._byname," TOKEN_ASSIGNOP ");
                                                                                                                   strcat($$._byname,$4._byname);
                                                                                                                   strcat($$._byname," TOKEN_SEMICOLON ");
                                                                                                                   strcat($$._byname,$6._byname);
                                                                                                                   
                                                                                                                   if ( $1._datatype == 5) 
                                                                                                                        yyerror("variable cant be of type VOID"); } 
                                                                                                                   
                        |function
                                                                                                       {strcpy($$._byid,$1._byid);
                                                                                                                   strcpy($$._byname,$1._byname);strcpy($$._asm,$1._asm);}
                        ;

function:                typeSpecifier   TOKEN_MAINFUNC{ 

                            func_type = current_dtype;
                            is_declaration = 0;
                            

                        }
                        TOKEN_LEFTPAREN {prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0; }  TOKEN_RIGHTPAREN {
                          
                                            is_declaration = 0;
							          is_func = 1;

                        }compoundStmt    {is_func = 0; if ($1._datatype != 1 )yyerror("main function must be of type INT");
                        
                                             strcpy($$._byid," main_function ");
                                             strcat($$._byid,$1._byid);
                                             strcat($$._byid," main ");
                                             strcat($$._byid," ( ");
                                             strcat($$._byid," ) ");
                                             strcat($$._byid,$8._byid);

                                             strcpy($$._asm,"\nmain :");
                                             char tmp[200];
                                             sprintf(tmp,"\n\tdaddiu  $sp,$sp,-%d",(scopeVars[$8._scopeNo]+2)*4);
                                             strcat($$._asm,tmp);
                                             string s = "\n\tsd      $fp,"+to_string(scopeVars[$8._scopeNo]*4)+"($sp)";
                                             strcat($$._asm,s.c_str());
                                             strcat($$._asm,"\n\tmove    $fp,$sp");

                                             strcat($$._asm,$8._asm);

                                             strcat($$._asm,"\n\tmove    $v0,$0");
                                             strcat($$._asm,"\n\tmove    $sp,$fp");
                                             s = "\n\tld      $fp,"+to_string(scopeVars[$8._scopeNo]*4)+"($sp)";
                                             strcat($$._asm,s.c_str());
                                             s = "\n\tdaddiu  $sp,$sp," + to_string((scopeVars[$8._scopeNo]+2)*4);
                                             strcat($$._asm,s.c_str());
                                             strcat($$._asm,"\n\tj       $31");
                                             strcat($$._asm,"\n\tnop");
                                             
                                             strcpy($$._byname," main_function ");
                                             strcat($$._byname,$1._byname);
                                             strcat($$._byname," TOKEN_MAINFINC  ");
                                             strcat($$._byname," TOKEN_LEFTPARAN ");
                                             strcat($$._byname," TOKEN_RIGHTPARAN ");
                                             strcat($$._byname,$8._byname);
                        
                                         }
                        |typeSpecifier   identifier{

                            func_type = current_dtype;
                            is_declaration = 0;
                            $2._datatype=$1._datatype;

                        } TOKEN_LEFTPAREN {prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;is_func = 1; } argumentList TOKEN_RIGHTPAREN{
                          
                                            is_declaration = 0;
									
                                             $2._cnt=$6._cnt;
                                            umap[$2._val].cnt=$2._cnt;

                        }
                        compoundStmt  {is_func = 0;} function  {

                                            strcpy($$._byid," function ");
                                             strcat($$._byid,$1._byid);
                                             strcat($$._byid,$2._byid);
                                             strcat($$._byid," ( ");
                                             strcat($$._byid,$6._byid);
                                             strcat($$._byid," ) ");
                                             strcat($$._byid,$9._byid);
                                             strcat($$._byid,$11._byid);

                                             string s;
                                             s = "\n" + string($2._val) + ":";
                                             strcpy($$._asm,s.c_str());
                                             char tmp[200];
                                             sprintf(tmp,"\n\tdaddiu  $sp,$sp,-%d",(scopeVars[$9._scopeNo]+2)*4);
                                             strcat($$._asm,tmp);
                                             s = "\n\tsd      $fp,"+to_string(scopeVars[$9._scopeNo]*4)+"($sp)";
                                             strcat($$._asm,s.c_str());
                                             strcat($$._asm,"\n\tmove    $fp,$sp");
                                             cout << "debug-c->" << umap[$2._val].cnt << endl;
                                             for(int i=0;i<umap[$2._val].cnt;i++) {
                                                  string s = "\n\tsw  $a" + to_string(i) + "," + to_string(i*4) + "($fp)";
                                                  strcat($$._asm,s.c_str());
                                             }

                                             strcat($$._asm,$9._asm);

                                             strcat($$._asm,"\n\tmove    $sp,$fp");
                                             s = "\n\tld      $fp,"+to_string(scopeVars[$9._scopeNo]*4)+"($sp)";
                                             strcat($$._asm,s.c_str());
                                             s = "\n\tdaddiu  $sp,$sp," + to_string((scopeVars[$9._scopeNo]+2)*4);
                                             strcat($$._asm,s.c_str());
                                             strcat($$._asm,"\n\tj       $31");
                                             strcat($$._asm,"\n\tnop");

                                             strcat($$._asm,$11._asm);

                                             
                                             
                                             
                                             strcpy($$._byname," function ");
                                             strcat($$._byname,$1._byname);
                                             strcat($$._byname,$2._byname);
                                             strcat($$._byname," TOKEN_LEFTPARAN ");
                                             strcat($$._byname,$6._byname);
                                             strcat($$._byname," TOKEN_RIGHTPARAN ");
                                             strcat($$._byname,$9._byname);
                                             strcat($$._byname,$11._byname);
                                      } 
                        ;

argumentList:            arguments                           {if($$._cnt > 4) yyerror("too many arguments");
                                                              strcpy($$._byid," argumentList "); 
                                                              strcpy($$._byname," argumentList "); 
                                                              strcat($$._byname,$1._byname);
                                                              strcat($$._byid, $1._byid);
                                                             }
                        |                                   {$$._cnt=0;}
                        ;

arguments:               arguments TOKEN_COMMA arg          { $$._cnt=$$._cnt+1;
                                                              strcpy($$._byid," arguments "); 
                                                              strcpy($$._byname," arguments "); 
                                                              strcat($$._byname,$1._byname);
                                                              strcat($$._byid, $1._byid); 
                                                              strcat($$._byname,"TOKEN_COMMA");
                                                              strcat($$._byid," , "); 
                                                              strcat($$._byname,$3._byname);
                                                              strcat($$._byid, $3._byid);

                                                            }
                        |arg
                        ;

arg:                     typeSpecifier identifier           { $$._cnt=1;
                                                              strcpy($$._byid," arg "); 
                                                              strcpy($$._byname," arg "); 
                                                              strcat($$._byname,$1._byname);
                                                              strcat($$._byid, $1._byid); 
                                                              strcat($$._byname,$2._byname);
                                                              strcat($$._byid, $2._byid);

                                                            }      
                        |typeSpecifier identifier TOKEN_LB constants TOKEN_RB { $$._cnt=1;
                                                                                strcpy($$._byname," arg ");
                                                                                strcpy($$._byid," arg "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname,$2._byname); 
                                                                                strcat($$._byid,$2._byid);
                                                                                strcat($$._byname," TOKEN_LB "); 
                                                                                strcat($$._byid," [ ");
                                                                                strcat($$._byname,$4._byname); 
                                                                                strcat($$._byid,$4._byid);
                                                                                strcat($$._byname," TOKEN_RB "); 
                                                                                strcat($$._byid," ] ");

                                                                                if ($4._datatype != 1)
                                                                                     yyerror("array index must be of type integer");
                                   
                                                                              }
                        ;


statements:              statements stmt  { strcpy($1._byid," statements "); 
                                            strcpy($1._byname," statements "); 
                                            strcat($$._byname,$1._byname);
                                            strcat($$._byid, $1._byid); 
                                            strcat($$._byname,$2._byname);
                                            strcat($$._byid, $2._byid);
                                             // strcat($$._asm,$1._asm);
                                             strcat($$._asm,$2._asm);

                                          }
                        |
                        ;

stmt:                    compoundStmt  {
                                        strcpy($$._byid," stmt "); 
                                        strcpy($$._byname," stmt "); 
                                        strcat($$._byname,$1._byname);
                                        strcat($$._byid, $1._byid);   
                                     }
                        |singleStmt   {
                                        strcpy($$._byid," stmt "); 
                                        strcat($$._byid,to_string(scopeNo).c_str());
                                        strcpy($$._byname," stmt "); 
                                        strcat($$._byname,$1._byname);
                                        strcat($$._byid, $1._byid);  
                                        strcpy($$._asm,$1._asm);

                                     }
                        ;

compoundStmt:           TOKEN_LCB statements TOKEN_RCB {
                                                                      strcpy($$._byid," compoundStmt "); 
                                                                      strcpy($$._byname," compoundStmt "); 
                                                                      strcat($$._byname," TOKEN_LCB ");
                                                                      strcat($$._byid," { ");
                                                                      
                                                                      strcat($$._byid,to_string(scopeNo).c_str());
                                                                      strcat($$._byname,$2._byname);
                                                                      strcat($$._byid,$2._byid);                                                                           
                                                                      strcat($$._byid," } "); 
                                                                      strcat($$._byname," TOKEN_RCB "); 
                                                                      strcpy($$._asm,$2._asm);
                                                                      $$._scopeNo = scopeNo;
                                                                      scopeNo = prevscopeNo;
                                                                    }
                        ;



singleStmt:              conditionStmt                 {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);   
                                                            strcpy($$._asm,$1._asm);
                                                            prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;
                                                            conditionNo++;

                                                       }
                        |loopStmt                      {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid); 
                                                            strcpy($$._asm,$1._asm);
                                                            prevscopeNo = scopeNo; scopeNo = rand();scopeVars[scopeNo]=0;
                                                            loopNo++;  
                                                       }
                        |declaration                   {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid); 
                                                            strcpy($$._asm,$1._asm);
                                                            

                                                       }
                        |functionCall TOKEN_SEMICOLON  {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);                                                                           
                                                            strcat($$._byid," ; "); 
                                                            strcat($$._byname," TOKEN_SEMOCOLON ");  

                                                       }
                        |printFunc TOKEN_SEMICOLON     {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);                                                                           
                                                            strcat($$._byid," ; "); 
                                                            strcat($$._byname," TOKEN_SEMOCOLON ");  
                                                            strcpy($$._asm,$1._asm);

                                                       }
	                   |TOKEN_RETURN TOKEN_SEMICOLON {
                              strcpy($$._byid," singleStmt "); 
                              strcpy($$._byname," singleStmt "); 
                              strcat($$._byname," TOKEN_RETURN ");
                              strcat($$._byid," return ");                                                                           
                              strcat($$._byid," ; "); 
                              strcat($$._byname," TOKEN_SEMOCOLON ");
                            if(is_func)
                            {
                              if(func_type != 5)
                                yyerror("return type (VOID) does not match function type");
                            }
                            else yyerror("return statement not inside function definition");
                          
                        }
                         |TOKEN_CONTINUESTMT TOKEN_SEMICOLON {if(!is_loop)    { yyerror("Illegal use of continue");}
                                                                                strcpy($$._byid," singleStmt "); 
                                                                                strcpy($$._byname," singleStmt "); 
                                                                                strcat($$._byname," TOKEN_CONTINUESTMT ");
                                                                                strcat($$._byid," continue ");                                                                           
                                                                                strcat($$._byid," ; "); 
                                                                                strcat($$._byname," TOKEN_SEMOCOLON ");
                                                                              }
                         |TOKEN_BREAKSTMT TOKEN_SEMICOLON       {if(!is_loop) { yyerror("Illegal use of break");}
                                                                                strcpy($$._byid," singleStmt "); 
                                                                                strcpy($$._byname," singleStmt "); 
                                                                                strcat($$._byname," TOKEN_BREAKSTMT ");
                                                                                strcat($$._byid," break ");                                                                           
                                                                                strcat($$._byid," ; "); 
                                                                                strcat($$._byname," TOKEN_SEMOCOLON ");
                                                                }
                         |TOKEN_RETURN sub_expr TOKEN_SEMICOLON {                   
                                                                           strcpy($$._byid," singleStmt "); 
                                                                           strcpy($$._byname," singleStmt "); 
                                                                           strcat($$._byname,"TOKEN_RETURN");
                                                                           strcat($$._byid,"return");
                                                                           strcat($$._byid,$2._byid);
                                                                           strcat($$._byname,$2._byname);
                                                                           strcat($$._byid," ; "); 
                                                                           strcat($$._byname," TOKEN_SEMOCOLON ");


                                                                           if(is_func)
                                                                           {
                                                                                if(func_type != $2._datatype)
                                                                                     yyerror("return type does not match function type");
                                                                           }
                                                                           else yyerror("return statement not in function definition");
                                                                           if($2._isVar == 2) {
                                                                                string tmp = "\n\tlw     $t0,"+to_string($2._stackPlace*4) + "($fp)";
                                                                                strcpy($$._asm,tmp.c_str());
                                                                           } else {
                                                                                strcpy($$._asm,$2._asm);

                                                                           }
                                                                           strcat($$._asm,"\n\tmove $t0,$v0");

                                                                           
                        }
                        ;         


printFunc:                TOKEN_PRFUNC TOKEN_LEFTPAREN sub_expr TOKEN_RIGHTPAREN  {

                                                                                     string tmp = "\n\tlw     $a0,"+to_string($3._stackPlace*4) + "($fp)";
                                                                                     
                                                                                     strcpy($$._asm,$3._asm);
                                                                                     strcpy($$._asm,tmp.c_str());
                                                                                     strcat($$._asm,"\n\tli   $v0,1");
                                                                                     strcat($$._asm,"\n\tsyscall");
                                                                                     strcpy($$._byid," printFunc "); 
                                                                                     strcpy($$._byname," printFunc "); 
                                                                                     strcat($$._byid,$1._byid);
                                                                                     strcat($$._byname,$1._byname);
                                                                                     strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat($$._byid," ( ");
                                                                                     strcat($$._byname,$3._byname); 
                                                                                     strcat($$._byid,$3._byid);
                                                                                     strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat($$._byid," ) ");                                                           
                                                                                    }
                         ;




conditionStmt:           TOKEN_IFCONDITION  TOKEN_LEFTPAREN  expression   TOKEN_RIGHTPAREN compoundStmt                                      {
                                                                                                                                                  strcpy($$._byid," conditionStmt "); 
                                                                                                                                                 strcpy($$._byname," conditionStmt "); 
                                                                                                                                                 strcat($$._byid," if "); 
                                                                                                                                                 strcat($$._byname," TOKEN_IFCONDITION ");
                                                                                                                                                 strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                 strcat($$._byid," ( ");
                                                                                                                                                 strcat($$._byid,$3._byid);
                                                                                                                                                 strcat($$._byname,$3._byname);
                                                                                                                                                 strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                 strcat($$._byid," ) ");
                                                                                                                                                 strcat($$._byid,$5._byid);
                                                                                                                                                 strcat($$._byname,$5._byname);
                                                                                                                                                 
                                                                                                                                                 string s;
                                                                                                                                                 s = "\nC" + to_string(conditionNo) + ":";
                                                                                                                                                 strcpy($$._asm,$3._asm);
                                                                                                                                                 strcat($$._asm,$5._asm);
                                                                                                                                                 strcat($$._asm,s.c_str());
                                                                                                                                             }
                        |TOKEN_IFCONDITION  TOKEN_LEFTPAREN  expression    TOKEN_RIGHTPAREN compoundStmt  TOKEN_ELSECONDITION compoundStmt   {
                                                                                                                                                 strcpy($$._byid," conditionStmt "); 
                                                                                                                                                 strcpy($$._byname," conditionStmt "); 
                                                                                                                                                 strcat($$._byid," if "); 
                                                                                                                                                 strcat($$._byname," TOKEN_IFCONDITION ");
                                                                                                                                                 strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                 strcat($$._byid," ( ");
                                                                                                                                                 strcat($$._byid,$3._byid);
                                                                                                                                                 strcat($$._byname,$3._byname);
                                                                                                                                                 strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                 strcat($$._byid," ) ");
                                                                                                                                                 strcat($$._byid,$5._byid);
                                                                                                                                                 strcat($$._byname,$5._byname);
                                                                                                                                                 strcat($$._byname," TOKEN_ELSECONDITION "); 
                                                                                                                                                 strcat($$._byid," else ");
                                                                                                                                                 strcat($$._byid,$7._byid);
                                                                                                                                                 strcat($$._byname,$7._byname);
                                                                                                                                                 
                                                                                                                                                 string s;
                                                                                                                                                 strcpy($$._asm,$3._asm);
                                                                                                                                                 strcat($$._asm,$5._asm);
                                                                                                                                                 s = "\n\tb     C"+to_string(++conditionNo);
                                                                                                                                                 strcat($$._asm,s.c_str());
                                                                                                                                                 strcat($$._asm,"\n\tnop");
                                                                                                                                                 s = "\nC"+to_string(conditionNo-1);
                                                                                                                                                 strcat($$._asm,s.c_str());
                                                                                                                                                 strcat($$._asm,$7._asm);
                                                                                                                                                 s = "\nC" + to_string(conditionNo) + ":";
                                                                                                                                                 strcat($$._asm,s.c_str());
                                                                                                                                            

                                                                                                                                             }
                        ;


loopStmt:                TOKEN_LOOP   identifier   TOKEN_LEFTPAREN expression TOKEN_UNTIL expression TOKEN_RIGHTPAREN  {is_loop = 1;}  compoundStmt {is_loop = 0;
                                                                                                                                                      strcpy($$._byid," loopStmt "); 
                                                                                                                                                      strcpy($$._byname," loopStmt "); 
                                                                                                                                                      strcat($$._byid," foreach "); 
                                                                                                                                                      strcat($$._byname," TOKEN_LOOP ");
                                                                                                                                                      strcat($$._byid,$2._byid);
                                                                                                                                                      strcat($$._byname,$2._byname);
                                                                                                                                                      strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                                                                                      strcat($$._byid," ( ");
                                                                                                                                                      strcat($$._byid,$4._byid);
                                                                                                                                                      strcat($$._byname,$4._byname);
                                                                                                                                                      strcat($$._byname," TOKEN_UNTIL "); 
                                                                                                                                                      strcat($$._byid," .. ");
                                                                                                                                                      strcat($$._byid,$6._byid);
                                                                                                                                                      strcat($$._byname,$6._byname);
                                                                                                                                                      strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                                                                                      strcat($$._byid," ) ");
                                                                                                                                                      strcat($$._byid,$9._byid);
                                                                                                                                                      strcat($$._byname,$9._byname);

                                                                                                                                                      string s;
                                                                                                                                                      s = "\nL" + to_string(++loopNo) + ":";
                                                                                                                                                      strcpy($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tli    $s0," + to_string($4._numVal);
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tli    $s1," + to_string($6._numVal);
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tbgt   $s0,$s1,L" + to_string(loopNo-1);
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tnop";
                                                                                                                                                      strcat($$._asm,s.c_str());

                                                                                                                                                      s = "\n\tsw    $s0," + to_string($2._stackPlace*4) + "($fp)";
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      strcat($$._asm,$9._asm);
                                                                                                                                                      
                                                                                                                                                      s = "\n\taddiu $s0,$s0,1";
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tsw    $s0," + to_string($2._stackPlace*4) + "($fp)";
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tb     L" + to_string(loopNo);
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\n\tnop";
                                                                                                                                                      strcat($$._asm,s.c_str());
                                                                                                                                                      s = "\nL" + to_string(loopNo-1);
                                                                                                                                                      strcat($$._asm,s.c_str());


                                                                                                                                                    }
                        ;


     functionCall:            identifier TOKEN_LEFTPAREN parameter_list TOKEN_RIGHTPAREN {$$._datatype = $1._datatype;
                                                                                               strcpy($$._byid," functionCall "); 
                                                                                               strcpy($$._byname," functionCall "); 
                                                                                               strcat($$._byid,$1._byid);
                                                                                               strcat($$._byname,$1._byname);
                                                                                               strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                               strcat($$._byid," ( ");
                                                                                               strcat($$._byname,$3._byname); 
                                                                                               strcat($$._byid,$3._byid);
                                                                                               strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                               strcat($$._byid," ) ");
                                                                                               string s ($1._val);
                                                                                     
                                                                                               if(umap[s].cnt!=$3._cnt)
                                                                                                     yyerror("function arguments count mismatch");
                                                                                               
                                                                                               // cout << "debug-p->" << $3._asm << endl;
                                                                                               strcpy($$._asm,$3._asm);
                                                                                               s = "\n\tjal " + string($1._val);
                                                                                               strcat($$._asm,s.c_str());

                                                                                          }
                        |identifier TOKEN_LEFTPAREN TOKEN_RIGHTPAREN                {$$._datatype = $1._datatype;
                                                                                     string s ($1._val);
                                                                                     if(umap[s].cnt != 0)
                                                                                          yyerror("function arguments missing");
                        
                                                                                     strcpy($$._byid," functionCall "); 
                                                                                     strcpy($$._byname," functionCall "); 
                                                                                     strcat($$._byid,$1._byid);
                                                                                     strcat($$._byname,$1._byname);
                                                                                     strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat($$._byid," ( ");
                                                                                     strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat($$._byid," ) ");

                                                                                     s = "\n\tjal " + string($1._val);
                                                                                     strcpy($$._asm,s.c_str());
                                                                                     
                                                                                     }
                        ;

parameter_list:          parameter_list TOKEN_COMMA  parameter          {
                                                                           strcpy($$._byid," parameter_list "); 
                                                                           strcpy($$._byname," parameter_list "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcat($$._byname," TOKEN_COMMA "); 
                                                                           strcat($$._byid," , ");
                                                                           strcat($$._byname,$3._byname); 
                                                                           strcat($$._byid,$3._byid);
                                                                           $$._cnt++;
                                                                           cout<<"::::"<<$$._cnt<<"::::";

                                                                           strcpy($$._asm,$1._asm);
                                                                           // strcat($$._asm,$3._asm);
                                                                           string s;
                                                                           if($3._isVar == 1) {
                                                                                s = "\n\tli  $t0," + to_string($3._numVal);
                                                                                strcat($$._asm,s.c_str());
                                                                                
                                                                           } else if($3._isVar == 2) {
                                                                                 s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                                strcat($$._asm,s.c_str());
                                                                                
                                                                           } else {
                                                                                strcpy($$._asm,$3._asm);
                                                                           }
                                                                           s = "\n\tmove $t0,a" + to_string($$._cnt);
                                                                                strcat($$._asm,s.c_str());
                                                                           // if($3._isVar == 1) {
                                                                           //      string s = "\n\tli  $4," + to_string($3._numVal);
                                                                           //      strcpy($$._asm,s.c_str());
                                                                           // } else {
                                                                           //      strcpy($$._asm,$3._asm);
                                                                           // }
                                                                        }
                        |parameter                                      {  strcpy($$._byid,$1._byid);
                                                                           strcpy($$._byname,$1._byname);
                                                                           $$._cnt=1;
                                                                           string s;
                                                                           if($1._isVar == 1) {
                                                                                 s = "\n\tli  $t0," + to_string($1._numVal);
                                                                                strcat($$._asm,s.c_str());
                                                                                
                                                                           } else if($1._isVar == 2) {
                                                                                 s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                                strcat($$._asm,s.c_str());
                                                                           } else {
                                                                                strcpy($$._asm,$1._asm);
                                                                           }
                                                                           s = "\n\tmove $t0,a" + to_string($$._cnt);
                                                                           strcat($$._asm,s.c_str());
                                                                                // strcpy($$._asm,$1._asm);
                                                                        }
                        ;

parameter:               sub_expr                                       {
                                                                           strcpy($$._byid," parameter "); 
                                                                           strcpy($$._byname," parameter "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcpy($$._asm,$1._asm);
                                                                        }           
					              // |constants
                        ;

declaration:             typeSpecifier declaration_list TOKEN_SEMICOLON {  is_declaration = 0;
                                                                           strcpy($$._byid," declaration "); 
                                                                           strcpy($$._byname," declaration "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcat($$._byname,$2._byname); 
                                                                           strcat($$._byid,$2._byid);
                                                                           strcat($$._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat($$._byid," ; ");
                                                                 strcpy($$._asm,$2._asm);



                                                                        }
			          |declaration_list TOKEN_SEMICOLON              {
                                                                           is_declaration = 0;
                                                                           strcpy($$._byid," declaration "); 
                                                                           strcpy($$._byname," declaration "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcat($$._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat($$._byid," ; ");
                                                                 strcpy($$._asm,$1._asm);


                                                                        }
                        ;

declaration_list:        declaration_list TOKEN_COMMA sub_decl          {  $3._datatype=$$._datatype;
                                                                           strcpy($$._byid," declaration_list "); 
                                                                           strcpy($$._byname," declaration_list "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcat($$._byname," TOKEN_COMMA "); 
                                                                           strcat($$._byid," , ");
                                                                           strcat($$._byname,$3._byname); 
                                                                           strcat($$._byid,$3._byid);
                                                                        }
		               |sub_decl                                      {  $1._datatype=$$._datatype;
                                                                           strcpy($$._byid," declaration_list "); 
                                                                           strcpy($$._byname," declaration_list "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcpy($$._asm,$1._asm);


                                                                        }
                        ;

sub_decl:                assignment_expr                    {
                                                                 strcpy($$._byid," sub_decl "); 
                                                                 strcpy($$._byname," sub_decl "); 
                                                                 strcat($$._byid,$1._byid);
                                                                 strcat($$._byname,$1._byname);
                                                                 strcpy($$._asm,$1._asm);
                                                            }
                        |identifier                         {
                                                                 strcpy($$._byid," sub_decl "); 
                                                                 strcpy($$._byname," sub_decl "); 
                                                                 strcat($$._byid,$1._byid);
                                                                 strcat($$._byname,$1._byname);
                                                            }          
                        |array_access                       {
                                                                 is_declaration = 1;
                                                                 
                                                                 strcpy($$._byid," sub_decl "); 
                                                                 strcpy($$._byname," sub_decl "); 
                                                                 strcat($$._byid,$1._byid);
                                                                 strcat($$._byname,$1._byname);

                                                            }
                        ;

               

expression:              expression TOKEN_COMMA sub_expr	{
                                                                 strcpy($$._byid," expression "); 
                                                                 strcpy($$._byname," expression "); 
                                                                 strcat($$._byid,$1._byid);
                                                                 strcat($$._byname,$1._byname);
                                                                 strcat($$._byname," TOKEN_COMMA "); 
                                                                 strcat($$._byid," , ");
                                                                 strcat($$._byname,$3._byname); 
                                                                 strcat($$._byid,$3._byid);

                                                            }							
                        |sub_expr	                         {strcpy($$._byid," expression ");
                                                             strcpy($$._byname," sub_expr ");
                                                             strcat($$._byid,$1._byid);
                                                             strcat($$._byname,$1._byname);
                                                             strcpy($$._asm,$1._asm);

                                                             $$._numVal=$1._numVal;
                                                            }	                                    
		                    ;

sub_expr:                sub_expr TOKEN_GR sub_expr			   {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_GR "); 
                                                                      strcat($$._byid," > ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tble  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                      


                                                                    }
                        |sub_expr TOKEN_LS sub_expr			   {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_LS "); 
                                                                      strcat($$._byid," < ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tbge  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                      
                                                                    }
                        |sub_expr TOKEN_EQ sub_expr			   {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_EQ "); 
                                                                      strcat($$._byid," = ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tbne  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                    }
                        |sub_expr TOKEN_NOTEQ sub_expr              {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_NOTEQ "); 
                                                                      strcat($$._byid," != ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tbeq  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                    }
                        |sub_expr TOKEN_LSEQ sub_expr               {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_LSEQ "); 
                                                                      strcat($$._byid," <= ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tbgt  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                    }
                        |sub_expr TOKEN_GREQ sub_expr               {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_GREQ "); 
                                                                      strcat($$._byid," >= ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);

                                                                      if($1._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                           strcpy($$._asm,s.c_str());     
                                                                      } else if($1._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($1._numVal);
                                                                           strcpy($$._asm,s.c_str());
                                                                      } else {
                                                                           strcpy($$._asm,$1._asm);
                                                                      }
                                                                      strcat($$._asm,"\n\tmove  $t0,$t6");

                                                                      if($3._isVar == 2) {
                                                                           string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                           strcat($$._asm,s.c_str());     
                                                                      } else if($3._isVar == 1) {
                                                                           string s = "\n\tli  $t0," + to_string($3._numVal);
                                                                           strcat($$._asm,s.c_str());
                                                                      } else {
                                                                           strcat($$._asm,$3._asm);
                                                                      }
                                                                      
                                                                      strcat($$._asm,"\n\tmove  $t0,$t7");
                                                                      // strcat($$._asm,"\n\tslt  $t6,$t6,$t7");
                                                                      strcat($$._asm,"\n\tblt  $t6,$7,C");
                                                                      strcat($$._asm,to_string(conditionNo).c_str());
                                                                      strcat($$._asm,"\n\tnop");
                                                                    }
                        |sub_expr TOKEN_LOGICAND sub_expr           {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname,"TOKEN_LOGICAND"); 
                                                                      strcat($$._byid," && ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);
                                                                    }
                        |sub_expr TOKEN_LOGICOR sub_expr            {type_check($1._datatype,$3._datatype,2); $$._datatype = $1._datatype;
                                                                      strcpy($$._byid," sub_expr "); 
                                                                      strcpy($$._byname," sub_expr "); 
                                                                      strcat($$._byid,$1._byid);
                                                                      strcat($$._byname,$1._byname);
                                                                      strcat($$._byname," TOKEN_LOGICOR "); 
                                                                      strcat($$._byid," || ");
                                                                      strcat($$._byname,$3._byname); 
                                                                      strcat($$._byid,$3._byid);
                                                                    }
                        |TOKEN_LOGICNOT sub_expr                    {$$._datatype = $2._datatype;
                                                                     strcpy($$._byid," sub_expr ");
                                                                     strcpy($$._byid," TOKEN_LOGICNOT ");
                                                                     strcat($$._byid,$2._byid);
                                                                     strcat($$._byname," sub_expr ");
                                                                     strcat($$._byname," ! ");
                                                                     strcat($$._byname,$2._byname);
                                                                    }
                        |arithmetic_expr				        {$$._datatype = $1._datatype;
                                                                     strcpy($$._byname," sub_expr ");
                                                                     strcpy($$._byid," sub_expr ");
                                                                     strcat($$._byid,$1._byid);
                                                                     strcat($$._byname,$1._byname);

                                                                     $$._numVal=$1._numVal;
                        
                                                                    }
                        |assignment_expr                            {$$._datatype = $1._datatype;
                                                                     strcpy($$._byname," sub_expr ");
                                                                     strcpy($$._byid," sub_expr ");
                                                                     strcat($$._byid,$1._byid);
                                                                     strcat($$._byname,$1._byname);
                                                                     strcpy($$._asm,$1._asm);
                                                                    }
                         
                        ;

assgn :                  TOKEN_ASSIGNOP {rhs=1;};

assignment_expr :        lhs assgn  arithmetic_expr         { type_check($1._datatype,$3._datatype,1); $$._datatype = $3._datatype;rhs=0;
                                                                                                 strcpy($$._byname," assignment_expr ");
                                                                                                 strcpy($$._byid," assignment_expr "); 
                                                                                                 strcat($$._byname,$1._byname); 
                                                                                                 strcat($$._byid,$1._byid);
                                                                                                 strcat($$._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat($$._byid,"=");
                                                                                                 strcat($$._byname,$3._byname); 
                                                                                                 strcat($$._byid,$3._byid);

                                                                                                 $1._numVal = (int)($3._numVal);

                                                                                                 cout<<"***"<<$1._numVal<<"**";

                                                                                               char tmp2[200];
                                                                                               char tmp[200];
                                                                                               
                                                                                                    if($3._isSingle) {
                                                                                                    if($3._isVar == 1) {
                                                                                                         sprintf(tmp,"\n\tli      $t0,%d",$3._numVal);
                                                                                                         strcpy($$._asm,tmp);
                                                                                                         char tmp2[200];
                                                                                                         sprintf(tmp2,"\n\tsw      $t0,%d($fp)",($1._stackPlace)*4);
                                                                                                         strcat($$._asm,tmp2);
                                                                                                    }
                                                                                                    if($3._isVar == 2) {
                                                                                                          string s = "\n\tlw  $t0," + to_string($3._stackPlace*4) + "($fp)";
                                                                                                          strcpy($$._asm,s.c_str());
                                                                                                          s = "\n\tsw   $t0," + to_string($1._stackPlace*4) + "($fp)";
                                                                                                          strcat($$._asm,s.c_str());
                                                                                                    }
                                                                                                    } else {
                                                                                                         strcpy($$._asm,$3._asm);
                                                                                                         sprintf(tmp2,"\n\tsw     $t0,%d($fp)",($1._stackPlace)*4);
                                                                                                         strcat($$._asm,tmp2);
                                                                                                         clacStart = 0;
                                                                                                    }
                                                                                               
                                                                                               
                                                                                               
                                                                                               // char tmp[200];
                                                                                               // sprintf(tmp,"\n\tli      $2,%d",$1._numVal);
                                                                                               // strcpy($$._asm,tmp);
                                                                                               // char tmp2[200];
                                                                                               // sprintf(tmp2,"\n\tsw      $2,%d($fp)",($1._stackPlace-1)*4);
                                                                                               // strcat($$._asm,tmp2);
                                                                                               }
                        
                        |lhs assgn  functionCall            { type_check($1._datatype,$3._datatype,1); $$._datatype = $3._datatype;rhs=0;
                                                                                                 strcpy($$._byname," assignment_expr ");
                                                                                                 strcpy($$._byid," assignment_expr "); 
                                                                                                 strcat($$._byname,$1._byname); 
                                                                                                 strcat($$._byid,$1._byid);
                                                                                                 strcat($$._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat($$._byid,"=");
                                                                                                 strcat($$._byname,$3._byname); 
                                                                                                 strcat($$._byid,$3._byid);

                                                                                                 strcpy($$._asm,$3._asm);
                                                                                                 string s = "\n\tsw   $v0," + to_string($1._stackPlace*4) + "($fp)";
                                                                                                 strcat($$._asm,s.c_str());

                                                                                               }
                        |lhs assgn array_init     {
                              type_check($1._datatype,$3._datatype,1);
                              yyerror("cant be initialized");
                                                       
                                                  }
                        ;



lhs:                     identifier                {$$._datatype = $1._datatype;strcpy($$._byid,$1._byid);strcat($$._byid,$1._byname);$$._stackPlace=$1._stackPlace;}
                        |array_access              {$$._datatype = $1._datatype;strcpy($$._byid,$1._byid);strcat($$._byid,$1._byname);$$._stackPlace=$1._stackPlace;$$._arrParam = $1._arrParam;$$._arrVar=$1._arrVar;}
                        ;

identifier:             TOKEN_ID                  {   
                                                       strcpy($$._byname," identifier ");
                                                       strcpy($$._byid," identifier "); 
                                                       strcat($$._byname," TOKEN_ID "); 
                                                       strcat($$._byid,$1._val);
                                                       string s ($1._val);
                                                       struct perScope temp;
                                                            if(is_declaration && !rhs)
                                                            {
                                                                 
                                                                 if ((umap.find(s) == umap.end())||((umap.find(s) != umap.end())&&(umap[s].scope!=scopeNo))) {
                                                                      if(is_func==1)
                                                                           scopeVars[scopeNo]=scopeVars[scopeNo]+1;
                                                                      temp.type=current_dtype;
                                                                      temp.scope=scopeNo;
                                                                      // temp.cnt=0;
                                                                      temp.stackPlace=scopeVars[scopeNo]-1;
                                                                      umap[s]= temp;
                                                                      $$._datatype = umap[s].type;}
                                                                 else if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                      $$._datatype = umap[s].type;
                                                                      yyerror("Redeclaration of variable");}
                                                                 

                                                                      
                                                            }
                                                            else
                                                            {
                                                                 $$._datatype = umap[s].type;
                                                                 if($$._datatype == 0) 
                                                                      yyerror("Variable not declared");
                                                            }
                                                            $$._val = $1._val;
                                                            $$._stackPlace=umap[s].stackPlace;
                                                            

                                                  }
                                                  ;
arithmetic_expr:         arithmetic_expr TOKEN_PLUS arithmetic_expr        {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_PLUS "); 
                                                                                strcat($$._byid," + ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                                
                                                                                
                                                                                $$._numVal = (int)($1._numVal+$3._numVal);
                                                                                // cout<<"^^"<<$$._numVal<<"="<<$1._numVal<<"^^"<<$3._numVal<<"^^";


                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==1 && $3._datatype==3) || ($1._datatype==3 && $3._datatype==1))
                                                                                     $$._datatype = 0;
                                                                                else if(($1._datatype==4 && $3._datatype==4))
                                                                                     $$._datatype = 4;
                                                                                else if(($1._datatype==6 && $3._datatype==6))
                                                                                     $$._datatype = 6;
                                                                                else if(($1._datatype==2 && $3._datatype==2))
                                                                                     $$._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                                
                                                                                $$._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                          strcat($$._asm,"\n\tli    $t0,0");
                                                                                     }
                                                                                     if($1._isVar == 2) {

                                                                                          cout << "lw $2," << $1._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string($1._stackPlace * 4) + "($fp)";
                                                                                          strcat($$._asm,s.c_str());
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t2," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw   $t2," + to_string($3._stackPlace * 4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               cout << "addu    $t0,$t2,$t1" << endl;
                                                                                               s = "\n\taddu    $t0,$t2,$t1";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $4,$2," << $3._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1," + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 1) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace * 4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "addiu   $t0,$t1," << $1._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1," + to_string($1._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               $$._isVar = 3;
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $t0,$0," << $$._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$0," + to_string($$._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               $$._isVar = 1;
                                                                                          }
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 3) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace*4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "addu    $t0,$t1,$t0" << endl;
                                                                                               s = "\n\taddu    $t0,$t1,$t0";
                                                                                               strcat($$._asm,s.c_str());

                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t0," << $3._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t0," + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 3) {
                                                                                               cout << "addu   $t0,$t0,$t3" << endl;
                                                                                               s = "\n\taddu   $t0,$t0,$t3";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                     }
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                

                                                                            

                                                                           }
                        |arithmetic_expr TOKEN_MINUS arithmetic_expr       {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_MINUS "); 
                                                                                strcat($$._byid," - ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);

                                                                                $$._numVal = (int)($1._numVal-$3._numVal);

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==1 && $3._datatype==3) || ($1._datatype==3 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==6 && $3._datatype==6))
                                                                                     $$._datatype = 6;
                                                                                else if(($1._datatype==2 && $3._datatype==2))
                                                                                     $$._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");

                                                                                $$._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                          strcat($$._asm,"\n\tli    $t0,0");
                                                                                     }
                                                                                     if($1._isVar == 2) {

                                                                                          cout << "lw $2," << $1._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string($1._stackPlace * 4) + "($fp)";
                                                                                          strcat($$._asm,s.c_str());
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t2," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw   $t2," + to_string($3._stackPlace * 4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               cout << "subu    $t0,$t2,$t1" << endl;
                                                                                               s = "\n\tsubu    $t0,$t2,$t1";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t1,-" << $3._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1,-" + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 1) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace * 4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "addiu   $t0,$t1,-" << $1._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t1,-" + to_string($1._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               $$._isVar = 3;
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $t0,$zero," << $$._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$zero," + to_string($$._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               $$._isVar = 1;
                                                                                          }
                                                                                          
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 3) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace*4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "subu    $t0,$t1,$t0" << endl;
                                                                                               s = "\n\tsubu    $t0,$t1,$t0";
                                                                                               strcat($$._asm,s.c_str());

                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "addiu   $t0,$t0,-" << $3._numVal << endl;
                                                                                               s = "\n\taddiu   $t0,$t0,-" + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 3) {
                                                                                               cout << "subu   $t0,$t0,$t3" << endl;
                                                                                               s = "\n\tsubu   $t0,$t0,$t3";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                     }

                                                                           }
                        |arithmetic_expr TOKEN_MUL arithmetic_expr         {    
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_MUL "); 
                                                                                strcat($$._byid," * ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);

                                                                                $$._numVal = (int)($1._numVal*$3._numVal);

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==1 && $3._datatype==3) || ($1._datatype==3 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==6 && $3._datatype==6))
                                                                                     $$._datatype = 6;
                                                                                else if(($1._datatype==2 && $3._datatype==2))
                                                                                     $$._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");

                                                                                $$._isSingle = 0;
                                                                                string s;
                                                                                if(!clacStart) 
                                                                                     {cout << "li    $t0,0" << endl;clacStart = 1;
                                                                                     s = "\n\tli    $t0,0";
                                                                                               strcat($$._asm,s.c_str());
                                                                                     }
                                                                                     if($1._isVar == 2) {
                                                                                          cout << "lw $t1," << $1._stackPlace << "($fp)" << endl;
                                                                                          s = "\n\tlw    $t1," + to_string($1._stackPlace*4) + "($fp)";
                                                                                          strcat($$._asm,s.c_str());
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t2," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t2," + to_string($3._stackPlace*4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               cout << "mul    $t3,$t2,$t1" << endl;
                                                                                               s = "\n\tmul    $t3,$t2,$t1";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "li   $t4," << $3._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               cout << "mul   $t3,$t1,$t4" << endl;
                                                                                               s = "\n\tmul   $t3,$t1,$t4";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 1) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace*4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "li   $t4," << $1._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string($1._numVal);
                                                                                               strcat($$._asm,s.c_str());

                                                                                               cout << "mul   $t3,$t1,$t4" << endl;
                                                                                               s = "\n\tmul   $t3,$t1,$t4";
                                                                                               strcat($$._asm,s.c_str());
                                                                                               $$._isVar = 3;
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               // cout << "li   $6," << $$._numVal << endl;
                                                                                               // cout << "li   $7,1" << endl;
                                                                                               // cout << "mul   $5,$7,$6" << endl;
                                                                                               $$._isVar = 1;
                                                                                          }
                                                                                          
                                                                                     }
                                                                                     if($1._isVar == 3) {
                                                                                          if($3._isVar == 2) {
                                                                                               cout << "lw $t1," << $3._stackPlace << "($fp)" << endl;
                                                                                               s = "\n\tlw    $t1," + to_string($3._stackPlace*4) + "($fp)";
                                                                                               strcat($$._asm,s.c_str());

                                                                                               cout << "mul    $t0,$t1,$0" << endl;
                                                                                               s = "\n\tmul    $t0,$t1,$t0";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          if($3._isVar == 1) {
                                                                                               cout << "li   $t4," << $3._numVal << endl;
                                                                                               s = "\n\tli   $t4," + to_string($3._numVal);
                                                                                               strcat($$._asm,s.c_str());
                                                                                               
                                                                                               cout << "mul   $t0,$t0,$t4" << endl;
                                                                                               s = "\n\tmul   $t0,$t0,$t4";
                                                                                               strcat($$._asm,s.c_str());
                                                                                          }
                                                                                          $$._isVar = 3;
                                                                                     }

                                                                           }
                        |arithmetic_expr TOKEN_DIV arithmetic_expr         {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_DIV "); 
                                                                                strcat($$._byid," / ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                                $$._numVal = (int)($1._numVal/$3._numVal);

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==1 && $3._datatype==3) || ($1._datatype==3 && $3._datatype==1))
                                                                                     $$._datatype = 1;
                                                                                else if(($1._datatype==6 && $3._datatype==6))
                                                                                     $$._datatype = 6;
                                                                                else if(($1._datatype==2 && $3._datatype==2))
                                                                                     $$._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
                         |arithmetic_expr TOKEN_POW arithmetic_expr         {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_POW "); 
                                                                                strcat($$._byid," ^ ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                               $$._numVal=(int)(pow(double($1._numVal),double($3._numVal)));

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
     
                                                                                else if(($1._datatype==2 && $3._datatype==2))
                                                                                     $$._datatype = 2;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
                         |arithmetic_expr TOKEN_BITWISEAND arithmetic_expr         {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_BITWISEAND "); 
                                                                                strcat($$._byid," & ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                               

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
     
                                                                                else if(($1._datatype==3 && $3._datatype==3))
                                                                                     $$._datatype = 3;
                                                                                else if(($1._datatype==4 && $3._datatype==4))
                                                                                     $$._datatype = 4;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
                         |arithmetic_expr TOKEN_BITWISEOR arithmetic_expr         {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_BITWISEOR "); 
                                                                                strcat($$._byid," | ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                               

                                                                                if(($1._datatype==1 && $3._datatype==1))
                                                                                     $$._datatype = 1;
     
                                                                                else if(($1._datatype==3 && $3._datatype==3))
                                                                                     $$._datatype = 3;
                                                                                else if(($1._datatype==4 && $3._datatype==4))
                                                                                     $$._datatype = 4;
                                                                                else 
                                                                                     yyerror("Type mismatch in arithmetic expression");
                                                                            }
                        |TOKEN_LEFTPAREN arithmetic_expr TOKEN_RIGHTPAREN   {$$._numVal=$2._numVal;$$._datatype = $2._datatype; strcpy($$._byid," TOKEN_LEFTPAREN");strcat($$._byname,"(");strcat($$._byid,$2._byid); strcat($$._byname,$2._byname);strcat($$._byid," ) ");strcat($$._byname," TOKEN_RIGHTPAREN ");}
                        |TOKEN_MINUS arithmetic_expr %prec UMINUS           {$$._numVal=(-1)*$2._numVal;$$._datatype = $2._datatype; strcpy($$._byid,"  - ");strcat($$._byname," TOKEN_MINUS ");strcat($$._byid,$2._byid); strcat($$._byname,$2._byname);}
                        |identifier                                         {$$._datatype = $1._datatype; strcpy($$._byid,$1._byid); strcpy($$._byname,$1._byname); $$._typ=2; $$._val=$1._val; $$._isVar=2;$$._stackPlace=$1._stackPlace;$$._isSingle = 1;$$._arrVar=0;}
                        |constants                                          {$$._numVal=$1._numVal;$$._datatype = $1._datatype; strcpy($$._byid,$1._byid); strcpy($$._byname,$1._byname); $$._typ=1; $$._val=$1._val;$$._isVar=1;$$._isSingle = 1;$$._arrVar=0;}
                        |array_access                                       {$$._datatype = $1._datatype; strcpy($$._byid,$1._byid); strcpy($$._byname,$1._byname); $$._typ=2; $$._val=$1._val; $$._isVar=2;$$._stackPlace=$1._stackPlace;$$._isSingle = 1;}
                        ;

array_init_vars:         array_init_vars TOKEN_COMMA constants 
                         |constants
                         ;

array_init:              TOKEN_LCB array_init_vars TOKEN_RCB { $$._datatype = 7;}
                         
                         ;

array_access:            identifier TOKEN_LB constants TOKEN_RB { 
                                                                 if($3._datatype != 1) {yyerror("array count should be integer");}
                                                                 string s ($1._val);
                                                                 if(is_declaration){
                                                                      if ((umap.find(s) == umap.end())||((umap.find(s) != umap.end())&&(umap[s].scope!=scopeNo))) {
                                                                      }
                                                                      else  if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                           umap[s].cnt = atoi($3._val);
                                                                           umap[s].stackPlace = scopeVars[scopeNo]-1;
                                                                           scopeVars[scopeNo] = scopeVars[scopeNo] + atoi($3._val) - 1;
                                                                      }
                                                                      
                                                                 } else {
                                                                      if ((umap.find(s) != umap.end())&&(umap[s].scope==scopeNo)){
                                                                           
                                                                           if(umap[s].cnt <= atoi($3._val) || atoi($3._val) < 0) {
                                                                           char errs[400];
                                                                           sprintf(errs,"cannot access element %d of array of size %d",atoi($3._val),umap[s].cnt);
                                                                           yyerror(errs);
                                                                           }
                                                                      }
                                                                 }
                                                                 
                                                                 $$._datatype = $1._datatype; 
                                                                  strcpy($$._byname," array_access ");
                                                                  strcpy($$._byid," array_access "); 
                                                                  strcat($$._byname,$1._byname); 
                                                                  strcat($$._byid,$1._byid); 
                                                                  strcat($$._byname," TOKEN_LB "); 
                                                                  strcat($$._byid," [ ");
                                                                  strcat($$._byname,$3._byname); 
                                                                  strcat($$._byid,$3._byid);
                                                                  strcat($$._byname," TOKEN_RB "); 
                                                                  strcat($$._byid," ] ");

                                                                  $$._stackPlace = umap[s].stackPlace + atoi($3._val);
                                                                  $$._arrParam = -1;

                                                                }
                         
                                                        
                        ;



typeSpecifier:       TOKEN_INTTYPE              { is_declaration = 1;current_dtype=1; $$._datatype=1; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_INTTYPE "); strcat($$._byid,$1._val);   }
                    |TOKEN_FLOATTYPE            { is_declaration = 1; current_dtype=2; $$._datatype=2; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_FLOATTYPE "); strcat($$._byid,$1._val); }
                    |TOKEN_DOUBLETYPE           { is_declaration = 1; current_dtype=6; $$._datatype=6; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_DOUBLETYPE "); strcat($$._byid,$1._val);}
                    |TOKEN_CHARTYPE             { is_declaration = 1; current_dtype=3; $$._datatype=3; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_CHARTYPE "); strcat($$._byid,$1._val);  }
                    |TOKEN_STRINGTYPE           { is_declaration = 1; current_dtype=4; $$._datatype=4; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_STRINGTYPE "); strcat($$._byid,$1._val);}
                    |TOKEN_VOIDTYPE             { is_declaration = 1; current_dtype=5; $$._datatype=5; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_VOIDTYPE "); strcat($$._byid,$1._val);  }
                    ;

constants:           TOKEN_INTCONST             {$$._datatype = 1; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_INTCONST "); strcat($$._byid,$1._val);  $$._typ=1; $$._val=$1._val; $$._numVal=atoi($1._val);}
                    |TOKEN_CHARCONST            {/*$$._datatype = 3; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_CHARCONST "); strcat($$._byid,$1._val);  */} 
                    |TOKEN_FLOATCONST           {/*$$._datatype = 2; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_FLOATCONST "); strcat($$._byid,$1._val); */}
                    |TOKEN_STRINGCONST          {/*$$._datatype = 4; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_STRINGCONST "); strcat($$._byid,$1._val);*/}
                    ;   



%%
/*==============================================================error handling===============================================================*/
void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

void yyerror(const char *s) {
  extern int yylineno;
  extern int columnNo;
  MyFile<<"[-] ERROR : LINE "<<yylineno<<" COLUMN "<<columnNo<<" : "<<s<<"\n";
}


/*==============================================================main function===============================================================*/

int main(int argc , char* argv[]) {
     srand(time(0)); 
     out = atoi(argv[1]);
     yyparse();

     MyFile.close();
     cout << "\n\n\n[#] ERRORS :\n\n\n";
     std::ifstream file("output.out");
     std::string str;
     while (std::getline(file, str)) {
      std::cout << str << "\n";
     }
     file.close();

}