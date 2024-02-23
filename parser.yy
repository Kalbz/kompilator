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
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP CLASS EXTENDS PUBLIC STATIC 
%token <std::string> VOID INT_KEYWORD BOOLEAN IF ELSE WHILE RETURN TRUE FALSE THIS NEW LENGTH PRINTLN 
%token <std::string> STRINGLITERAL IDENTIFIER LCB RCB LB RB ASSIGNOP SEMICOLON COMMA DOT ANDOP EQOP 
%token <std::string> NEOP OROP DIVOP MODOP NOTOP LCHEV RCHEV STRING_KEYWORD MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl


%right ASSIGNOP
%left OROP
%left ANDOP
%left EQUOP
%left LCHEV RCHEV
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%right NEW
%right NOTOP
%left LP RP LB RB DOT
%nonassoc ELSE

// definition of the production rules. All production rules are of type Node
%type <Node *> root Goal MainClass expression VarDeclaration VarDeclarationList MethodDeclaration statement ClassDeclaration MethodDeclarationList ClassDeclarationList StatementList Parameter ParameterList body return Index ExtendedFunc Argumentlist IfStatement ElseStatement type StatementVars Arg MainBody void main vs Methods factor identifier




%%
root:       Goal {root = $1;};
            

Goal: MainClass END {
                          $$ = new Node("Goal", "", yylineno);
                          $$->children.push_back($1);
          } 
          | MainClass ClassDeclarationList END {
                          $$ = new Node("Goal", "", yylineno);
                          $$->children.push_back($1);
                          $$->children.push_back($2);
          } 
          ;


ClassDeclarationList: ClassDeclaration {
                          $$ = new Node("ClassDeclarationList", "", yylineno);
                          $$->children.push_back($1);

                          }
                          | ClassDeclarationList ClassDeclaration {
                            $$ = $1; 
                            $$->children.push_back($2);
                          }
    ;

MainClass: PUBLIC CLASS identifier LCB Methods RCB {
                            $$ = new Node("MainClass", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                          }  
    ;

Methods: PUBLIC STATIC void main Arg MainBody {
                            $$ = new Node("Method", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($4);
                            $$->children.push_back($5);
                            $$->children.push_back($6);
}
;

main : MAIN { $$ = new Node("Name", $1, yylineno); } ;
void : VOID { $$ = new Node("Type", $1, yylineno); } ;


MainBody: LCB statement RCB {
                            $$ = new Node("MainBody", "", yylineno);
                            $$->children.push_back($2);
};

Arg: LP STRING_KEYWORD LB RB identifier RP {
                            $$ = new Node("Argument", $2 + $3 + $4, yylineno);
                            $$->children.push_back($5);
                          
};


ClassDeclaration: CLASS identifier LCB  RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
            }
            | CLASS identifier LCB VarDeclarationList RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
            }
            | CLASS identifier LCB MethodDeclarationList RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
            }
            | CLASS identifier LCB VarDeclarationList MethodDeclarationList RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                            $$->children.push_back($5);
            }
            ;

VarDeclarationList: VarDeclaration { 
                                $$ = new Node("VarDeclarationList", "", yylineno); 
                                $$->children.push_back($1); 
                                }
              | VarDeclarationList VarDeclaration { 
                                $$ = $1;
                                $$->children.push_back($2); 
              }
              ;


MethodDeclarationList: MethodDeclaration { 
                                $$ = new Node("MethodDeclarationList", "", yylineno); 
                                $$->children.push_back($1);
                                }
                      | MethodDeclarationList MethodDeclaration { 
                                $$ = $1; 
                                $$->children.push_back($2); 
                                }
                      ;
VarDeclaration: type identifier SEMICOLON {
                            $$ = new VarDeclaration("VarDeclaration", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            
            } 
            ;

MethodDeclaration: PUBLIC type identifier LP RP LCB body RCB {
                            $$ = new MethodDeclaration("MethodDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            $$->children.push_back($7);
 
            }
            | PUBLIC type identifier LP ParameterList RP LCB body RCB {
                            $$ = new MethodDeclaration("MethodDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                            $$->children.push_back($8);
                                        }
          
            ;
            


ParameterList: Parameter{
                                $$ = new Node("Parameters", "", yylineno);
                                $$->children.push_back($1);
                                }
                                | ParameterList COMMA Parameter {
                                $$ = new Node("ParameterList", "", yylineno);
                                $$=$1;
                                $$->children.push_back($3);
                                }
    ;

Parameter: type identifier{
                                $$ = new Node("Parameter", "", yylineno);
                                $$->children.push_back($1);
                                $$->children.push_back($2);

}
;

body: return {
                          $$ = new Body("Body", "", yylineno);
                          $$->children.push_back($1);
      }
      | StatementVars return {
                          $$=$1 ;
                          $$->children.push_back($2);
      }
    ;

return: RETURN expression SEMICOLON {
                          $$ = new Node("Return", "", yylineno) ;
                          $$->children.push_back($2) ;

    }
    ;


StatementVars: vs {
                    $$ = new Body("Body", "", yylineno) ;
                    $$->children.push_back($1);
              }
              | StatementVars vs {
                    $$ = $1;
                    $$->children.push_back($2) ;
              }
    ;

vs: VarDeclaration { $$ = $1 ;} | statement {$$ = $1;} ;

type: BOOLEAN  { $$ = new Node("Type", $1, yylineno) ; } | INT_KEYWORD  { $$ = new Node("Type", $1, yylineno) ; } | IDENTIFIER { $$ = new Node("Type", $1, yylineno) ; } | INT_KEYWORD LB RB  { $$ = new Node("Type", $1 + $2 + $3, yylineno) ; } 
/* type: BOOLEAN  {$$ = $1;} | INT_KEYWORD  {$$ = $1;} | IDENTIFIER{$$ = $1;} | INT_KEYWORD LB RB  {$$ = $1 + $2 + $3;}  */
    ;


statement: LCB RCB {
                            $$ = new Node("EmptyStateMentList", "", yylineno);
            }
                        | LCB StatementList RCB {
                              $$ = $2;
                          } 
            | 
            
            IF LP expression RP IfStatement {
                            $$ = new Node("IF", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
            }
            | IF LP expression RP IfStatement ELSE ElseStatement {
                            $$ = new Node("IF ELSE", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                            $$->children.push_back($7);
                          } 
            | WHILE LP expression RP IfStatement {
                            $$ = new Node("WHILE", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
            }
            | PRINTLN LP expression RP SEMICOLON {
                            $$ = new Node("Print", "", yylineno);
                            $$->children.push_back($3);
            }
            | identifier ASSIGNOP expression SEMICOLON {
                            $$ = new Node("Assignment", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | identifier Index ASSIGNOP expression SEMICOLON {
                            $$ = new Node("Assignment", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
            }
            ;

IfStatement: statement {
                            $$ = new Node("True", "", yylineno);
                            $$->children.push_back($1);
                          } ;

ElseStatement: statement {
                            $$ = new Node("False", "", yylineno);
                            $$->children.push_back($1);
                          } ;


StatementList: statement {
                            $$ = new Node("Statements", "", yylineno);
                            $$->children.push_back($1);
                        }
                      | StatementList statement{
                            $$ = $1; 
                            $$->children.push_back($2);
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
            | expression Index {
                            $$ = new Node("ExpressionLBExpressionRB", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
            }
            | expression DOT LENGTH {
                            $$ = new Node("ExpressionDotLength", "", yylineno);
                            $$->children.push_back($1);
            }

            | expression DOT ExtendedFunc {
                            $$ = new Node("Method Invocation", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
            }
            | NEW INT_KEYWORD Index {
                            $$ = new Node("New Int", "", yylineno);
                            $$->children.push_back($3);
            }
            | NEW identifier LP RP {
                            $$ = new Node("New", "", yylineno);
                            $$->children.push_back($2);
            }
            | NOTOP expression {
                            $$ = new Node("Not Equal", "", yylineno);
                            $$->children.push_back($2);
            }
            | factor {$$ = $1; /* printf("r4 ");*/}
            | VarDeclaration {$$ = $1;}
            ;

ExtendedFunc: identifier LP RP {
                            $$ = new Node(".function", "", yylineno);
                            $$->children.push_back($1);
                  }
                  | identifier LP Argumentlist RP{
                            $$ = new Node(".function", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                  }
    ;

Index : LB expression RB {
                  $$ = new Node("Index", "", yylineno); 
                  $$->children.push_back($2);
                  } 
    ;

Argumentlist: expression {
                            $$ = new Node("Arguments", "", yylineno);
                            $$->children.push_back($1);
                          } 
            | Argumentlist COMMA expression {
                            $$ = $1; 
                            $$->children.push_back($3);
                          } 
    ;




factor:     INT           {  $$ = new Node("Int", $1, yylineno); }
            | identifier  {  $$ = $1; }
            | TRUE        {  $$ = new Node("True", $1, yylineno); }
            | FALSE       {  $$ = new Node("False", $1, yylineno); }
            | THIS        {  $$ = new Node("This", $1, yylineno); }
            | LP expression RP { $$ = $2; }
    ;

identifier: IDENTIFIER { $$ = new Node("ID/Name", $1, yylineno) ; } ;
