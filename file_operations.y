%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_create_file(const char *filename);
void generate_delete_file(const char *filename);
void generate_add_function(const char *funcname, const char *filename);
void generate_delete_function(const char *funcname, const char *filename);
void generate_for_loop(const char *var, int limit, int step, const char *filename);

extern int yylex();
extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%union {
    char* str;
    int num;
}

%token <str> IDENTIFIER
%token <num> NUMBER
%token CREATE DELETE FILE_TOKEN FUNCTION_TOKEN FOR LOOP UP TO WITH INCREMENT IN UP_TO

%%

command:
      CREATE FILE_TOKEN IDENTIFIER {
        generate_create_file($3);
        free($3);
      }
    | DELETE FILE_TOKEN IDENTIFIER {
        generate_delete_file($3);
        free($3);
      }
    | CREATE FUNCTION_TOKEN IDENTIFIER IN IDENTIFIER {
        generate_add_function($3, $5);
        free($3);
        free($5);
      }
    | DELETE FUNCTION_TOKEN IDENTIFIER IN IDENTIFIER {
        generate_delete_function($3, $5);
        free($3);
        free($5);
      }
    | CREATE FOR LOOP IDENTIFIER UP_TO NUMBER WITH INCREMENT NUMBER IN IDENTIFIER {
        generate_for_loop($4, $6, $9, $11); 
        free($4);  // free IDENTIFIER
        free($11); // free IDENTIFIER
      }
    ;

%%

void generate_create_file(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check = fopen(full_name, "r");
    if (check) {
        fclose(check);
        printf("File '%s' already exists.\n", full_name);
        return;
    }

    FILE *fp = fopen(full_name, "w");
    if (!fp) {
        perror("Create file error");
        return;
    }

    fprintf(fp, "#include <stdio.h>\n\nint main() {\n    return 0;\n}\n");
    fclose(fp);
    printf("File '%s' created.\n", full_name);
}

void generate_delete_file(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check = fopen(full_name, "r");
    if (!check) {
        printf("File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(check);

    if (remove(full_name) == 0)
        printf("File '%s' deleted.\n", full_name);
    else
        perror("Delete file error");
}

void generate_add_function(const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *check_fp = fopen(full_name, "r");
    if (!check_fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    char line[256];
    int exists = 0;

    while (fgets(line, sizeof(line), check_fp)) {
        if (strstr(line, funcname) && strstr(line, "void")) {
            exists = 1;
            break;
        }
    }
    fclose(check_fp);

    if (exists) {
        printf("Function '%s' already exists in %s.\n", funcname, full_name);
        return;
    }

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "\nvoid %s() {\n    // TODO: implement %s\n}\n", funcname, funcname);
    fclose(fp);
    printf("Function '%s' added to %s.\n", funcname, full_name);
}

void generate_delete_function(const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    FILE *temp = fopen("temp.c", "w");
    if (!temp) {
        fclose(fp);
        perror("Error creating temporary file");
        return;
    }

    char line[256];
    int found = 0, skip = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (!skip && strstr(line, funcname) && strstr(line, "void")) {
            found = 1;
            skip = 1;
            continue;
        }
        if (skip && strstr(line, "}")) {
            skip = 0;
            continue;
        }
        if (!skip) fputs(line, temp);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("temp.c");
        printf("Function '%s' not found in %s.\n", funcname, full_name);
        return;
    }

    remove(full_name);
    rename("temp.c", full_name);
    printf("Function '%s' deleted from %s.\n", funcname, full_name);
}

void generate_for_loop(const char *var, int limit, int step, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for loop");
        return;
    }

    fprintf(fp,
        "\nfor (int %s = 0; %s < %d; %s += %d) {\n    // TODO: Add logic\n}\n",
        var, var, limit, var, step
    );
    fclose(fp);
    printf("For loop with '%s' added to %s up to %d with step %d\n", var, full_name, limit, step);
}

int main() {
    FILE *fp = fopen("command.txt", "r");
    if (!fp) {
        perror("command.txt not found");
        return 1;
    }

    yyin = fp;
    yyparse();
    fclose(fp);
    return 0;
}
