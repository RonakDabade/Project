%{
#include "file_operations.tab.h"
#include <string.h>
%}

%%

create                  { return CREATE; }
delete                  { return DELETE; }
file                    { return FILE_TOKEN; }
function                { return FUNCTION_TOKEN; }
for                     { return FOR; }
loop                    { return LOOP; }
"up to"             { return UP_TO; }
with                    { return WITH; }
increment               { return INCREMENT; }
in                      { return IN; }
[0-9]+                  { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[ \t\n]+                ; // Ignore whitespace
.                       ; // Ignore unknown characters

%%

int yywrap(void) {
    return 1;  // End of input
}
