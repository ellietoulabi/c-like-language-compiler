%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Parser.h"


int lineNO = 1;
int columnNo=0;

void count(void);

%}

%option yylineno
%option noyywrap




DIGIT              [0-9]
SLETTER            [a-z]
CLETTER            [A-Z]
IDENTIFIER         ({CLETTER}|{SLETTER})({CLETTER}|{SLETTER}|{DIGIT}|-)*
NIDENTIFIER        ({DIGIT}|-)({CLETTER}|{SLETTER}|{DIGIT}|-)+
KEYWORD            "int"|"float"|"char"|"string"|"double"|"void"|"main"|"foreach"|"return"|"if"|"break"|"continue"|"else"|"print"             
SINGLELINE         (\/\/.*) 
MULTILINE          (\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)
UNCLOSED           (\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*[^\*][^\/])
UNOPENED           "*/"
WHITESPACE         [ \n\t]
STRING             (\")(.*)(\")
CHARACTER          ((\')({DIGIT}|{SLETTER}|{CLETTER})(\'))|(\'(\\.|[^'\\])\')       
ARITHMETIC         "+"|"-"|"*"|"/"|"^"
SIGNS              "&&"|"||"|"!"|"&"|"|"|">"|"<"|">="|"<="|"=="|"!="|"="|")"|"("|"]"|"["|"}"|"{"|";"|","|".."            
INTEGER            (\+|-)*{DIGIT}+
SIMPLE_FRAC        (\+|-)*{DIGIT}+(\.){DIGIT}+
SCIENTIFIC_FRAC    ((\+|-)*{DIGIT}(\.{DIGIT}+)*[eE]{DIGIT}+)



%%

{KEYWORD}      {
                  if(!strcmp(yytext,"int")){
                     count();
                      yylval.token._val= strdup(yytext);
                     return TOKEN_INTTYPE;
                  }
                  else if(!strcmp(yytext,"float")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_FLOATTYPE;
                  }
                  else if(!strcmp(yytext,"double")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_DOUBLETYPE;
                  }
                  else if(!strcmp(yytext,"string")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_STRINGTYPE;
                  }
                  else if(!strcmp(yytext,"char")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_CHARTYPE;
                  }
                  else if(!strcmp(yytext,"void")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_VOIDTYPE;
                  }
                  else if(!strcmp(yytext,"main")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_MAINFUNC;
                  }
                  else if(!strcmp(yytext,"foreach")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_LOOP;
                  }
                  else if(!strcmp(yytext,"return")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_RETURN;
                  }
                  else if(!strcmp(yytext,"if")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_IFCONDITION;
                  }
                  else if(!strcmp(yytext,"break")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_BREAKSTMT;
                  }
                  else if(!strcmp(yytext,"continue")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_CONTINUESTMT;
                  }
                  else if(!strcmp(yytext,"else")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_ELSECONDITION;
                  }
                  else if(!strcmp(yytext,"print")){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_PRFUNC;
                  }
               }

{IDENTIFIER}   {
                  if(yyleng<31){
                     count();
                       yylval.token._val= strdup(yytext);
                     return TOKEN_ID;
                  }
                  else{
                     printf("\nERROR IN LINE %d COLUMN %d : identifier too long",yylineno,columnNo);
                     return 1;
                  }
               }
{NIDENTIFIER}  {
                  printf("\nERROR IN LINE %d COLUMN %d : wrong id definition",yylineno,columnNo);
                  return 1;
               }

{WHITESPACE}   {
                  if(!strcmp(yytext," ")){
                     count();

                  }
                  else if(!strcmp(yytext,"\t")){
                     count();
                  }
                  else if(!strcmp(yytext,"\n")){
                     columnNo=0;
                     lineNO++;
                  }

               }

{SINGLELINE}   { 
                  count();
                
               }

{MULTILINE}    {  count();  

               }

{UNCLOSED}     {  printf("\nERROR IN LINE %d COLUMN %d :  unclosed comment section",lineNO,columnNo);
                  return 1;
               }   

{UNOPENED}     {
                  printf("\nERROR IN LINE %d COLUMN %d :  unopened comment section",lineNO,columnNo);
                  return 1;
               }

{INTEGER}      {
                  int upper_bound=2147483647;
                  int lower_bound =-2147483648;
                  long long int x = atoll(yytext);
                  if(x < upper_bound && x > lower_bound){
                     count();
                      yylval.token._val= strdup(yytext);
                     return TOKEN_INTCONST;
                  }
                  else{
                     printf("\nERROR IN LINE %d COLUMN %d :  integer constant is out of range",yylineno,columnNo);
                     return 1;
                  }
               }

{SIMPLE_FRAC}  {  count();
                   yylval.token._val=strdup(yytext);
                  return TOKEN_FLOATCONST;
               }

{SCIENTIFIC_FRAC} {
                  count();
                    yylval.token._val=strdup(yytext);
                  return TOKEN_FLOATCONST;
                  }

{STRING}       {
                  count();
                    yylval.token._val=strdup(yytext);
                  return TOKEN_STRINGCONST;
               }

{CHARACTER}    {  
                  count();
                    yylval.token._val= strdup(yytext);
                  return TOKEN_CHARCONST;
               }

{ARITHMETIC}   {  
                  count();
                    yylval.token._val=strdup(yytext);
                  if(!strcmp(yytext,"+"))
                     return TOKEN_PLUS;
                  else if(!strcmp(yytext,"-"))
                     return TOKEN_MINUS;
                  else if(!strcmp(yytext,"*"))
                     return TOKEN_MUL;
                  else if(!strcmp(yytext,"/"))
                     return TOKEN_DIV;
                  else if(!strcmp(yytext,"^"))
                     return TOKEN_POW;


               }
{SIGNS}        {
                  if(!strcmp(yytext,"&&")){
                     count();
                      yylval.token._val=strdup(yytext);
                     return TOKEN_LOGICAND;}
                  else if(!strcmp(yytext,"||")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LOGICOR;}
                  else if(!strcmp(yytext,"!")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LOGICNOT;}
                  else if(!strcmp(yytext,"&")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_BITWISEOR;}
                  else if(!strcmp(yytext,"|")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_BITWISEOR;}
                  else if(!strcmp(yytext,">")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_GR;}
                  else if(!strcmp(yytext,"<")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LS;}
                  else if(!strcmp(yytext,">=")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_GREQ;}
                  else if(!strcmp(yytext,"<=")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LSEQ;}
                  else if(!strcmp(yytext,"==")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_EQ;}
                  else if(!strcmp(yytext,"!=")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_NOTEQ;}
                  else if(!strcmp(yytext,"=")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_ASSIGNOP;}
                  else if(!strcmp(yytext,")")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_RIGHTPAREN;}
                  else if(!strcmp(yytext,"(")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LEFTPAREN;}
                  else if(!strcmp(yytext,"]")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_RB;}
                  else if(!strcmp(yytext,"[")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LB;}
                  else if(!strcmp(yytext,"}")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_RCB;}
                  else if(!strcmp(yytext,"{")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_LCB;}
                  else if(!strcmp(yytext,";")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_SEMICOLON;}
                  else if(!strcmp(yytext,",")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_COMMA;}
                  else if(!strcmp(yytext,"..")){
                     count();
                       yylval.token._val=strdup(yytext);
                     return TOKEN_UNTIL;}
               }

%%




void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			columnNo = 0;
		else if (yytext[i] == '\t')
			columnNo += 8 - (columnNo % 8);
		else
			columnNo++;

	ECHO;
}


