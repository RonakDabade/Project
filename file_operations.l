%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.tab.h"

extern YYSTYPE yylval;
%}

%%
[ \t\n]+        /* ignore whitespace */
"create"        return CREATE;
"delete"        return DELETE;
"file"          return FILE_TOKEN;
"function"      return FUNCTION_TOKEN;
"for"           return FOR;
"loop"          return LOOP;
"up"            return UP;
"to"            return TO;
"up to"         return UP_TO;
"with"          return WITH;
"increment"     return INCREMENT;
"in"            return IN;
"if"            return IF;
"else"          return ELSE;
"switch"        return SWITCH;
"functions"     return FUNCTIONS;
"case"          return CASE;
"default"       return DEFAULT;
"optimize"      return OPTIMIZE; 
"iterate"       return ITERATE;
"array"         return ARRAY;
"using"         return USING;
"index"         return INDEX;
"from"          return FROM;
"break"         return BREAK;
"close"         return CLOSE;
"brace"         return BRACE;
"conditions"     return CONDITIONS;
"equals"        return EQ;
"equal to"      return EQ;
"not equal to"  return NEQ;
"not equals"    return NEQ;
"less than or equal to" return LE;
"less or equal" return LE;
"greater than or equal to" return GE;
"greater or equal" return GE;
"less than"     return LT;
"greater than"  return GT;
":"             return COLON;
[a-zA-Z][a-zA-Z0-9_]*  { 
                    yylval.str = strdup(yytext); 
                    return IDENTIFIER; 
                }
[0-9]+          { 
                    yylval.num = atoi(yytext); 
                    return NUMBER; 
                }
.               /* ignore any other character */
%%

int yywrap() {
    return 1;
}