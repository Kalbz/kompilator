%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the 
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  extern int yylineno;
  
}
// definition of set of tokens. All tokens are of type string
%token <std::string> IDENTIFIER BOOLDEF INTDEF PUBILC CLASS STR STATIC MAIN VOID RET ELSE IF WHILE 
%token <std::string> SOPL LEN TRUE FALSE THIS NEW LP RP LCB RCB LB RB SEMICOLON COMMA DOT EXM PLUSOP MINUSOP 
%token <std::string> MULTOP ASSIGN ANDOP OROP LTOP GTOP EQUOP DIVOP INT 
%token END 0 "end of file"

//defition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl

%right ASSIGN 
%left OROP
%left ANDOP
%left EQUOP
%left LTOP GTOP
%left PLUSOP MINUSOP
%left MULTOP DIVOP 
%right NEW
%right EXM
%left LP RP LB RB DOT
%nonassoc ELSE

// definition of the production rules. All production rules are of type Node
%type <Node *> root expression methods main factor ifStatement elseStatement varDeclaration index arg 
%type <Node *> extendedFunc vs body return identifier argumentlist goal classDeclarations mainClass 
%type <Node *> classDeclaration varDeclarations methodDeclarations methodDeclaration parameter parameters 
%type <Node *> StatementVars statement stmtArgumentlist type void mainBody


%%
root:       goal {root = $1;};

goal:  mainClass END {
                            $$ = new Node("Goal", "", yylineno);
                            $$->children.push_back($1);
                          } 
                  | mainClass classDeclarations END {
                            $$ = new Node("Goal", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                          } 
    ;
    
classDeclarations: classDeclaration {
                            $$ = new Node("ClassDeclarations", "", yylineno);
                            $$->children.push_back($1);
                          }  
                    | classDeclarations classDeclaration {
                            $$ = $1; 
                            $$->children.push_back($2);
                          } 
    ;

mainClass: PUBILC CLASS identifier LCB methods RCB {
                            $$ = new Node("MainClass", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                          }  
    ;

methods :  PUBILC STATIC void main arg  mainBody {
                            $$ = new Node("Method", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($4);
                            $$->children.push_back($5);
                            $$->children.push_back($6);
                          }
    ;
  
main : MAIN { $$ = new Node("Name", $1, yylineno); } ;
void : VOID { $$ = new Node("Type", $1, yylineno); } ;
mainBody : LCB statement RCB {
                            $$ = new Node("Body", "", yylineno);
                            $$->children.push_back($2);
                           }
    ;

arg: LP STR LB RB identifier RP {
                            $$ = new Node("Argument", $2 + $3 + $4, yylineno);
                            $$->children.push_back($5);
                          };

classDeclaration: CLASS identifier LCB RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                          }  
                  | CLASS identifier LCB varDeclarations RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                          }  
                  | CLASS identifier LCB methodDeclarations RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                          }  
                  | CLASS identifier LCB varDeclarations methodDeclarations RCB {
                            $$ = new Node("ClassDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                            $$->children.push_back($5);
                          }   
    ;

varDeclarations: varDeclaration {
                            $$ = new Node("VarDeclarations", "", yylineno);
                            $$->children.push_back($1);
                          }  
                  | varDeclarations varDeclaration {
                            $$ = $1; 
                            $$->children.push_back($2);
                          } 
    ;
methodDeclarations: methodDeclaration {
                            $$ = new Node("methodDeclarations", "", yylineno);
                            $$->children.push_back($1);
                          }  
                  | methodDeclarations methodDeclaration {
                            $$ = $1; 
                            $$->children.push_back($2);
                          } 
    ;

varDeclaration: type identifier SEMICOLON { $$ = new Node("VarDeclaration", " ", yylineno); 
$$->children.push_back($1) ; 
$$->children.push_back($2) ;} 
    ;

methodDeclaration: PUBILC type identifier LP RP LCB body RCB {
                            $$ = new Node("methodDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            $$->children.push_back($7);
                          }  
                  | PUBILC type identifier LP parameters RP LCB body RCB  {
                            $$ = new Node("methodDeclaration", "", yylineno);
                            $$->children.push_back($2);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                            $$->children.push_back($8);
                          }  
    ;

parameters: parameter {
                $$ = new Node("Parameters", "", yylineno);
                $$->children.push_back($1);
              }
              | parameters COMMA parameter {
                $$ = new Node("Parameters", "", yylineno);
                $$=$1;
                $$->children.push_back($3);
              }
    ;

parameter: type identifier{
                            $$ = new Node("Parameter", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                          }
    ;

body: return {
                          $$ = new Node("Body", "", yylineno);
                          $$->children.push_back($1);
      }
      | StatementVars return {
                          $$=$1 ;
                          $$->children.push_back($2);
      }
    ;

return: RET expression SEMICOLON {
                          $$ = new Node("Return", "", yylineno) ;
                          $$->children.push_back($2) ;

    }
    ;

StatementVars: vs {
                    $$ = new Node("Body", "", yylineno) ;
                    $$->children.push_back($1);
              }
              | StatementVars vs {
                    $$=$1 ;
                    $$->children.push_back($2) ;
              }
    ;

vs: varDeclaration { $$ = $1 ;} | statement {$$ = $1;} ;

type: BOOLDEF  { $$ = new Node("Type", $1, yylineno) ; } | INTDEF  { $$ = new Node("Type", $1, yylineno) ; } | IDENTIFIER { $$ = new Node("Type", $1, yylineno) ; } | INTDEF LB RB  { $$ = new Node("Type", $1 + $2 + $3, yylineno) ; } 
/* type: BOOLDEF  {$$ = $1;} | INTDEF  {$$ = $1;} | IDENTIFIER{$$ = $1;} | INTDEF LB RB  {$$ = $1 + $2 + $3;}  */
    ;

statement: LCB RCB {
                            $$ = new Node("EmptyStatement", "", yylineno);
                          } 
            | LCB stmtArgumentlist RCB {
                              $$ = $2 ;
                          } 
            | IF LP expression RP ifStatement {
                            $$ = new Node("IF", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                          } 
            | IF LP expression RP ifStatement ELSE elseStatement {
                            $$ = new Node("IF ELSE", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                            $$->children.push_back($7);
                          } 
            | WHILE LP expression RP ifStatement {
                            $$ = new Node("While", "", yylineno);
                            $$->children.push_back($3);
                            $$->children.push_back($5);
                          } 
            | SOPL LP expression RP SEMICOLON {
                            $$ = new Node("Print", "", yylineno);
                            $$->children.push_back($3);
                          } 
            | identifier ASSIGN expression SEMICOLON {
                            $$ = new Node("Assignment", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          } 
            | identifier index ASSIGN expression SEMICOLON {
                            $$ = new Node("Assignment", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            $$->children.push_back($4);
                          } 
    ;

ifStatement: statement {
                            $$ = new Node("TrueBranch", "", yylineno);
                            $$->children.push_back($1);
                          } ;

elseStatement : statement {
                            $$ = new Node("FalseBranch", "", yylineno);
                            $$->children.push_back($1);
                          } ;

stmtArgumentlist: statement {
                            $$ = new Node("Statements", "", yylineno);
                            $$->children.push_back($1);
                          } 
            | stmtArgumentlist statement {
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
                          }
            | expression MINUSOP expression {
                            $$ = new Node("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression MULTOP expression {
                            $$ = new Node("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression ANDOP expression {
                            $$ = new Node("AndExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression OROP expression {
                            $$ = new Node("OrExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression LTOP expression {
                            $$ = new Node("LessThanExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression GTOP expression {
                            $$ = new Node("GreaterThanExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression EQUOP expression {
                            $$ = new Node("EqualExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression DIVOP expression {
                            $$ = new Node("DivisionExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression index {
                            $$ = new Node("Expression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                          }
            | expression DOT LEN {
                            $$ = new Node("LenExpression", "", yylineno);
                            $$->children.push_back($1);
                          }
            | expression DOT extendedFunc {
                            $$ = new Node("MethodCall", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          } 
            | NEW INTDEF index {
                            $$ = new Node("New Int", "", yylineno);
                            $$->children.push_back($3);
                          }
            | NEW identifier LP RP {
                            $$ = new Node("New", "", yylineno);
                            $$->children.push_back($2);
                          }
            | EXM expression { 
                            $$ = new Node("NotExpression", "", yylineno); 
                            $$->children.push_back($2);
                          }
            | factor      {$$ = $1; /* printf("r4 ");*/}
            | varDeclaration {$$ = $1;}
            ;

extendedFunc: identifier LP  RP {
                            $$ = new Node(".function", "", yylineno);
                            $$->children.push_back($1);
                  }
                  | identifier LP argumentlist RP{
                            $$ = new Node(".function", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                  }
    ;

index : LB expression RB {
                  $$ = new Node("Index", "", yylineno); 
                  $$->children.push_back($2);
                  } 
    ;

argumentlist: expression {
                            $$ = new Node("Arguments", "", yylineno);
                            $$->children.push_back($1);
                          } 
            | argumentlist COMMA expression {
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
