%{
****** C Stuff (headers, declarations, variables, etc) ******
#include <stdio.h>
void showError();
%}

****** regular expressions ******
numbers ([0-9])+


%%
****** token specifications (what tokens do) ******
"hello"     {return (STRING);}
{numbers}   {return (NUM);}
";"         {return (SEMICOLON);}
.           {showError(); return(OTHER);}

%%

****** C Functions ******
void showError(){
    printf("Other input hehe");
}