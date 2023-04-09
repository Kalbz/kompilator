// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 12 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
  

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 126 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 48: // root
      case 49: // expressionList
      case 50: // expression
      case 51: // Type
      case 52: // ParameterList
      case 53: // VarDeclaration
      case 54: // BothVarAndStatement
      case 55: // MethodDeclaration
      case 56: // MethodDeclarationList
      case 57: // VarDeclarationList
      case 58: // statementList
      case 59: // elseStatement
      case 60: // statement
      case 61: // ClassDeclaration
      case 62: // MainClass
      case 63: // ClassDeclarationList
      case 64: // MainClassList
      case 65: // NonEmptyMainClassList
      case 66: // Goal
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // CLASS
      case 10: // EXTENDS
      case 11: // PUBLIC
      case 12: // STATIC
      case 13: // VOID
      case 14: // INT_KEYWORD
      case 15: // BOOLEAN
      case 16: // IF
      case 17: // ELSE
      case 18: // WHILE
      case 19: // RETURN
      case 20: // TRUE
      case 21: // FALSE
      case 22: // THIS
      case 23: // NEW
      case 24: // LENGTH
      case 25: // PRINTLN
      case 26: // STRINGLITERAL
      case 27: // IDENTIFIER
      case 28: // LCB
      case 29: // RCB
      case 30: // LB
      case 31: // RB
      case 32: // ASSIGNOP
      case 33: // SEMICOLON
      case 34: // COMMA
      case 35: // DOT
      case 36: // ANDOP
      case 37: // EQOP
      case 38: // NEOP
      case 39: // OROP
      case 40: // DIVOP
      case 41: // MODOP
      case 42: // NOTOP
      case 43: // LCHEV
      case 44: // RCHEV
      case 45: // STRING_KEYWORD
      case 46: // MAIN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 48: // root
      case 49: // expressionList
      case 50: // expression
      case 51: // Type
      case 52: // ParameterList
      case 53: // VarDeclaration
      case 54: // BothVarAndStatement
      case 55: // MethodDeclaration
      case 56: // MethodDeclarationList
      case 57: // VarDeclarationList
      case 58: // statementList
      case 59: // elseStatement
      case 60: // statement
      case 61: // ClassDeclaration
      case 62: // MainClass
      case 63: // ClassDeclarationList
      case 64: // MainClassList
      case 65: // NonEmptyMainClassList
      case 66: // Goal
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // CLASS
      case 10: // EXTENDS
      case 11: // PUBLIC
      case 12: // STATIC
      case 13: // VOID
      case 14: // INT_KEYWORD
      case 15: // BOOLEAN
      case 16: // IF
      case 17: // ELSE
      case 18: // WHILE
      case 19: // RETURN
      case 20: // TRUE
      case 21: // FALSE
      case 22: // THIS
      case 23: // NEW
      case 24: // LENGTH
      case 25: // PRINTLN
      case 26: // STRINGLITERAL
      case 27: // IDENTIFIER
      case 28: // LCB
      case 29: // RCB
      case 30: // LB
      case 31: // RB
      case 32: // ASSIGNOP
      case 33: // SEMICOLON
      case 34: // COMMA
      case 35: // DOT
      case 36: // ANDOP
      case 37: // EQOP
      case 38: // NEOP
      case 39: // OROP
      case 40: // DIVOP
      case 41: // MODOP
      case 42: // NOTOP
      case 43: // LCHEV
      case 44: // RCHEV
      case 45: // STRING_KEYWORD
      case 46: // MAIN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 48: // root
      case 49: // expressionList
      case 50: // expression
      case 51: // Type
      case 52: // ParameterList
      case 53: // VarDeclaration
      case 54: // BothVarAndStatement
      case 55: // MethodDeclaration
      case 56: // MethodDeclarationList
      case 57: // VarDeclarationList
      case 58: // statementList
      case 59: // elseStatement
      case 60: // statement
      case 61: // ClassDeclaration
      case 62: // MainClass
      case 63: // ClassDeclarationList
      case 64: // MainClassList
      case 65: // NonEmptyMainClassList
      case 66: // Goal
        value.copy< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // CLASS
      case 10: // EXTENDS
      case 11: // PUBLIC
      case 12: // STATIC
      case 13: // VOID
      case 14: // INT_KEYWORD
      case 15: // BOOLEAN
      case 16: // IF
      case 17: // ELSE
      case 18: // WHILE
      case 19: // RETURN
      case 20: // TRUE
      case 21: // FALSE
      case 22: // THIS
      case 23: // NEW
      case 24: // LENGTH
      case 25: // PRINTLN
      case 26: // STRINGLITERAL
      case 27: // IDENTIFIER
      case 28: // LCB
      case 29: // RCB
      case 30: // LB
      case 31: // RB
      case 32: // ASSIGNOP
      case 33: // SEMICOLON
      case 34: // COMMA
      case 35: // DOT
      case 36: // ANDOP
      case 37: // EQOP
      case 38: // NEOP
      case 39: // OROP
      case 40: // DIVOP
      case 41: // MODOP
      case 42: // NOTOP
      case 43: // LCHEV
      case 44: // RCHEV
      case 45: // STRING_KEYWORD
      case 46: // MAIN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 48: // root
      case 49: // expressionList
      case 50: // expression
      case 51: // Type
      case 52: // ParameterList
      case 53: // VarDeclaration
      case 54: // BothVarAndStatement
      case 55: // MethodDeclaration
      case 56: // MethodDeclarationList
      case 57: // VarDeclarationList
      case 58: // statementList
      case 59: // elseStatement
      case 60: // statement
      case 61: // ClassDeclaration
      case 62: // MainClass
      case 63: // ClassDeclarationList
      case 64: // MainClassList
      case 65: // NonEmptyMainClassList
      case 66: // Goal
        value.move< Node * > (that.value);
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // CLASS
      case 10: // EXTENDS
      case 11: // PUBLIC
      case 12: // STATIC
      case 13: // VOID
      case 14: // INT_KEYWORD
      case 15: // BOOLEAN
      case 16: // IF
      case 17: // ELSE
      case 18: // WHILE
      case 19: // RETURN
      case 20: // TRUE
      case 21: // FALSE
      case 22: // THIS
      case 23: // NEW
      case 24: // LENGTH
      case 25: // PRINTLN
      case 26: // STRINGLITERAL
      case 27: // IDENTIFIER
      case 28: // LCB
      case 29: // RCB
      case 30: // LB
      case 31: // RB
      case 32: // ASSIGNOP
      case 33: // SEMICOLON
      case 34: // COMMA
      case 35: // DOT
      case 36: // ANDOP
      case 37: // EQOP
      case 38: // NEOP
      case 39: // OROP
      case 40: // DIVOP
      case 41: // MODOP
      case 42: // NOTOP
      case 43: // LCHEV
      case 44: // RCHEV
      case 45: // STRING_KEYWORD
      case 46: // MAIN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 48: // root
      case 49: // expressionList
      case 50: // expression
      case 51: // Type
      case 52: // ParameterList
      case 53: // VarDeclaration
      case 54: // BothVarAndStatement
      case 55: // MethodDeclaration
      case 56: // MethodDeclarationList
      case 57: // VarDeclarationList
      case 58: // statementList
      case 59: // elseStatement
      case 60: // statement
      case 61: // ClassDeclaration
      case 62: // MainClass
      case 63: // ClassDeclarationList
      case 64: // MainClassList
      case 65: // NonEmptyMainClassList
      case 66: // Goal
        yylhs.value.emplace< Node * > ();
        break;

      case 3: // PLUSOP
      case 4: // MINUSOP
      case 5: // MULTOP
      case 6: // INT
      case 7: // LP
      case 8: // RP
      case 9: // CLASS
      case 10: // EXTENDS
      case 11: // PUBLIC
      case 12: // STATIC
      case 13: // VOID
      case 14: // INT_KEYWORD
      case 15: // BOOLEAN
      case 16: // IF
      case 17: // ELSE
      case 18: // WHILE
      case 19: // RETURN
      case 20: // TRUE
      case 21: // FALSE
      case 22: // THIS
      case 23: // NEW
      case 24: // LENGTH
      case 25: // PRINTLN
      case 26: // STRINGLITERAL
      case 27: // IDENTIFIER
      case 28: // LCB
      case 29: // RCB
      case 30: // LB
      case 31: // RB
      case 32: // ASSIGNOP
      case 33: // SEMICOLON
      case 34: // COMMA
      case 35: // DOT
      case 36: // ANDOP
      case 37: // EQOP
      case 38: // NEOP
      case 39: // OROP
      case 40: // DIVOP
      case 41: // MODOP
      case 42: // NOTOP
      case 43: // LCHEV
      case 44: // RCHEV
      case 45: // STRING_KEYWORD
      case 46: // MAIN
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 41 "parser.yy"
                 {root = yystack_[0].value.as < Node * > ();}
#line 885 "parser.tab.cc"
    break;

  case 3:
#line 45 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("EmptyExpressionList", "", yylineno); }
#line 891 "parser.tab.cc"
    break;

  case 4:
#line 46 "parser.yy"
                                                { yylhs.value.as < Node * > () = new Node("NonEmptyExpressionList", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 897 "parser.tab.cc"
    break;

  case 5:
#line 48 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);  }
#line 903 "parser.tab.cc"
    break;

  case 6:
#line 52 "parser.yy"
                                         {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r1 "); */
                          }
#line 918 "parser.tab.cc"
    break;

  case 7:
#line 62 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 929 "parser.tab.cc"
    break;

  case 8:
#line 68 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 940 "parser.tab.cc"
    break;

  case 9:
#line 74 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 950 "parser.tab.cc"
    break;

  case 10:
#line 79 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("AndOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 960 "parser.tab.cc"
    break;

  case 11:
#line 84 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("OrOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 970 "parser.tab.cc"
    break;

  case 12:
#line 89 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("LChevExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 980 "parser.tab.cc"
    break;

  case 13:
#line 94 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("RChevExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 990 "parser.tab.cc"
    break;

  case 14:
#line 99 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("EqOpExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1000 "parser.tab.cc"
    break;

  case 15:
#line 104 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("ExpressionLBExpressionRB", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1010 "parser.tab.cc"
    break;

  case 16:
#line 109 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("ExpressionDotLength", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1019 "parser.tab.cc"
    break;

  case 17:
#line 114 "parser.yy"
                                                             {
                            yylhs.value.as < Node * > () = new Node("MethodInvocation", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ()); 

                            Node* identifierNode = new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno); 
                            yylhs.value.as < Node * > ()->children.push_back(identifierNode); 

                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); 
            }
#line 1033 "parser.tab.cc"
    break;

  case 18:
#line 123 "parser.yy"
                  {
                            yylhs.value.as < Node * > () = new Node("Int", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Int", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1042 "parser.tab.cc"
    break;

  case 19:
#line 127 "parser.yy"
                   {
                            yylhs.value.as < Node * > () = new Node("TRUE", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("True", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1051 "parser.tab.cc"
    break;

  case 20:
#line 131 "parser.yy"
                    {
                            yylhs.value.as < Node * > () = new Node("FALSE", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("False", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1060 "parser.tab.cc"
    break;

  case 21:
#line 135 "parser.yy"
                         {
                            yylhs.value.as < Node * > () = new Node("IDENTIFIER", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("IDENTIFIER", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1069 "parser.tab.cc"
    break;

  case 22:
#line 139 "parser.yy"
                   {
                            yylhs.value.as < Node * > () = new Node("THIS", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("This", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1078 "parser.tab.cc"
    break;

  case 23:
#line 143 "parser.yy"
                                               {
                            yylhs.value.as < Node * > () = new Node("NewIntExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1087 "parser.tab.cc"
    break;

  case 24:
#line 147 "parser.yy"
                                  {
                            yylhs.value.as < Node * > () = new Node("NewIdentifierExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[2].value.as < std::string > (), yylineno));
            }
#line 1096 "parser.tab.cc"
    break;

  case 25:
#line 151 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1105 "parser.tab.cc"
    break;

  case 26:
#line 155 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("LPExpressionRP", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1114 "parser.tab.cc"
    break;

  case 27:
#line 162 "parser.yy"
                        {
                            yylhs.value.as < Node * > () = new Node("IntLBRB", "", yylineno);
            }
#line 1122 "parser.tab.cc"
    break;

  case 28:
#line 165 "parser.yy"
                      {
                            yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno);
            }
#line 1130 "parser.tab.cc"
    break;

  case 29:
#line 168 "parser.yy"
                          {
                            yylhs.value.as < Node * > () = new Node("Int", "", yylineno);
            }
#line 1138 "parser.tab.cc"
    break;

  case 30:
#line 171 "parser.yy"
                         {
                            yylhs.value.as < Node * > () = new Node("Identifier", "", yylineno);
            }
#line 1146 "parser.tab.cc"
    break;

  case 31:
#line 176 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("IDENTIFIER", yystack_[0].value.as < std::string > (), yylineno));
            }
#line 1155 "parser.tab.cc"
    break;

  case 32:
#line 180 "parser.yy"
                                                  {
                            yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("IDENTIFIER", yystack_[2].value.as < std::string > (), yylineno));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1165 "parser.tab.cc"
    break;

  case 33:
#line 185 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("EmptyParameterList", "", yylineno); }
#line 1171 "parser.tab.cc"
    break;

  case 34:
#line 189 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[1].value.as < std::string > (), yylineno));
                            
            }
#line 1181 "parser.tab.cc"
    break;

  case 35:
#line 196 "parser.yy"
                                    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1187 "parser.tab.cc"
    break;

  case 36:
#line 197 "parser.yy"
                        { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1193 "parser.tab.cc"
    break;

  case 37:
#line 198 "parser.yy"
                                                 { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1199 "parser.tab.cc"
    break;

  case 38:
#line 199 "parser.yy"
                                            { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1205 "parser.tab.cc"
    break;

  case 39:
#line 205 "parser.yy"
                                                                                                                      {
                            yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[9].value.as < std::string > (), yylineno));
 
            }
#line 1215 "parser.tab.cc"
    break;

  case 40:
#line 210 "parser.yy"
                                                                                                           {
                            yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[9].value.as < std::string > (), yylineno));
            }
#line 1224 "parser.tab.cc"
    break;

  case 41:
#line 214 "parser.yy"
                                                                                                                {
                            yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[9].value.as < std::string > (), yylineno));
            }
#line 1233 "parser.tab.cc"
    break;

  case 42:
#line 223 "parser.yy"
                                         { yylhs.value.as < Node * > () = new Node("EmptyMethodDeclarationList", "", yylineno); }
#line 1239 "parser.tab.cc"
    break;

  case 43:
#line 224 "parser.yy"
                                                                { yylhs.value.as < Node * > () = new Node("MethodDeclarationList", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1245 "parser.tab.cc"
    break;

  case 44:
#line 229 "parser.yy"
                                   { yylhs.value.as < Node * > () = new Node("EmptyDeclarationList", "", yylineno); 
                                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                                }
#line 1253 "parser.tab.cc"
    break;

  case 45:
#line 232 "parser.yy"
                                                  { yylhs.value.as < Node * > () = new Node("VarDeclarationList", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1259 "parser.tab.cc"
    break;

  case 46:
#line 237 "parser.yy"
                                       {
                            yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1269 "parser.tab.cc"
    break;

  case 47:
#line 242 "parser.yy"
                        { yylhs.value.as < Node * > () = new Node("EmptyStatementList", "", yylineno); }
#line 1275 "parser.tab.cc"
    break;

  case 48:
#line 244 "parser.yy"
                              {
                            yylhs.value.as < Node * > () = new Node("ElseStatement", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1284 "parser.tab.cc"
    break;

  case 49:
#line 248 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("EmptyElseStatement", "", yylineno); }
#line 1290 "parser.tab.cc"
    break;

  case 50:
#line 251 "parser.yy"
                                 {
                            yylhs.value.as < Node * > () = new Node("LCBStatementListRCB", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1299 "parser.tab.cc"
    break;

  case 51:
#line 255 "parser.yy"
                                                          {
                            yylhs.value.as < Node * > () = new Node("IfLPExpressionRPStatement", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1309 "parser.tab.cc"
    break;

  case 52:
#line 260 "parser.yy"
                                               {
                            yylhs.value.as < Node * > () = new Node("WhileLPExpressionRPStatement", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1319 "parser.tab.cc"
    break;

  case 53:
#line 265 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node("SystemOutPrintlnLPExpressionRP", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1328 "parser.tab.cc"
    break;

  case 54:
#line 269 "parser.yy"
                                                       {
                            yylhs.value.as < Node * > () = new Node("IdentifierEqualExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1338 "parser.tab.cc"
    break;

  case 55:
#line 274 "parser.yy"
                                                                        {
                            yylhs.value.as < Node * > () = new Node("Identifier2EqualExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier2", yystack_[6].value.as < std::string > (), yylineno));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            }
#line 1348 "parser.tab.cc"
    break;

  case 56:
#line 282 "parser.yy"
                                                                                    {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);

            }
#line 1357 "parser.tab.cc"
    break;

  case 57:
#line 286 "parser.yy"
                                                             {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);

            }
#line 1366 "parser.tab.cc"
    break;

  case 58:
#line 290 "parser.yy"
                                                                                                   {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);

            }
#line 1375 "parser.tab.cc"
    break;

  case 59:
#line 294 "parser.yy"
                                                                                {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);

            }
#line 1384 "parser.tab.cc"
    break;

  case 60:
#line 300 "parser.yy"
                                                                                                                           {
                            yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[15].value.as < std::string > (), yylineno));
                            yylhs.value.as < Node * > ()->children.push_back(new Node("Identifier", yystack_[5].value.as < std::string > (), yylineno));
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1395 "parser.tab.cc"
    break;

  case 61:
#line 308 "parser.yy"
                                                            { yylhs.value.as < Node * > () = new Node("EmptyClassDeclarationList", "", yylineno);
                                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                                            }
#line 1404 "parser.tab.cc"
    break;

  case 62:
#line 312 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
 }
#line 1411 "parser.tab.cc"
    break;

  case 63:
#line 318 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("EmptyMainClassList", "", yylineno); }
#line 1417 "parser.tab.cc"
    break;

  case 64:
#line 319 "parser.yy"
                                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1423 "parser.tab.cc"
    break;

  case 65:
#line 322 "parser.yy"
                                 {
                          yylhs.value.as < Node * > () = new Node("NonEmptyMainClassList", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1432 "parser.tab.cc"
    break;

  case 66:
#line 326 "parser.yy"
                                                      {
                        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                      }
#line 1441 "parser.tab.cc"
    break;

  case 67:
#line 332 "parser.yy"
                                             {
                          yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1451 "parser.tab.cc"
    break;


#line 1455 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -71;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -8,     4,    25,   -71,    23,    -8,   -71,    17,   -71,    34,
      23,    57,   -71,    56,     0,   -71,   -71,    79,    62,    67,
      89,    82,    78,    65,   -71,   -71,    77,   -71,   -71,     7,
      67,    93,    67,    87,    86,    88,   -71,   -71,   -71,     8,
      90,    11,    67,   121,   -71,   -71,   -71,   125,   -71,    42,
      78,    97,   -71,   108,   138,   119,   116,   127,   128,    78,
     195,   131,   -71,   153,   154,   155,    53,   262,   -71,   129,
     258,   149,   262,   159,   388,   388,   388,   388,   388,    53,
     141,   262,   388,   -71,   -71,   388,   388,   -71,   146,   -71,
     388,   -71,   -71,   -71,    45,   -71,   388,    30,    72,    83,
      94,   136,   -71,   148,   160,   202,   262,   213,   147,   175,
     249,   388,   388,   388,   262,   388,    76,   388,   388,   388,
     388,   388,   388,   262,   156,   162,   -71,   157,   169,   172,
     173,   -71,   388,   200,   325,   325,   249,   197,   224,   -71,
     205,   342,   331,   331,   249,   353,   353,   -71,   -71,   388,
     -71,   -71,   -71,   186,   266,   -71,   262,   -71,   -71,   388,
     278,   -71,   -71,   -71,   211,   289,   -71,   -71,   388,   -71
  };

  const signed char
  parser::yydefact_[] =
  {
      63,     0,     0,    65,    62,    64,     2,     0,     1,     0,
      62,     0,    66,     0,     0,    61,    67,     0,     0,     0,
       0,     0,     0,    29,    28,    30,     0,    44,    42,     0,
       0,     0,     0,     0,     0,     0,    57,    43,    45,     0,
       0,     0,     0,     0,    27,    34,    56,     0,    59,     0,
      33,     0,    58,     0,     0,     0,    31,     0,     0,    33,
      47,     0,    32,     0,     0,     0,    30,    47,    35,     0,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    37,    38,     0,     0,    46,     0,    18,
       0,    19,    20,    22,     0,    21,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,     0,
       0,    26,     0,     0,     6,     7,     8,    49,     0,    16,
       0,    10,    14,    11,     9,    12,    13,    52,    53,     0,
      39,    41,    40,     0,     0,    24,     0,    51,    15,     5,
       0,    60,    23,    48,     0,     3,    55,    17,     5,     4
  };

  const short
  parser::yypgoto_[] =
  {
     -71,   -71,    58,   -70,   -20,   165,    -5,   -71,   -18,    26,
     -31,   -43,   -71,   -60,   -71,   220,   221,   -71,   -71,   -71
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,   164,   165,    26,    54,    38,    69,    28,    29,
      30,    87,   157,    81,    10,     3,    11,     4,     5,     6
  };

  const unsigned char
  parser::yytable_[] =
  {
      72,    42,    33,     1,    97,    98,    99,   100,   101,    84,
      18,    37,   103,     7,    27,   104,   105,    71,    22,    22,
     107,    37,    22,    37,    80,     8,   110,    27,    19,    70,
      53,    37,     9,   111,   112,   113,    36,    46,   114,    53,
      48,   134,   135,   136,    13,   138,   130,   141,   142,   143,
     144,   145,   146,    22,   137,    68,    39,    16,    41,   108,
     115,    14,   154,   147,    83,   116,   117,   118,    49,   119,
     120,    52,   109,   121,   122,   111,   112,   113,    22,   160,
     123,    23,    24,    77,    17,    78,   111,   112,   113,    21,
      20,   124,    23,    24,    25,    34,   163,   111,   112,   113,
     139,    31,   115,   140,    35,    25,    40,   116,   117,   118,
      32,   119,   120,   115,    43,   121,   122,    44,   116,   117,
     118,    45,   119,   120,   115,   125,   121,   122,    50,   116,
     117,   118,    51,   119,   120,    56,    47,   121,   122,   111,
     112,   113,    55,    23,    24,    63,    57,    64,    82,    58,
      59,   111,   112,   113,    65,    60,    66,    67,    73,    61,
      74,    75,    76,   111,   112,   113,   115,    88,    86,   126,
     102,   116,   117,   118,   106,   119,   120,   132,   115,   121,
     122,   127,   133,   116,   117,   118,   150,   119,   120,   148,
     115,   121,   122,   128,   149,   116,   117,   118,   151,   119,
     120,   152,   153,   121,   122,   111,   112,   113,   155,    23,
      24,    63,   159,    64,   156,   161,   111,   112,   113,   167,
      65,   131,    66,    67,    62,    12,   169,   111,   112,   113,
       0,    15,   115,     0,     0,   129,     0,   116,   117,   118,
       0,   119,   120,   115,     0,   121,   122,     0,   116,   117,
     118,     0,   119,   120,   115,   158,   121,   122,     0,   116,
     117,   118,     0,   119,   120,     0,     0,   121,   122,   111,
     112,   113,    23,    24,     0,     0,     0,    85,    63,   115,
      64,   111,   112,   113,   116,    25,   118,    65,   119,    79,
      67,     0,   111,   112,   113,     0,   115,   162,     0,     0,
       0,   116,   117,   118,     0,   119,   120,     0,   115,   121,
     122,   166,     0,   116,   117,   118,     0,   119,   120,   115,
       0,   121,   122,   168,   116,   117,   118,     0,   119,   120,
     113,     0,   121,   122,   111,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,     0,     0,
       0,     0,     0,     0,     0,   115,   111,   112,   113,     0,
     116,   115,   118,     0,   119,   120,   116,   117,   118,     0,
     119,   120,   115,     0,   121,   122,     0,   116,     0,   118,
       0,   119,   120,   115,     0,   121,   122,     0,   116,     0,
     118,     0,   119,   120,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96
  };

  const short
  parser::yycheck_[] =
  {
      60,    32,    22,    11,    74,    75,    76,    77,    78,    69,
      10,    29,    82,     9,    19,    85,    86,    60,    11,    11,
      90,    39,    11,    41,    67,     0,    96,    32,    28,    60,
      50,    49,     9,     3,     4,     5,    29,    29,     8,    59,
      29,   111,   112,   113,    27,   115,   106,   117,   118,   119,
     120,   121,   122,    11,   114,    60,    30,     0,    32,    14,
      30,    27,   132,   123,    69,    35,    36,    37,    42,    39,
      40,    29,    27,    43,    44,     3,     4,     5,    11,   149,
       8,    14,    15,    30,    28,    32,     3,     4,     5,    27,
      11,     8,    14,    15,    27,    30,   156,     3,     4,     5,
      24,    12,    30,    27,    27,    27,    13,    35,    36,    37,
      28,    39,    40,    30,    27,    43,    44,    31,    35,    36,
      37,    33,    39,    40,    30,    31,    43,    44,     7,    35,
      36,    37,     7,    39,    40,    27,    46,    43,    44,     3,
       4,     5,    45,    14,    15,    16,     8,    18,    19,    30,
      34,     3,     4,     5,    25,    28,    27,    28,    27,    31,
       7,     7,     7,     3,     4,     5,    30,     8,    19,    33,
      29,    35,    36,    37,    28,    39,    40,    30,    30,    43,
      44,    33,     7,    35,    36,    37,    29,    39,    40,    33,
      30,    43,    44,    33,    32,    35,    36,    37,    29,    39,
      40,    29,    29,    43,    44,     3,     4,     5,     8,    14,
      15,    16,     7,    18,    17,    29,     3,     4,     5,     8,
      25,     8,    27,    28,    59,     5,   168,     3,     4,     5,
      -1,    10,    30,    -1,    -1,    33,    -1,    35,    36,    37,
      -1,    39,    40,    30,    -1,    43,    44,    -1,    35,    36,
      37,    -1,    39,    40,    30,    31,    43,    44,    -1,    35,
      36,    37,    -1,    39,    40,    -1,    -1,    43,    44,     3,
       4,     5,    14,    15,    -1,    -1,    -1,    19,    16,    30,
      18,     3,     4,     5,    35,    27,    37,    25,    39,    27,
      28,    -1,     3,     4,     5,    -1,    30,    31,    -1,    -1,
      -1,    35,    36,    37,    -1,    39,    40,    -1,    30,    43,
      44,    33,    -1,    35,    36,    37,    -1,    39,    40,    30,
      -1,    43,    44,    34,    35,    36,    37,    -1,    39,    40,
       5,    -1,    43,    44,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,     3,     4,     5,    -1,
      35,    30,    37,    -1,    39,    40,    35,    36,    37,    -1,
      39,    40,    30,    -1,    43,    44,    -1,    35,    -1,    37,
      -1,    39,    40,    30,    -1,    43,    44,    -1,    35,    -1,
      37,    -1,    39,    40,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    11,    48,    62,    64,    65,    66,     9,     0,     9,
      61,    63,    62,    27,    27,    63,     0,    28,    10,    28,
      11,    27,    11,    14,    15,    27,    51,    53,    55,    56,
      57,    12,    28,    51,    30,    27,    29,    55,    53,    56,
      13,    56,    57,    27,    31,    33,    29,    46,    29,    56,
       7,     7,    29,    51,    52,    45,    27,     8,    30,    34,
      28,    31,    52,    16,    18,    25,    27,    28,    53,    54,
      57,    58,    60,    27,     7,     7,     7,    30,    32,    27,
      58,    60,    19,    53,    60,    19,    19,    58,     8,     6,
       7,    20,    21,    22,    23,    27,    42,    50,    50,    50,
      50,    50,    29,    50,    50,    50,    28,    50,    14,    27,
      50,     3,     4,     5,     8,    30,    35,    36,    37,    39,
      40,    43,    44,     8,     8,    31,    33,    33,    33,    33,
      60,     8,    30,     7,    50,    50,    50,    60,    50,    24,
      27,    50,    50,    50,    50,    50,    50,    60,    33,    32,
      29,    29,    29,    29,    50,     8,    17,    59,    31,     7,
      50,    29,    31,    60,    49,    50,    33,     8,    34,    49
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    53,    54,    54,    54,    54,    55,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     3,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     6,     1,     1,
       1,     1,     1,     5,     4,     2,     3,     3,     1,     1,
       1,     2,     4,     0,     3,     1,     1,     2,     2,    12,
      12,    12,     1,     2,     1,     2,     2,     0,     2,     0,
       3,     6,     5,     5,     4,     7,     6,     5,     8,     7,
      18,     2,     0,     0,     1,     1,     2,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "PLUSOP", "MINUSOP", "MULTOP",
  "INT", "LP", "RP", "CLASS", "EXTENDS", "PUBLIC", "STATIC", "VOID",
  "INT_KEYWORD", "BOOLEAN", "IF", "ELSE", "WHILE", "RETURN", "TRUE",
  "FALSE", "THIS", "NEW", "LENGTH", "PRINTLN", "STRINGLITERAL",
  "IDENTIFIER", "LCB", "RCB", "LB", "RB", "ASSIGNOP", "SEMICOLON", "COMMA",
  "DOT", "ANDOP", "EQOP", "NEOP", "OROP", "DIVOP", "MODOP", "NOTOP",
  "LCHEV", "RCHEV", "STRING_KEYWORD", "MAIN", "$accept", "root",
  "expressionList", "expression", "Type", "ParameterList",
  "VarDeclaration", "BothVarAndStatement", "MethodDeclaration",
  "MethodDeclarationList", "VarDeclarationList", "statementList",
  "elseStatement", "statement", "ClassDeclaration", "MainClass",
  "ClassDeclarationList", "MainClassList", "NonEmptyMainClassList", "Goal", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    41,    41,    45,    46,    48,    52,    62,    68,    74,
      79,    84,    89,    94,    99,   104,   109,   114,   123,   127,
     131,   135,   139,   143,   147,   151,   155,   162,   165,   168,
     171,   176,   180,   185,   189,   196,   197,   198,   199,   205,
     210,   214,   223,   224,   229,   232,   237,   242,   244,   248,
     251,   255,   260,   265,   269,   274,   282,   286,   290,   294,
     300,   308,   312,   318,   319,   322,   326,   332
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1993 "parser.tab.cc"

