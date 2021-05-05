#ifndef XPathGrammarH
#define XPathGrammarH
/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_XPATHYY_GEN_BLINK_CORE_XPATHGRAMMAR_HPP_INCLUDED
#define YY_XPATHYY_GEN_BLINK_CORE_XPATHGRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
extern int xpathyydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype {
    MULOP = 258,
    EQOP = 259,
    RELOP = 260,
    PLUS = 261,
    MINUS = 262,
    OR = 263,
    AND = 264,
    AXISNAME = 265,
    NODETYPE = 266,
    PI = 267,
    FUNCTIONNAME = 268,
    LITERAL = 269,
    VARIABLEREFERENCE = 270,
    NUMBER = 271,
    DOTDOT = 272,
    SLASHSLASH = 273,
    NAMETEST = 274,
    XPATH_ERROR = 275
};
#endif

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE {
#line 61 "../../third_party/WebKit/Source/core/xml/XPathGrammar.y" /* yacc.c:1909  */

    blink::XPath::Step::Axis axis;
    blink::XPath::Step::NodeTest* nodeTest;
    blink::XPath::NumericOp::Opcode numop;
    blink::XPath::EqTestOp::Opcode eqop;
    String* str;
    blink::XPath::Expression* expr;
    blink::HeapVector<blink::Member<blink::XPath::Predicate>>* predList;
    blink::HeapVector<blink::Member<blink::XPath::Expression>>* argList;
    blink::XPath::Step* step;
    blink::XPath::LocationPath* locationPath;

#line 88 "gen/blink/core/XPathGrammar.hpp" /* yacc.c:1909  */
};
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

int xpathyyparse(blink::XPath::Parser* parser);

#endif /* !YY_XPATHYY_GEN_BLINK_CORE_XPATHGRAMMAR_HPP_INCLUDED  */

#endif
