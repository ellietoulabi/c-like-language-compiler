%{
          
     #include <stdio.h>
     #include <iostream>
     #include <stdlib.h>
     #include <math.h>
     #include <string.h>
     #include <string>
     #include <unordered_map> 
     #include <algorithm>
     #include <fstream>
     #include<stack>


     using namespace std;

     int current_dtype;
     int is_declaration = 0;
     int is_loop = 0;
     int is_func = 0;
     int func_type;
     int out = 0;
     int rhs = 0;
     int scopeNo=0; 
     struct perScope{
          int type;
          int scope;
          int cnt;

     };
     unordered_map<string, struct perScope> umap; 

     ofstream MyFile("output.out");


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
%type <token> lhs    compoundStmt  function declaration parameter parameter_list


/*==============================================================precedances===============================================================*/

%left TOKEN_COMMA
%right TOKEN_ASSIGNOP
%left TOKEN_LOGICOR
%left TOKEN_LOGICAND
%left TOKEN_BITWISEOR TOKEN_BITWISEAND
%left TOKEN_EQ TOKEN_NOTEQ
%left TOKEN_GR TOKEN_LS TOKEN_LSEQ TOKEN_GREQ
%left TOKEN_RELATIONOP
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MUL TOKEN_DIV
%left TOKEN_POW
%right TOKEN_LOGICNOT

%nonassoc UMINUS



/*==============================================================grammar===============================================================*/

%start program

%%

program:                globalVars  {strcpy($$._byid," PROGRAM ");strcpy($$._byname," PROGRAM ");strcat($$._byid,$1._byid);strcat($$._byname,$1._byname);
                                     

                                     if (out==1)
                                        cout << "\n\n\n[+] Parse : \n\n"<<$$._byid;
                                     else if (out == 0)
                                          cout << "\n[+] Parse : \n"<<$$._byname;
                                     else
                                        MyFile<<"[-] ERROR IN OUTPUT TYPE : WRONG OPTION";


                                    }
                        ;


globalVars:              typeSpecifier   identifier   TOKEN_ASSIGNOP   constants TOKEN_SEMICOLON   globalVars {  
                                                                                                                   strcpy($$._byid," globalVars ");
                                                                                                                   strcat($$._byid,$1._byid);
                                                                                                                   strcat($$._byid,$2._byid);
                                                                                                                   strcat($$._byid," = ");
                                                                                                                   strcat($$._byid,$4._byid);
                                                                                                                   strcat($$._byid," ; ");
                                                                                                                   strcat($$._byid,$6._byid);

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
                                                                                                                   strcpy($$._byname,$1._byname);}
                        ;

function:                typeSpecifier   TOKEN_MAINFUNC{ 

                            func_type = current_dtype;
                            is_declaration = 0;
                            

                        }
                        TOKEN_LEFTPAREN  TOKEN_RIGHTPAREN {
                          
                                            is_declaration = 0;
							          is_func = 1;

                        }compoundStmt    {is_func = 0; if ($1._datatype != 1 )yyerror("main function must be of type INT");
                        
                                             strcpy($$._byid," main_function ");
                                             strcat($$._byid,$1._byid);
                                             strcat($$._byid," main ");
                                             strcat($$._byid," ( ");
                                             strcat($$._byid," ) ");
                                             strcat($$._byid,$7._byid);
                                             
                                             strcpy($$._byname," main_function ");
                                             strcat($$._byname,$1._byname);
                                             strcat($$._byname," TOKEN_MAINFINC  ");
                                             strcat($$._byname," TOKEN_LEFTPARAN ");
                                             strcat($$._byname," TOKEN_RIGHTPARAN ");
                                             strcat($$._byname,$7._byname);
                        
                                         }
                        |typeSpecifier   identifier{

                            func_type = current_dtype;
                            is_declaration = 0;

                        } TOKEN_LEFTPAREN argumentList TOKEN_RIGHTPAREN{
                          
                                            is_declaration = 0;
									is_func = 1;

                        }
                        compoundStmt  {is_func = 0;} function  {

                                            strcpy($$._byid," function ");
                                             strcat($$._byid,$1._byid);
                                             strcat($$._byid,$2._byid);
                                             strcat($$._byid," ( ");
                                             strcat($$._byid,$5._byid);
                                             strcat($$._byid," ) ");
                                             strcat($$._byid,$8._byid);
                                             strcat($$._byid,$10._byid);
                                             
                                             strcpy($$._byname," function ");
                                             strcat($$._byname,$1._byname);
                                             strcat($$._byname,$2._byname);
                                             strcat($$._byname," TOKEN_LEFTPARAN ");
                                             strcat($$._byname,$5._byname);
                                             strcat($$._byname," TOKEN_RIGHTPARAN ");
                                             strcat($$._byname,$8._byname);
                                             strcat($$._byname,$10._byname);
                                      } 
                        ;

argumentList:            arguments                           {if($$._cnt > 4) yyerror("too many arguments");
                                                              strcpy($$._byid," argumentList "); 
                                                              strcpy($$._byname," argumentList "); 
                                                              strcat($$._byname,$1._byname);
                                                              strcat($$._byid, $1._byid);
                                                             }
                        |
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
                                        strcpy($$._byname," stmt "); 
                                        strcat($$._byname,$1._byname);
                                        strcat($$._byid, $1._byid);   
                                     }
                        ;

compoundStmt:           TOKEN_LCB {scopeNo++;} statements TOKEN_RCB {
                                                                      strcpy($$._byid," compoundStmt "); 
                                                                      strcpy($$._byname," compoundStmt "); 
                                                                      strcat($$._byname," TOKEN_LCB ");
                                                                      strcat($$._byid," { ");
                                                                      strcat($$._byname,$3._byname);
                                                                      strcat($$._byid,$3._byid);                                                                           
                                                                      strcat($$._byid," } "); 
                                                                      strcat($$._byname," TOKEN_RCB "); 
                                                                    }
                        ;



singleStmt:              conditionStmt                 {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);   
                                                       }
                        |loopStmt                      {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);   
                                                       }
                        |declaration                   {
                                                            strcpy($$._byid," singleStmt "); 
                                                            strcpy($$._byname," singleStmt "); 
                                                            strcat($$._byname,$1._byname);
                                                            strcat($$._byid, $1._byid);   
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
                        }
                        ;         


printFunc:                TOKEN_PRFUNC TOKEN_LEFTPAREN expression TOKEN_RIGHTPAREN  {

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




conditionStmt:           TOKEN_IFCONDITION TOKEN_LEFTPAREN   expression   TOKEN_RIGHTPAREN compoundStmt                                      {
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
                                                                                                                                             }
                        |TOKEN_IFCONDITION TOKEN_LEFTPAREN   expression    TOKEN_RIGHTPAREN compoundStmt  TOKEN_ELSECONDITION compoundStmt   {
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
                                                                                          }
                        |identifier TOKEN_LEFTPAREN TOKEN_RIGHTPAREN                {$$._datatype = $1._datatype;
                        
                                                                                     strcpy($$._byid," functionCall "); 
                                                                                     strcpy($$._byname," functionCall "); 
                                                                                     strcat($$._byid,$1._byid);
                                                                                     strcat($$._byname,$1._byname);
                                                                                     strcat($$._byname," TOKEN_LEFTPAREN "); 
                                                                                     strcat($$._byid," ( ");
                                                                                     strcat($$._byname," TOKEN_RIGHTPAREN "); 
                                                                                     strcat($$._byid," ) ");
                                                                                     
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
                                                                        }
                        |parameter                                      {  strcpy($$._byid,$1._byid);
                                                                           strcpy($$._byname,$1._byname);
                                                                        }
                        ;

parameter:               sub_expr                                       {
                                                                           strcpy($$._byid," parameter "); 
                                                                           strcpy($$._byname," parameter "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
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


                                                                        }
			          |declaration_list TOKEN_SEMICOLON              {
                                                                           is_declaration = 0;
                                                                           strcpy($$._byid," declaration "); 
                                                                           strcpy($$._byname," declaration "); 
                                                                           strcat($$._byid,$1._byid);
                                                                           strcat($$._byname,$1._byname);
                                                                           strcat($$._byname,"TOKEN_SEMICOLON"); 
                                                                           strcat($$._byid," ; ");
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
                                                                        }
                        ;

sub_decl:                assignment_expr                    {
                                                                 strcpy($$._byid," sub_decl "); 
                                                                 strcpy($$._byname," sub_decl "); 
                                                                 strcat($$._byid,$1._byid);
                                                                 strcat($$._byname,$1._byname);
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
                        
                                                                    }
                        |assignment_expr                            {$$._datatype = $1._datatype;
                                                                     strcpy($$._byname," sub_expr ");
                                                                     strcpy($$._byid," sub_expr ");
                                                                     strcat($$._byid,$1._byid);
                                                                     strcat($$._byname,$1._byname);
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

                                                                                               }
                        |lhs assgn  array_access            { type_check($1._datatype,$3._datatype,1); $$._datatype = $3._datatype;rhs=0;
                                                                                                 strcpy($$._byname," assignment_expr ");
                                                                                                 strcpy($$._byid," assignment_expr "); 
                                                                                                 strcat($$._byname,$1._byname); 
                                                                                                 strcat($$._byid,$1._byid);
                                                                                                 strcat($$._byname,"TOKEN_ASSIGNOP"); 
                                                                                                 strcat($$._byid,"=");
                                                                                                 strcat($$._byname,$3._byname); 
                                                                                                 strcat($$._byid,$3._byid);
                                                                                                 
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

                                                                                               }
                        |lhs assgn array_init     {
                              type_check($1._datatype,$3._datatype,1);
                              yyerror("cant be initialized");
                                                       
                                                  }
                        ;



lhs:                     identifier                {$$._datatype = $1._datatype;strcpy($$._byid,$1._byid);strcat($$._byid,$1._byname);}
                        |array_access              {$$._datatype = $1._datatype;strcpy($$._byid,$1._byid);strcat($$._byid,$1._byname);}
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
                                                                      temp.type=current_dtype;
                                                                      temp.scope=scopeNo;
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
                        |arithmetic_expr TOKEN_MUL arithmetic_expr         {    
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_MUL "); 
                                                                                strcat($$._byid," * ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);

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
                        |arithmetic_expr TOKEN_DIV arithmetic_expr         {
                                                                                strcpy($$._byname," arithmetic_expr ");
                                                                                strcpy($$._byid," arithmetic_expr "); 
                                                                                strcat($$._byname,$1._byname); 
                                                                                strcat($$._byid,$1._byid); 
                                                                                strcat($$._byname," TOKEN_DIV "); 
                                                                                strcat($$._byid," / ");
                                                                                strcat($$._byname,$3._byname); 
                                                                                strcat($$._byid,$3._byid);
                                                                               

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
                        |TOKEN_LEFTPAREN arithmetic_expr TOKEN_RIGHTPAREN   {$$._datatype = $2._datatype; strcpy($$._byid," TOKEN_LEFTPAREN");strcat($$._byname,"(");strcat($$._byid,$2._byid); strcat($$._byname,$2._byname);strcat($$._byid," ) ");strcat($$._byname," TOKEN_RIGHTPAREN ");}
                        |TOKEN_MINUS arithmetic_expr %prec UMINUS           {$$._datatype = $2._datatype; strcpy($$._byid,"  - ");strcat($$._byname," TOKEN_MINUS ");strcat($$._byid,$2._byid); strcat($$._byname,$2._byname);}
                        |identifier                                         {$$._datatype = $1._datatype; strcpy($$._byid,$1._byid); strcpy($$._byname,$1._byname);}
                        |constants                                          {$$._datatype = $1._datatype; strcpy($$._byid,$1._byid); strcpy($$._byname,$1._byname);}
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

                                                                }                                     
                        ;



typeSpecifier:       TOKEN_INTTYPE              { is_declaration = 1;current_dtype=1; $$._datatype=1; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_INTTYPE "); strcat($$._byid,$1._val);   }
                    |TOKEN_FLOATTYPE            { is_declaration = 1; current_dtype=2; $$._datatype=2; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_FLOATTYPE "); strcat($$._byid,$1._val); }
                    |TOKEN_DOUBLETYPE           { is_declaration = 1; current_dtype=6; $$._datatype=6; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_DOUBLETYPE "); strcat($$._byid,$1._val);}
                    |TOKEN_CHARTYPE             { is_declaration = 1; current_dtype=3; $$._datatype=3; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_CHARTYPE "); strcat($$._byid,$1._val);  }
                    |TOKEN_STRINGTYPE           { is_declaration = 1; current_dtype=4; $$._datatype=4; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_STRINGTYPE "); strcat($$._byid,$1._val);}
                    |TOKEN_VOIDTYPE             { is_declaration = 1; current_dtype=5; $$._datatype=5; strcpy($$._byname," typeSpecifier "); strcpy($$._byid," typeSpecifier "); strcat($$._byname," TOKEN_VOIDTYPE "); strcat($$._byid,$1._val);  }
                    ;

constants:           TOKEN_INTCONST             {$$._datatype = 1; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_INTCONST "); strcat($$._byid,$1._val);   }
                    |TOKEN_CHARCONST            {$$._datatype = 3; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_CHARCONST "); strcat($$._byid,$1._val);  } 
                    |TOKEN_FLOATCONST           {$$._datatype = 2; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_FLOATCONST "); strcat($$._byid,$1._val); }
                    |TOKEN_STRINGCONST          {$$._datatype = 4; strcpy($$._byname," constants "); strcpy($$._byid," constants "); strcat($$._byname," TOKEN_STRINGCONST "); strcat($$._byid,$1._val);}
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