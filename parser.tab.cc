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
      case 49: // root
      case 50: // Goal
      case 51: // ClassDeclarationList
      case 52: // MainClass
      case 53: // Methods
      case 54: // main
      case 55: // void
      case 56: // MainBody
      case 57: // Arg
      case 58: // ClassDeclaration
      case 59: // VarDeclarationList
      case 60: // MethodDeclarationList
      case 61: // VarDeclaration
      case 62: // MethodDeclaration
      case 63: // ParameterList
      case 64: // Parameter
      case 65: // body
      case 66: // return
      case 67: // StatementVars
      case 68: // vs
      case 69: // type
      case 70: // statement
      case 71: // IfStatement
      case 72: // ElseStatement
      case 73: // StatementList
      case 74: // expression
      case 75: // ExtendedFunc
      case 76: // Index
      case 77: // Argumentlist
      case 78: // factor
      case 79: // identifier
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
      case 49: // root
      case 50: // Goal
      case 51: // ClassDeclarationList
      case 52: // MainClass
      case 53: // Methods
      case 54: // main
      case 55: // void
      case 56: // MainBody
      case 57: // Arg
      case 58: // ClassDeclaration
      case 59: // VarDeclarationList
      case 60: // MethodDeclarationList
      case 61: // VarDeclaration
      case 62: // MethodDeclaration
      case 63: // ParameterList
      case 64: // Parameter
      case 65: // body
      case 66: // return
      case 67: // StatementVars
      case 68: // vs
      case 69: // type
      case 70: // statement
      case 71: // IfStatement
      case 72: // ElseStatement
      case 73: // StatementList
      case 74: // expression
      case 75: // ExtendedFunc
      case 76: // Index
      case 77: // Argumentlist
      case 78: // factor
      case 79: // identifier
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
      case 49: // root
      case 50: // Goal
      case 51: // ClassDeclarationList
      case 52: // MainClass
      case 53: // Methods
      case 54: // main
      case 55: // void
      case 56: // MainBody
      case 57: // Arg
      case 58: // ClassDeclaration
      case 59: // VarDeclarationList
      case 60: // MethodDeclarationList
      case 61: // VarDeclaration
      case 62: // MethodDeclaration
      case 63: // ParameterList
      case 64: // Parameter
      case 65: // body
      case 66: // return
      case 67: // StatementVars
      case 68: // vs
      case 69: // type
      case 70: // statement
      case 71: // IfStatement
      case 72: // ElseStatement
      case 73: // StatementList
      case 74: // expression
      case 75: // ExtendedFunc
      case 76: // Index
      case 77: // Argumentlist
      case 78: // factor
      case 79: // identifier
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
      case 49: // root
      case 50: // Goal
      case 51: // ClassDeclarationList
      case 52: // MainClass
      case 53: // Methods
      case 54: // main
      case 55: // void
      case 56: // MainBody
      case 57: // Arg
      case 58: // ClassDeclaration
      case 59: // VarDeclarationList
      case 60: // MethodDeclarationList
      case 61: // VarDeclaration
      case 62: // MethodDeclaration
      case 63: // ParameterList
      case 64: // Parameter
      case 65: // body
      case 66: // return
      case 67: // StatementVars
      case 68: // vs
      case 69: // type
      case 70: // statement
      case 71: // IfStatement
      case 72: // ElseStatement
      case 73: // StatementList
      case 74: // expression
      case 75: // ExtendedFunc
      case 76: // Index
      case 77: // Argumentlist
      case 78: // factor
      case 79: // identifier
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
      case 49: // root
      case 50: // Goal
      case 51: // ClassDeclarationList
      case 52: // MainClass
      case 53: // Methods
      case 54: // main
      case 55: // void
      case 56: // MainBody
      case 57: // Arg
      case 58: // ClassDeclaration
      case 59: // VarDeclarationList
      case 60: // MethodDeclarationList
      case 61: // VarDeclaration
      case 62: // MethodDeclaration
      case 63: // ParameterList
      case 64: // Parameter
      case 65: // body
      case 66: // return
      case 67: // StatementVars
      case 68: // vs
      case 69: // type
      case 70: // statement
      case 71: // IfStatement
      case 72: // ElseStatement
      case 73: // StatementList
      case 74: // expression
      case 75: // ExtendedFunc
      case 76: // Index
      case 77: // Argumentlist
      case 78: // factor
      case 79: // identifier
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
#line 49 "parser.yy"
                 {root = yystack_[0].value.as < Node * > ();}
#line 945 "parser.tab.cc"
    break;

  case 3:
#line 52 "parser.yy"
                    {
                          yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 954 "parser.tab.cc"
    break;

  case 4:
#line 56 "parser.yy"
                                               {
                          yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 964 "parser.tab.cc"
    break;

  case 5:
#line 64 "parser.yy"
                                       {
                          yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

                          }
#line 974 "parser.tab.cc"
    break;

  case 6:
#line 69 "parser.yy"
                                                                  {
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); 
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 983 "parser.tab.cc"
    break;

  case 7:
#line 75 "parser.yy"
                                                   {
                            yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          }
#line 993 "parser.tab.cc"
    break;

  case 8:
#line 82 "parser.yy"
                                              {
                            yylhs.value.as < Node * > () = new Node("Method", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1005 "parser.tab.cc"
    break;

  case 9:
#line 91 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("Name", yystack_[0].value.as < std::string > (), yylineno); }
#line 1011 "parser.tab.cc"
    break;

  case 10:
#line 92 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno); }
#line 1017 "parser.tab.cc"
    break;

  case 11:
#line 95 "parser.yy"
                            {
                            yylhs.value.as < Node * > () = new Node("MainBody", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 1026 "parser.tab.cc"
    break;

  case 12:
#line 100 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("Argument", yystack_[4].value.as < std::string > () + yystack_[3].value.as < std::string > () + yystack_[2].value.as < std::string > (), yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          
}
#line 1036 "parser.tab.cc"
    break;

  case 13:
#line 107 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1045 "parser.tab.cc"
    break;

  case 14:
#line 111 "parser.yy"
                                                          {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1055 "parser.tab.cc"
    break;

  case 15:
#line 116 "parser.yy"
                                                             {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1065 "parser.tab.cc"
    break;

  case 16:
#line 121 "parser.yy"
                                                                                {
                            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1076 "parser.tab.cc"
    break;

  case 17:
#line 129 "parser.yy"
                                   { 
                                yylhs.value.as < Node * > () = new Node("VarDeclarationList", "", yylineno); 
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                                }
#line 1085 "parser.tab.cc"
    break;

  case 18:
#line 133 "parser.yy"
                                                  { 
                                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
              }
#line 1094 "parser.tab.cc"
    break;

  case 19:
#line 140 "parser.yy"
                                         { 
                                yylhs.value.as < Node * > () = new Node("MethodDeclarationList", "", yylineno); 
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 1103 "parser.tab.cc"
    break;

  case 20:
#line 144 "parser.yy"
                                                                { 
                                yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); 
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
                                }
#line 1112 "parser.tab.cc"
    break;

  case 21:
#line 149 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("VarDeclaration", " ", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            
            }
#line 1123 "parser.tab.cc"
    break;

  case 22:
#line 157 "parser.yy"
                                                             {
                            yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
 
            }
#line 1135 "parser.tab.cc"
    break;

  case 23:
#line 164 "parser.yy"
                                                                      {
                            yylhs.value.as < Node * > () = new Node("methodDeclaration", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                        }
#line 1147 "parser.tab.cc"
    break;

  case 24:
#line 176 "parser.yy"
                        {
                                yylhs.value.as < Node * > () = new Node("Parameters", "", yylineno);
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 1156 "parser.tab.cc"
    break;

  case 25:
#line 180 "parser.yy"
                                                                {
                                yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
                                yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > ();
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                                }
#line 1166 "parser.tab.cc"
    break;

  case 26:
#line 187 "parser.yy"
                          {
                                yylhs.value.as < Node * > () = new Node("Parameter", "", yylineno);
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());

}
#line 1177 "parser.tab.cc"
    break;

  case 27:
#line 195 "parser.yy"
             {
                          yylhs.value.as < Node * > () = new Node("Body", "", yylineno);
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1186 "parser.tab.cc"
    break;

  case 28:
#line 199 "parser.yy"
                             {
                          yylhs.value.as < Node * > ()=yystack_[1].value.as < Node * > () ;
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1195 "parser.tab.cc"
    break;

  case 29:
#line 205 "parser.yy"
                                    {
                          yylhs.value.as < Node * > () = new Node("Return", "", yylineno) ;
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()) ;

    }
#line 1205 "parser.tab.cc"
    break;

  case 30:
#line 213 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("Body", "", yylineno) ;
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 1214 "parser.tab.cc"
    break;

  case 31:
#line 217 "parser.yy"
                                 {
                    yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()) ;
              }
#line 1223 "parser.tab.cc"
    break;

  case 32:
#line 223 "parser.yy"
                   { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > () ;}
#line 1229 "parser.tab.cc"
    break;

  case 33:
#line 223 "parser.yy"
                                            {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1235 "parser.tab.cc"
    break;

  case 34:
#line 225 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno) ; }
#line 1241 "parser.tab.cc"
    break;

  case 35:
#line 225 "parser.yy"
                                                                        { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno) ; }
#line 1247 "parser.tab.cc"
    break;

  case 36:
#line 225 "parser.yy"
                                                                                                                               { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno) ; }
#line 1253 "parser.tab.cc"
    break;

  case 37:
#line 225 "parser.yy"
                                                                                                                                                                                              { yylhs.value.as < Node * > () = new Node("Type", yystack_[2].value.as < std::string > () + yystack_[1].value.as < std::string > () + yystack_[0].value.as < std::string > (), yylineno) ; }
#line 1259 "parser.tab.cc"
    break;

  case 38:
#line 230 "parser.yy"
                   {
                            yylhs.value.as < Node * > () = new Node("EmptyStateMentList", "", yylineno);
            }
#line 1267 "parser.tab.cc"
    break;

  case 39:
#line 233 "parser.yy"
                                                {
                              yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
                          }
#line 1275 "parser.tab.cc"
    break;

  case 40:
#line 238 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("IF", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1285 "parser.tab.cc"
    break;

  case 41:
#line 243 "parser.yy"
                                                                 {
                            yylhs.value.as < Node * > () = new Node("IF ELSE", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1296 "parser.tab.cc"
    break;

  case 42:
#line 249 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node("WHILE", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1306 "parser.tab.cc"
    break;

  case 43:
#line 254 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1315 "parser.tab.cc"
    break;

  case 44:
#line 258 "parser.yy"
                                                       {
                            yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1325 "parser.tab.cc"
    break;

  case 45:
#line 263 "parser.yy"
                                                             {
                            yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1336 "parser.tab.cc"
    break;

  case 46:
#line 271 "parser.yy"
                       {
                            yylhs.value.as < Node * > () = new Node("True", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1345 "parser.tab.cc"
    break;

  case 47:
#line 276 "parser.yy"
                         {
                            yylhs.value.as < Node * > () = new Node("False", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1354 "parser.tab.cc"
    break;

  case 48:
#line 282 "parser.yy"
                         {
                            yylhs.value.as < Node * > () = new Node("Statements", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1363 "parser.tab.cc"
    break;

  case 49:
#line 286 "parser.yy"
                                               {
                            yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); 
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1372 "parser.tab.cc"
    break;

  case 50:
#line 294 "parser.yy"
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
#line 1387 "parser.tab.cc"
    break;

  case 51:
#line 304 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r2 "); */
                          }
#line 1398 "parser.tab.cc"
    break;

  case 52:
#line 310 "parser.yy"
                                           {
                            yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                            /* printf("r3 "); */
                          }
#line 1409 "parser.tab.cc"
    break;

  case 53:
#line 316 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1419 "parser.tab.cc"
    break;

  case 54:
#line 321 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("AndOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1429 "parser.tab.cc"
    break;

  case 55:
#line 326 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("OrOPExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1439 "parser.tab.cc"
    break;

  case 56:
#line 331 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("LChevExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1449 "parser.tab.cc"
    break;

  case 57:
#line 336 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("RChevExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1459 "parser.tab.cc"
    break;

  case 58:
#line 341 "parser.yy"
                                         {
                            yylhs.value.as < Node * > () = new Node("EqOpExpression", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1469 "parser.tab.cc"
    break;

  case 59:
#line 346 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("ExpressionLBExpressionRB", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1479 "parser.tab.cc"
    break;

  case 60:
#line 351 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("ExpressionDotLength", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1488 "parser.tab.cc"
    break;

  case 61:
#line 356 "parser.yy"
                                          {
                            yylhs.value.as < Node * > () = new Node("Method Invocation", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1498 "parser.tab.cc"
    break;

  case 62:
#line 361 "parser.yy"
                                    {
                            yylhs.value.as < Node * > () = new Node("New Int", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1507 "parser.tab.cc"
    break;

  case 63:
#line 365 "parser.yy"
                                   {
                            yylhs.value.as < Node * > () = new Node("New", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1516 "parser.tab.cc"
    break;

  case 64:
#line 369 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node("Not Equal", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1525 "parser.tab.cc"
    break;

  case 65:
#line 373 "parser.yy"
                     {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); /* printf("r4 ");*/}
#line 1531 "parser.tab.cc"
    break;

  case 66:
#line 374 "parser.yy"
                             {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1537 "parser.tab.cc"
    break;

  case 67:
#line 377 "parser.yy"
                               {
                            yylhs.value.as < Node * > () = new Node(".function", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  }
#line 1546 "parser.tab.cc"
    break;

  case 68:
#line 381 "parser.yy"
                                                 {
                            yylhs.value.as < Node * > () = new Node(".function", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  }
#line 1556 "parser.tab.cc"
    break;

  case 69:
#line 388 "parser.yy"
                         {
                  yylhs.value.as < Node * > () = new Node("Index", "", yylineno); 
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  }
#line 1565 "parser.tab.cc"
    break;

  case 70:
#line 394 "parser.yy"
                         {
                            yylhs.value.as < Node * > () = new Node("Arguments", "", yylineno);
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1574 "parser.tab.cc"
    break;

  case 71:
#line 398 "parser.yy"
                                            {
                            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); 
                            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                          }
#line 1583 "parser.tab.cc"
    break;

  case 72:
#line 407 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); }
#line 1589 "parser.tab.cc"
    break;

  case 73:
#line 408 "parser.yy"
                          {  yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1595 "parser.tab.cc"
    break;

  case 74:
#line 409 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("True", yystack_[0].value.as < std::string > (), yylineno); }
#line 1601 "parser.tab.cc"
    break;

  case 75:
#line 410 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("False", yystack_[0].value.as < std::string > (), yylineno); }
#line 1607 "parser.tab.cc"
    break;

  case 76:
#line 411 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("This", yystack_[0].value.as < std::string > (), yylineno); }
#line 1613 "parser.tab.cc"
    break;

  case 77:
#line 412 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1619 "parser.tab.cc"
    break;

  case 78:
#line 415 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("ID/Name", yystack_[0].value.as < std::string > (), yylineno) ; }
#line 1625 "parser.tab.cc"
    break;


#line 1629 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -64;

  const signed char parser::yytable_ninf_ = -37;

  const short
  parser::yypact_[] =
  {
      11,    14,    34,   -64,    50,    19,   -64,   -64,    19,    70,
     -64,   -64,    26,    30,   -64,   -64,    49,   171,    53,    47,
      -2,    51,   -64,   -64,   -64,   181,     8,   -64,   -64,    19,
      72,   -64,    19,    60,   -64,    18,   -64,   -64,   -64,    59,
     -64,    58,    90,   -64,   -64,   -64,   -64,    99,     6,    63,
      82,    83,    -6,   -64,    19,    77,   297,   -64,   244,    85,
      -2,   -64,    89,   114,   123,   124,   351,   103,   -14,   343,
     106,   -64,   109,   -64,   244,   -64,   -64,   244,   -64,    19,
     343,   343,   343,   -64,   -64,   359,   -64,   343,   343,   107,
     -64,   343,   -64,   -64,   -64,    12,   343,   -64,    79,   -64,
     -64,   -64,   -64,   -64,   112,   135,   121,   132,   144,   -64,
     -64,   186,   198,   343,   210,   115,   137,    38,   343,   343,
     343,   -64,    62,   343,   343,   343,   343,   343,   343,   -64,
     -64,   -64,   297,   297,   113,   -64,   -64,   252,   -64,   -64,
     142,     1,     1,    38,   -64,   -64,   146,   316,   263,   274,
      38,     5,     5,   -64,   149,   -64,   -64,   -64,   -64,   320,
     297,   -64,   263,     9,   -64,   -64,   -64,   343,   263
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     3,     0,     0,
       5,    78,     0,     0,     4,     6,     0,     0,     0,     0,
       0,    35,    34,    36,    13,     0,     0,    17,    19,     0,
       0,     7,     0,     0,    14,     0,    18,    15,    20,     0,
      10,     0,     0,    37,    16,    21,     9,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     8,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    32,     0,    27,     0,    30,    33,     0,    25,     0,
       0,     0,     0,    38,    48,     0,    11,     0,     0,     0,
      72,     0,    74,    75,    76,     0,     0,    66,     0,    65,
      73,    22,    28,    31,     0,     0,     0,     0,     0,    39,
      49,     0,     0,     0,     0,     0,     0,    64,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,    59,
      23,    12,     0,     0,     0,    69,    44,     0,    77,    62,
       0,    50,    51,    52,    60,    61,     0,    54,    58,    55,
      53,    56,    57,    46,    40,    42,    43,    45,    63,     0,
       0,    67,    70,     0,    47,    41,    68,     0,    71
  };

  const short
  parser::yypgoto_[] =
  {
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     145,   -64,   134,   -10,    61,   -64,   110,    86,   104,   -64,
     119,   -16,   -55,    40,   -64,   -64,   -25,   -64,   -63,   -64,
     -64,    -5
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     9,     4,    19,    47,    41,    57,    50,
      10,    25,    26,    97,    28,    52,    53,    72,    73,    74,
      75,    29,    76,   154,   165,    85,    98,   145,   129,   163,
      99,   100
  };

  const short
  parser::yytable_[] =
  {
      12,    67,    59,    13,    32,    89,   120,    27,   118,   119,
     120,    84,    21,    22,    51,    36,    87,   166,    88,    20,
      21,    22,     1,     5,    39,    23,   115,    42,    60,    20,
     110,    87,    54,    23,     6,    87,   122,    37,   124,    11,
     122,   126,   124,   167,    54,   126,    11,    44,    71,    61,
       7,    68,   139,    68,    16,   106,   107,   108,    17,     8,
      18,    68,   111,   112,    71,    30,   114,    71,    87,    68,
      14,   117,    68,   122,   105,   124,    31,   153,   153,     8,
      68,    33,   118,   119,   120,    40,   144,    38,   137,    11,
     116,    43,    45,   141,   142,   143,    38,    48,   147,   148,
     149,   150,   151,   152,    46,   164,    49,    62,    55,    87,
      56,    58,   121,    77,   122,   123,   124,   146,   125,   126,
      79,    80,   127,   128,   118,   119,   120,    68,    68,   132,
      81,    82,    86,   -36,   162,   118,   119,   120,   101,   113,
     133,   130,   168,   131,   140,    87,   156,   118,   119,   120,
     158,    87,   134,   159,    15,    68,   122,   123,   124,    35,
     125,   126,    87,   104,   127,   128,   160,   122,   123,   124,
      78,   125,   126,   155,    87,   127,   128,     0,   102,   122,
     123,   124,    20,   125,   126,    21,    22,   127,   128,   118,
     119,   120,    20,   103,     0,    21,    22,     0,    23,     0,
      24,   118,   119,   120,     0,     0,     0,     0,    23,     0,
      34,     0,     0,   118,   119,   120,    87,   135,   138,     0,
       0,   122,   123,   124,     0,   125,   126,     0,    87,   127,
     128,   136,     0,   122,   123,   124,     0,   125,   126,     0,
      87,   127,   128,     0,     0,   122,   123,   124,     0,   125,
     126,     0,     0,   127,   128,   118,   119,   120,    21,    22,
      63,     0,    64,    69,     0,     0,   118,   119,   120,    65,
       0,    70,    66,     0,     0,     0,     0,   118,   119,   120,
       0,     0,    87,     0,     0,   157,     0,   122,   123,   124,
       0,   125,   126,    87,     0,   127,   128,     0,   122,   123,
     124,     0,   125,   126,    87,     0,   127,   128,     0,   122,
     123,   124,     0,    63,   126,    64,     0,   127,   128,   118,
     119,   120,    65,     0,    11,    66,    90,    91,   161,     0,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
      92,    93,    94,    95,     0,     0,    87,    70,     0,    90,
      91,   122,     0,   124,     0,     0,   126,    21,    22,   127,
     128,     0,    96,    92,    93,    94,    95,    63,     0,    64,
      70,     0,     0,     0,     0,    63,    65,    64,    11,    66,
      83,     0,     0,     0,    65,    96,    11,    66,   109
  };

  const short
  parser::yycheck_[] =
  {
       5,    56,     8,     8,    20,    68,     5,    17,     3,     4,
       5,    66,    14,    15,     8,    25,    30,     8,    32,    11,
      14,    15,    11,     9,    29,    27,    14,    32,    34,    11,
      85,    30,    48,    27,     0,    30,    35,    29,    37,    27,
      35,    40,    37,    34,    60,    40,    27,    29,    58,    54,
       0,    56,   115,    58,    28,    80,    81,    82,    28,     9,
      11,    66,    87,    88,    74,    12,    91,    77,    30,    74,
       0,    96,    77,    35,    79,    37,    29,   132,   133,     9,
      85,    30,     3,     4,     5,    13,    24,    26,   113,    27,
      95,    31,    33,   118,   119,   120,    35,     7,   123,   124,
     125,   126,   127,   128,    46,   160,     7,    30,    45,    30,
      28,    28,    33,    28,    35,    36,    37,   122,    39,    40,
      31,     7,    43,    44,     3,     4,     5,   132,   133,     8,
       7,     7,    29,    27,   159,     3,     4,     5,    29,    32,
       8,    29,   167,     8,     7,    30,    33,     3,     4,     5,
       8,    30,     8,     7,     9,   160,    35,    36,    37,    25,
      39,    40,    30,    77,    43,    44,    17,    35,    36,    37,
      60,    39,    40,   133,    30,    43,    44,    -1,    74,    35,
      36,    37,    11,    39,    40,    14,    15,    43,    44,     3,
       4,     5,    11,    74,    -1,    14,    15,    -1,    27,    -1,
      29,     3,     4,     5,    -1,    -1,    -1,    -1,    27,    -1,
      29,    -1,    -1,     3,     4,     5,    30,    31,     8,    -1,
      -1,    35,    36,    37,    -1,    39,    40,    -1,    30,    43,
      44,    33,    -1,    35,    36,    37,    -1,    39,    40,    -1,
      30,    43,    44,    -1,    -1,    35,    36,    37,    -1,    39,
      40,    -1,    -1,    43,    44,     3,     4,     5,    14,    15,
      16,    -1,    18,    19,    -1,    -1,     3,     4,     5,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    37,
      -1,    39,    40,    30,    -1,    43,    44,    -1,    35,    36,
      37,    -1,    39,    40,    30,    -1,    43,    44,    -1,    35,
      36,    37,    -1,    16,    40,    18,    -1,    43,    44,     3,
       4,     5,    25,    -1,    27,    28,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    30,    27,    -1,     6,
       7,    35,    -1,    37,    -1,    -1,    40,    14,    15,    43,
      44,    -1,    42,    20,    21,    22,    23,    16,    -1,    18,
      27,    -1,    -1,    -1,    -1,    16,    25,    18,    27,    28,
      29,    -1,    -1,    -1,    25,    42,    27,    28,    29
  };

  const signed char
  parser::yystos_[] =
  {
       0,    11,    49,    50,    52,     9,     0,     0,     9,    51,
      58,    27,    79,    79,     0,    58,    28,    28,    11,    53,
      11,    14,    15,    27,    29,    59,    60,    61,    62,    69,
      12,    29,    69,    30,    29,    60,    61,    29,    62,    79,
      13,    55,    79,    31,    29,    33,    46,    54,     7,     7,
      57,     8,    63,    64,    69,    45,    28,    56,    28,     8,
      34,    79,    30,    16,    18,    25,    28,    70,    79,    19,
      27,    61,    65,    66,    67,    68,    70,    28,    64,    31,
       7,     7,     7,    29,    70,    73,    29,    30,    32,    76,
       6,     7,    20,    21,    22,    23,    42,    61,    74,    78,
      79,    29,    66,    68,    65,    79,    74,    74,    74,    29,
      70,    74,    74,    32,    74,    14,    79,    74,     3,     4,
       5,    33,    35,    36,    37,    39,    40,    43,    44,    76,
      29,     8,     8,     8,     8,    31,    33,    74,     8,    76,
       7,    74,    74,    74,    24,    75,    79,    74,    74,    74,
      74,    74,    74,    70,    71,    71,    33,    33,     8,     7,
      17,     8,    74,    77,    70,    72,     8,    34,    74
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      55,    56,    57,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    62,    62,    63,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    79
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     1,     2,     6,     6,     1,
       1,     3,     6,     4,     5,     5,     6,     1,     2,     1,
       2,     3,     8,     9,     1,     3,     2,     1,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     3,     2,     3,
       5,     7,     5,     5,     4,     5,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     4,     2,     1,     1,     3,     4,     3,
       1,     3,     1,     1,     1,     1,     1,     3,     1
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
  "LCHEV", "RCHEV", "STRING_KEYWORD", "MAIN", "EQUOP", "$accept", "root",
  "Goal", "ClassDeclarationList", "MainClass", "Methods", "main", "void",
  "MainBody", "Arg", "ClassDeclaration", "VarDeclarationList",
  "MethodDeclarationList", "VarDeclaration", "MethodDeclaration",
  "ParameterList", "Parameter", "body", "return", "StatementVars", "vs",
  "type", "statement", "IfStatement", "ElseStatement", "StatementList",
  "expression", "ExtendedFunc", "Index", "Argumentlist", "factor",
  "identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    49,    49,    52,    56,    64,    69,    75,    82,    91,
      92,    95,   100,   107,   111,   116,   121,   129,   133,   140,
     144,   149,   157,   164,   176,   180,   187,   195,   199,   205,
     213,   217,   223,   223,   225,   225,   225,   225,   230,   233,
     238,   243,   249,   254,   258,   263,   271,   276,   282,   286,
     294,   304,   310,   316,   321,   326,   331,   336,   341,   346,
     351,   356,   361,   365,   369,   373,   374,   377,   381,   388,
     394,   398,   407,   408,   409,   410,   411,   412,   415
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
#line 2166 "parser.tab.cc"

