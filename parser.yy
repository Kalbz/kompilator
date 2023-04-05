%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
  
}
// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP CLASS EXTENDS PUBLIC STATIC VOID INT_KEYWORD BOOLEAN IF ELSE WHILE RETURN TRUE FALSE THIS NEW LENGTH PRINTLN STRINGLITERAL IDENTIFIER LCB RCB LB RB ASSIGNOP SEMICOLON COMMA DOT ANDOP EQOP NEOP OROP DIVOP MODOP NOTOP LCHEV RCHEV STRING_KEYWORD MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left PLUSOP MINUSOP
%left MULTOP DIVOP

// definition of the production rules. All production rules are of type Node
%type <Node *> root main_class expressions expression factor statement statement_list

%%
root:       expression {root = $1;};

expression: expression PLUSOP expression {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            $$ = new Node("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r1 "); */
                          }
            | expression MINUSOP expression {
                            $$ = new Node("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r2 "); */
                          }
            | expression MULTOP expression {
                            $$ = new Node("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            /* printf("r3 "); */
                          }
            | expression DIVOP expression {
                            $$ = new Node("DivExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression ANDOP expression {
                            $$ = new Node("AndOPExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression OROP expression {
                            $$ = new Node("OrOPExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression LCHEV expression {
                            $$ = new Node("LChevExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression RCHEV expression {
                            $$ = new Node("RChevExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression EQOP expression {
                            $$ = new Node("EqOpExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression expression {
                            $$ = new Node("ExpressionExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
            }
            | factor      {$$ = $1; /* printf("r4 ");*/}
            ;

factor:     INT           {  $$ = new Node("Int", $1, yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
            | LP expression RP { $$ = $2; /* printf("r6 ");  simply return the expression */}
    ;
