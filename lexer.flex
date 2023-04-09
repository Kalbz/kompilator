%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("SUBOP ");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP(yytext);}}
"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LCB ");} else {return yy::parser::make_LCB(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RCB ");} else {return yy::parser::make_RCB(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LB ");} else {return yy::parser::make_LB(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RB ");} else {return yy::parser::make_RB(yytext);}}
"="                     {if(USE_LEX_ONLY) {printf("ASSIGNOP ");} else {return yy::parser::make_ASSIGNOP(yytext);}}
";"                     {if(USE_LEX_ONLY) {printf("SEMICOLON ");} else {return yy::parser::make_SEMICOLON(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("COMMA ");} else {return yy::parser::make_COMMA(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_DOT(yytext);}}
"&&"                    {if(USE_LEX_ONLY) {printf("ANDOP ");} else {return yy::parser::make_ANDOP(yytext);}}
"=="                    {if(USE_LEX_ONLY) {printf("EQOP ");} else {return yy::parser::make_EQOP(yytext);}}
"!="                    {if(USE_LEX_ONLY) {printf("NEOP ");} else {return yy::parser::make_NEOP(yytext);}}
"||"                    {if(USE_LEX_ONLY) {printf("OROP ");} else {return yy::parser::make_OROP(yytext);}}
"/"                     {if(USE_LEX_ONLY) {printf("DIVOP ");} else {return yy::parser::make_DIVOP(yytext);}}
"%"                     {if(USE_LEX_ONLY) {printf("MODOP ");} else {return yy::parser::make_MODOP(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOTOP ");} else {return yy::parser::make_NOTOP(yytext);}}
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);}}
"extends"               {if(USE_LEX_ONLY) {printf("EXTENDS ");} else {return yy::parser::make_EXTENDS(yytext);}}
"public"                {if(USE_LEX_ONLY) {printf("PUBLIC ");} else {return yy::parser::make_PUBLIC(yytext);}}
"static"                {if(USE_LEX_ONLY) {printf("STATIC ");} else {return yy::parser::make_STATIC(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INT_KEYWORD ");} else {return yy::parser::make_INT_KEYWORD(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOLEAN ");} else {return yy::parser::make_BOOLEAN(yytext);}}
"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE(yytext);}}
"while"                 {if(USE_LEX_ONLY) {printf("WHILE ");} else {return yy::parser::make_WHILE(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RETURN(yytext);}}
"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_TRUE(yytext);}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_FALSE(yytext);}}
"this"                  {if(USE_LEX_ONLY) {printf("THIS ");} else {return yy::parser::make_THIS(yytext);}}
"new"                   {if(USE_LEX_ONLY) {printf("NEW ");} else {return yy::parser::make_NEW(yytext);}}
"length"                {if(USE_LEX_ONLY) {printf("LENGTH ");} else {return yy::parser::make_LENGTH(yytext);}}
"System.out.println"    {if(USE_LEX_ONLY) {printf("PRINTLN ");} else {return yy::parser::make_PRINTLN(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LCHEV ");} else {return yy::parser::make_LCHEV(yytext);}}
">"                     {if(USE_LEX_ONLY) {printf("RCHEV ");} else {return yy::parser::make_RCHEV(yytext);}}
"String"                {if(USE_LEX_ONLY) {printf("STRING_KEYWORD ");} else {return yy::parser::make_STRING_KEYWORD(yytext);}}
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_MAIN(yytext);}}


[a-zA-Z_][a-zA-Z0-9_]*  {if(USE_LEX_ONLY) {printf("IDENTIFIER ");} else {return yy::parser::make_IDENTIFIER(yytext);}}
0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}
\"([^\"]|\\\")*\"       {if(USE_LEX_ONLY) {printf("STRINGLITERAL ");} else {return yy::parser::make_STRINGLITERAL(yytext);}}

[ \t\n\r]+              {}
"//".*                  {}
"/*"([^*]|(\*+[^*/]))*\*+"/" {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); printf("Character %s is not recognized\n", yytext); lexical_errors = 1;}
<<EOF>>                 return yy::parser::make_END();
%%