/* Elaheh Toulabi Nejad 9631243*/
/* NOTE : ((.*)*.*)(\*\/) was my previous RegEx which ignored all tokens between last valid  token and unopened one */

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lineNO = 1;

%}


%option yylineno


DIGIT              [0-9]
SLETTER            [a-z]
CLETTER            [A-Z]
IDENTIFIER         ({CLETTER}|{SLETTER})({CLETTER}|{SLETTER}|{DIGIT}|-)*
NIDENTIFIER        ({DIGIT}|-)({CLETTER}|{SLETTER}|{DIGIT}|-)+
KEYWORD            "int"|"float"|"char"|"string"|"double"|"void"|"main"|"foreach"|"return"|"if"|"break"|"continue"             
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
                  if(!strcmp(yytext,"int"))
                     printf("\nTOKEN_INTTYPE int");
                  else if(!strcmp(yytext,"float"))
                     printf("\nTOKEN_FLOATTYPE float");
                  else if(!strcmp(yytext,"double"))
                     printf("\nTOKEN_DOUBLETYPE double");
                  else if(!strcmp(yytext,"string"))
                     printf("\nTOKEN_STRINGTYPE string");
                  else if(!strcmp(yytext,"char"))
                     printf("\nTOKEN_CHARTYPE char");
                  else if(!strcmp(yytext,"void"))
                     printf("\nTOKEN_VOIDTYPE %s",yytext);
                  else if(!strcmp(yytext,"main"))
                     printf("\nTOKEN_MAINFUNC %s",yytext);
                  else if(!strcmp(yytext,"foreach"))
                     printf("\nTOKEN_LOOP %s",yytext);
                  else if(!strcmp(yytext,"return"))
                     printf("\nTOKEN_RETURN %s",yytext);
                  else if(!strcmp(yytext,"if"))
                     printf("\nTOKEN_IFCONDITION %s",yytext);
                  else if(!strcmp(yytext,"break"))
                     printf("\nTOKEN_BREAKSTMT %s",yytext);
                  else if(!strcmp(yytext,"continue"))
                     printf("\nTOKEN_CONTINUESTMT %s",yytext);
               }

{IDENTIFIER}   {
                  if(yyleng<31)
                     printf("\nTOKEN_ID %s",yytext);
                  else{
                     printf("\nerror in line %d : identifier too long",yylineno);
                     return 1;
                  }
               }
{NIDENTIFIER}  {
                  printf("\nerror in line %d : wrong id definition",yylineno);
                  return 1;
               }

{WHITESPACE}   {
                  if(!strcmp(yytext," "))
                     printf("\nTOKEN_WHITESPACE	[space]");
                  else if(!strcmp(yytext,"\t"))
                     printf("\nTOKEN_WHITESPACE	\\t");
                  else if(!strcmp(yytext,"\n")){
                     printf("\nTOKEN_WHITESPACE	\\n");
                     lineNO++;
                  }
               }

{SINGLELINE}   {  printf("\nTOKEN_COMMENT");}

{MULTILINE}    {  printf("\nTOKEN_COMMENT");}

{UNCLOSED}     {  printf("\nerror in line %d : unclosed comment section",lineNO);
                  return 1;
               }   

{UNOPENED}     {
                  printf("\nerror in line %d : unopened comment section",lineNO);
                  return 1;
               }

{INTEGER}      {
                  int upper_bound=2147483647;
                  int lower_bound =-2147483648;
                  long long int x = atoll(yytext);
                  if(x < upper_bound && x > lower_bound)
                     printf("\nTOKEN_INTCONST %s",yytext);
                  else{
                     printf("\nerror in line %d : integer constant is out of range",yylineno);
                     return 1;
                  }
               }

{SIMPLE_FRAC}  {  printf("\nTOKEN_FLOATCONST %s",yytext);}

{SCIENTIFIC_FRAC} {printf("\nTOKEN_FLOATCONST %s",yytext);}

{STRING}       {  printf("\nTOKEN_STRINGCONST %s",yytext);}

{CHARACTER}    {  printf("\nTOKEN_CHARCONST %s",yytext);}

{ARITHMETIC}   {  printf("\nTOKEN_ARITHMATICOP %s",yytext);} 

{SIGNS}        {
                  if(!strcmp(yytext,"&&"))
                     printf("\nTOKEN_LOGICOP %s",yytext);
                  else if(!strcmp(yytext,"||"))
                     printf("\nTOKEN_LOGICOP %s",yytext);
                  else if(!strcmp(yytext,"!"))
                     printf("\nTOKEN_LOGICOP %s",yytext);
                  else if(!strcmp(yytext,"&"))
                     printf("\nTOKEN_BITWISEOP %s",yytext);
                  else if(!strcmp(yytext,"|"))
                     printf("\nTOKEN_BITWISEOP %s",yytext);
                  else if(!strcmp(yytext,">"))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,"<"))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,">="))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,"<="))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,"=="))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,"!="))
                     printf("\nTOKEN_RELATIONOP %s",yytext);
                  else if(!strcmp(yytext,"="))
                     printf("\nTOKEN_ASSIGNOP %s",yytext);
                  else if(!strcmp(yytext,")"))
                     printf("\nTOKEN_RIGHTPAREN %s",yytext);
                  else if(!strcmp(yytext,"("))
                     printf("\nTOKEN_LEFTPAREN %s",yytext);
                  else if(!strcmp(yytext,"]"))
                     printf("\nTOKEN_RB %s",yytext);
                  else if(!strcmp(yytext,"["))
                     printf("\nTOKEN_LB %s",yytext);
                  else if(!strcmp(yytext,"}"))
                     printf("\nTOKEN_RCB %s",yytext);
                  else if(!strcmp(yytext,"{"))
                     printf("\nTOKEN_LCB %s",yytext);
                  else if(!strcmp(yytext,";"))
                     printf("\nTOKEN_SEMICOLON %s",yytext);
                  else if(!strcmp(yytext,","))
                     printf("\nTOKEN_COMMA %s",yytext);
                  else if(!strcmp(yytext,".."))
                     printf("\nTOKEN_UNTIL %s",yytext);
               }

%%


int yywrap(){

   printf("\n");
   return 1;
}


int main(int argc ,char *argv[]) 
{ 
   if (argc < 2) {
		printf("\n[-] Please provide file path.\n");
		return 0;
	}

	yyin = fopen(argv[1],"r"); 
	yylex(); 
	fclose(yyin);
	return 0; 
}