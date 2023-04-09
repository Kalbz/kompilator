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


%right ASSIGNOP
%left ANDOP
%left LCHEV RCHEV
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%right NEW
%right NOTOP
%left LB RB LP RP DOT


// definition of the production rules. All production rules are of type Node
%type <Node *> root Goal MainClass expression expressionList NonEmptyExpressionList VarDeclaration VarDeclarationList Type MethodDeclaration statement statementList NonEmptyStatementList ClassDeclaration MethodDeclarationList ClassDeclarationList NonEmptyClassDeclarationList MainClassList NonEmptyMainClassList ParameterList

%%
root:       Goal {root = $1;};
            


expressionList: { $$ = new Node("EmptyExpressionList", "", yylineno); }
              | NonEmptyExpressionList { $$ = $1; }
              ;

NonEmptyExpressionList: expression {
                          $$ = new Node("ExpressionList", "", yylineno);
                          $$->children.push_back($1);
                        }
                      | NonEmptyExpressionList "," expression {
                          $$ = $1;
                          $$->children.push_back($3);
                        }
                      ;

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
            | expression LB expression RB {
                            $$ = new Node("ExpressionLBExpressionRB", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | expression DOT LENGTH {
                            $$ = new Node("ExpressionDotLength", "", yylineno);
                            $$->children.push_back($1);
            }

            | expression DOT IDENTIFIER LP expressionList RP {
                            $$ = new Node("MethodInvocation", "", yylineno);
                            $$->children.push_back($1); 

                            Node* identifierNode = new Node("Identifier", $3, yylineno); 
                            $$->children.push_back(identifierNode); 

                            $$->children.push_back($5); 
            }
            | INT {
                            $$ = new Node("Int", "", yylineno);
                            $$->children.push_back(new Node("Int", $1, yylineno));
            }
            | TRUE {
                            $$ = new Node("TRUE", "", yylineno);
                            $$->children.push_back(new Node("True", $1, yylineno));
            }
            | FALSE {
                            $$ = new Node("FALSE", "", yylineno);
                            $$->children.push_back(new Node("False", $1, yylineno));
            }
            | IDENTIFIER {
                            $$ = new Node("IDENTIFIER", "", yylineno);
                            $$->children.push_back(new Node("IDENTIFIER", $1, yylineno));
            }
            | THIS {
                            $$ = new Node("THIS", "", yylineno);
                            $$->children.push_back(new Node("This", $1, yylineno));
            }
            | NEW INT_KEYWORD LB expression RB {
                            $$ = new Node("NewIntExpression", "", yylineno);
                            $$->children.push_back($4);
            }
            | NEW IDENTIFIER LP RP{
                            $$ = new Node("NewIdentifierExpression", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $2, yylineno));
            }
            | NOTOP expression {
                            $$ = new Node("NotExpression", "", yylineno);
                            $$->children.push_back($2);
            }
            | LP expression RP {
                            $$ = new Node("LPExpressionRP", "", yylineno);
                            $$->children.push_back($2);
            }

            ;

Type: INT_KEYWORD LB RB {
                            $$ = new Node("IntLBRB", "", yylineno);
            }
            | BOOLEAN {
                            $$ = new Node("Boolean", "", yylineno);
            }
            | INT_KEYWORD {
                            $$ = new Node("Int", "", yylineno);
            }
            | IDENTIFIER {
                            $$ = new Node("Identifier", "", yylineno);
            }
            ;

ParameterList: Type IDENTIFIER {
                            $$ = new Node("ParameterList", "", yylineno);
                            $$->children.push_back(new Node("IDENTIFIER", $2, yylineno));
            }
            | Type IDENTIFIER COMMA ParameterList {
                            $$ = new Node("ParameterList", "", yylineno);
                            $$->children.push_back(new Node("IDENTIFIER", $2, yylineno));
                            $$->children.push_back($4);
            }
            | { $$ = new Node("EmptyParameterList", "", yylineno); }
            ;


VarDeclaration: Type IDENTIFIER SEMICOLON {
                            $$ = new Node("VarDeclaration", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $2, yylineno));
                            
            } 
            ;

MethodDeclaration: PUBLIC Type IDENTIFIER LP ParameterList RP LCB VarDeclarationList statementList RETURN expression SEMICOLON RCB {
                            $$ = new Node("MethodDeclaration", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $3, yylineno));
 
            }
            | PUBLIC Type IDENTIFIER LP ParameterList RP LCB statementList RETURN expression SEMICOLON RCB {
                            $$ = new Node("MethodDeclaration", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $3, yylineno));

            }
            ;
            

MethodDeclarationList: { $$ = new Node("EmptyMethodDeclarationList", "", yylineno); }
                      | MethodDeclaration MethodDeclarationList { $$ = new Node("MethodDeclarationList", "", yylineno); $$->children.push_back($1); $$->children.push_back($2); }
                      ;



VarDeclarationList: { $$ = new Node("EmptyDeclarationList", "", yylineno); }
              | VarDeclaration VarDeclarationList { $$ = new Node("VarDeclarationList", "", yylineno); $$->children.push_back($1); $$->children.push_back($2); }
              ;



statementList: { $$ = new Node("EmptyStatementList", "", yylineno); }
              | NonEmptyStatementList { $$ = $1; }
              ;

NonEmptyStatementList: statement {
                            $$ = new Node("NonEmptyStatementList", "", yylineno);
                            $$->children.push_back($1);
                        }
                      | NonEmptyStatementList statement {
                          $$ = $1;
                          $$->children.push_back($2);
                        }
                      ;

statement: LCB statementList RCB {
                            $$ = new Node("LCBStatementListRCB", "", yylineno);
                            $$->children.push_back($2);
            }
            | IF LP expression RP statement ELSE statement {
                            $$ = new Node("IfLPExpressionRPStatement", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
            }
            | WHILE LP expression RP statement {
                            $$ = new Node("WhileLPExpressionRPStatement", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
            }
            | PRINTLN LP expression RP SEMICOLON {
                            $$ = new Node("SystemOutPrintlnLPExpressionRP", "", yylineno);
                            $$->children.push_back($3);
            }
            | IDENTIFIER ASSIGNOP expression SEMICOLON {
                            $$ = new Node("IdentifierEqualExpression", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $1, yylineno));
                            $$->children.push_back($3);
            }
            | IDENTIFIER LB expression RB ASSIGNOP expression SEMICOLON {
                            $$ = new Node("Identifier2EqualExpression", "", yylineno);
                            $$->children.push_back(new Node("Identifier2", $1, yylineno));
                            $$->children.push_back($3);
            }
            ;


ClassDeclaration: CLASS IDENTIFIER LCB VarDeclarationList MethodDeclarationList RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $2, yylineno));
                            $$->children.push_back($4);
                            $$->children.push_back($5);
            }
            ;

MainClass: PUBLIC CLASS IDENTIFIER LCB PUBLIC STATIC VOID MAIN LP STRING_KEYWORD LB RB IDENTIFIER RP LCB statement RCB RCB {
                            $$ = new Node("MainClass", "", yylineno);
                            $$->children.push_back(new Node("Identifier", $3, yylineno));
                            $$->children.push_back(new Node("Identifier", $13, yylineno));
                            $$->children.push_back($16);
            }
            ;

ClassDeclarationList: { $$ = new Node("EmptyClassDeclarationList", "", yylineno); }
                     | NonEmptyClassDeclarationList { $$ = $1; }
                     ;

NonEmptyClassDeclarationList: ClassDeclaration {
                            $$ = new Node("NonEmptyClassDeclarationList", "", yylineno);
                            $$->children.push_back($1);
                        }
                     | NonEmptyClassDeclarationList ClassDeclaration {
                          $$ = $1;
                          $$->children.push_back($2);
                        }
                     ;

MainClassList: { $$ = new Node("EmptyMainClassList", "", yylineno); }
             | NonEmptyMainClassList { $$ = $1; }
             ;

NonEmptyMainClassList: MainClass {
                          $$ = new Node("NonEmptyMainClassList", "", yylineno);
                          $$->children.push_back($1);
                      }
                    | NonEmptyMainClassList MainClass {
                        $$ = $1;
                        $$->children.push_back($2);
                      }
                    ;

Goal: MainClassList ClassDeclarationList END {
                          $$ = new Node("Goal", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($2);
          }
          ;