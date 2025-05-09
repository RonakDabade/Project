
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     NUMBER = 259,
     CREATE = 260,
     DELETE = 261,
     FILE_TOKEN = 262,
     FUNCTION_TOKEN = 263,
     FOR = 264,
     LOOP = 265,
     UP = 266,
     TO = 267,
     WITH = 268,
     INCREMENT = 269,
     IN = 270,
     UP_TO = 271,
     IF = 272,
     ELSE = 273,
     SWITCH = 274,
     CASE = 275,
     DEFAULT = 276,
     BREAK = 277,
     COLON = 278,
     CONDITIONS = 279,
     ITERATE = 280,
     ARRAY = 281,
     USING = 282,
     INDEX = 283,
     FROM = 284,
     OPTIMIZE = 285,
     FUNCTIONS = 286,
     EQ = 287,
     NEQ = 288,
     LE = 289,
     GE = 290,
     LT = 291,
     GT = 292,
     CLOSE = 293,
     BRACE = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 33 ".\\file_operations.y"

    char* str;
    int num;
    char** str_array;



/* Line 1676 of yacc.c  */
#line 99 "file_operations.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


