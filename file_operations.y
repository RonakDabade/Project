%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_create_file(const char *filename);
void generate_delete_file(const char *filename);
void generate_add_function(const char *funcname, const char *filename);
void generate_delete_function(const char *funcname, const char *filename);
void generate_for_loop(const char *var, int limit, int step, const char *funcname, const char *filename);
void generate_if_statement(const char *var, const char *op, int value, const char *funcname, const char *filename);
void generate_if_else_statement(const char *var, const char *op, int value, const char *funcname, const char *filename);
void generate_switch_statement(const char *var, int cases, const char *funcname, const char *filename);
void generate_case_statement(int value, const char *filename);
void generate_default_case(const char *filename);
void generate_break_statement(const char *filename);
void generate_close_brace(const char *filename);
int variable_exists_in_function(const char *var, const char *funcname, const char *filename);
void generate_array(const char *array_name, int start, int end, const char *funcname, const char *filename);
void generate_array_iteration(const char *array_name, const char *index_var, const char *funcname, const char *filename);
void optimize_code(const char *filename);



extern int yylex();
extern FILE *yyin;

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%union {
    char* str;
    int num;
    char** str_array;
}

%token <str> IDENTIFIER
%token <num> NUMBER
%token CREATE DELETE FILE_TOKEN FUNCTION_TOKEN FOR LOOP UP TO WITH INCREMENT IN UP_TO
%token IF ELSE SWITCH CASE DEFAULT BREAK COLON CONDITIONS ITERATE ARRAY USING INDEX FROM OPTIMIZE FUNCTIONS
%token EQ NEQ LE GE LT GT
%token CLOSE BRACE

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
    | CREATE FOR LOOP IDENTIFIER UP_TO NUMBER WITH INCREMENT NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_for_loop($4, $6, $9, $11, $13);
        free($4);
        free($11);
        free($13);
      }
     | OPTIMIZE FILE_TOKEN IDENTIFIER {
        optimize_code($3);
        free($3);
      }
    | CREATE IF IDENTIFIER EQ NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, "==", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER NEQ NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, "!=", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER LT NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, "<", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER GT NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, ">", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER LE NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, "<=", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER GE NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_if_statement($3, ">=", $5, $7, $9);
        free($3);
        free($7);
        free($9);
      }
    | CREATE IF IDENTIFIER EQ NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, "==", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE IF IDENTIFIER NEQ NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, "!=", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE IF IDENTIFIER LT NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, "<", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE IF IDENTIFIER GT NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, ">", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE IF IDENTIFIER LE NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, "<=", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE IF IDENTIFIER GE NUMBER ELSE IN IDENTIFIER IN IDENTIFIER {
        generate_if_else_statement($3, ">=", $5, $8, $10);
        free($3);
        free($8);
        free($10);
      }
    | CREATE SWITCH IDENTIFIER CONDITIONS WITH NUMBER CASE IN IDENTIFIER IN IDENTIFIER {
        generate_switch_statement($3, $6, $9, $11);
        free($3);
        free($9);
        free($11);
      }
    | CREATE CASE NUMBER IN IDENTIFIER {
        generate_case_statement($3, $5);
        free($5);
      }
    | CREATE DEFAULT IN IDENTIFIER {
        generate_default_case($4);
        free($4);
      }
    | CREATE BREAK IN IDENTIFIER {
        generate_break_statement($4);
        free($4);
      }
    | CLOSE BRACE IN IDENTIFIER {
        generate_close_brace($4);
        free($4);
      }
     | CREATE ARRAY IDENTIFIER FROM NUMBER TO NUMBER IN IDENTIFIER IN IDENTIFIER {
        generate_array($3, $5, $7, $9, $11);
        free($3);
        free($9);
        free($11);
      }

       | CREATE ITERATE ARRAY IDENTIFIER USING INDEX IDENTIFIER IN IDENTIFIER IN IDENTIFIER {
        generate_array_iteration($4, $7, $9, $11);
        free($4);
        free($7);
        free($9);
        free($11);
      }
       | CREATE FILE_TOKEN IDENTIFIER WITH NUMBER FUNCTIONS IDENTIFIER IDENTIFIER IDENTIFIER IDENTIFIER IDENTIFIER {
        generate_create_file($3);
        generate_add_function($7, $3);
        generate_add_function($8, $3);
        generate_add_function($9, $3);
        generate_add_function($10, $3);
        generate_add_function($11, $3);
        free($3);
        free($7);
        free($8);
        free($9);
        free($10);
        free($11);
      }
    ;

%%

/* Check if a variable exists in a function */
int variable_exists_in_function(const char *var, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return 0;
    }

    char line[256];
    int in_function = 0;
    int var_found = 0;
    int brace_count = 0;
    char function_pattern[256];
    
    // Create pattern to search for function
    snprintf(function_pattern, sizeof(function_pattern), "%s(", funcname);
    
    while (fgets(line, sizeof(line), fp)) {
        // Check if we're entering the target function
        if (!in_function && strstr(line, function_pattern)) {
            in_function = 1;
        }
        
        // If in function, check for variable declaration or usage
        if (in_function) {
            // Count braces to track function scope
            for (char *c = line; *c; c++) {
                if (*c == '{') brace_count++;
                if (*c == '}') brace_count--;
            }
            
            // Check if we've exited the function
            if (brace_count <= 0 && strstr(line, "}")) {
                break;
            }
            
            // Check for variable in different contexts
            char var_pattern[256];
            snprintf(var_pattern, sizeof(var_pattern), "int %s", var); // Check for declaration
            
            if (strstr(line, var_pattern) || 
                (strstr(line, var) && (line[0] == ' ' || line[0] == '\t'))) {
                var_found = 1;
                break;
            }
        }
    }
    
    fclose(fp);
    return var_found;
}

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

long find_insertion_point_in_function(const char *file_content, const char *funcname) {
    // Create pattern to search for function
    char pattern[256];
    snprintf(pattern, sizeof(pattern), "%s(", funcname);
    
    char *func_pos = strstr(file_content, pattern);
    if (!func_pos) {
        return -1; // Function not found
    }
    
    // Find the opening brace of the function
    char *brace_pos = strchr(func_pos, '{');
    if (!brace_pos) {
        return -1; // Opening brace not found
    }
    
    // Now find the right position to insert code - this should be right before the 
    // closing brace of the function, not after content at brace level 1
    char *current_pos = brace_pos + 1;
    int brace_level = 1;
    
    // Track the position until we find the closing brace of the function
    while (*current_pos && brace_level > 0) {
        if (*current_pos == '{') {
            brace_level++;
        } else if (*current_pos == '}') {
            brace_level--;
            
            // If this is the closing brace of the function, we found our spot
            if (brace_level == 0) {
                // Find the start of this line or the last newline before the brace
                char *line_start = current_pos;
                while (line_start > brace_pos && *(line_start-1) != '\n') {
                    line_start--;
                }
                
                // Return position right before the closing brace indentation
                return (line_start - file_content);
            }
        }
        
        current_pos++;
    }
    
    // If we couldn't find the closing brace for some reason, 
    // fall back to position after opening brace
    return (brace_pos - file_content) + 1;
}

// Now modify the generate_for_loop function to use the new helper function
void generate_for_loop(const char *var, int limit, int step, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    // First, let's check if the file exists
    FILE *fp = fopen(full_name, "r");
    if (!fp) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }

    // Read the entire file content into memory
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the for loop code with proper indentation
    char for_loop[256];
    snprintf(for_loop, sizeof(for_loop), 
             "    for (int %s = 0; %s < %d; %s += %d) {\n        // TODO: Add logic\n    }\n",
             var, var, limit, var, step);
    
    // Create a new file with the for loop inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write for loop
    fputs(for_loop, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("For loop with '%s' added to function '%s' in %s up to %d with step %d\n", 
           var, funcname, full_name, limit, step);
}

// Similarly, update generate_if_statement to use the new helper
void generate_if_statement(const char *var, const char *op, int value, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the if statement code with proper indentation
    char if_statement[256];
    snprintf(if_statement, sizeof(if_statement), 
             "    if (%s %s %d) {\n        // TODO: Add logic for if condition\n    }\n",
             var, op, value);
    
    // Create a new file with the if statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write if statement
    fputs(if_statement, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("If statement for '%s %s %d' added to function '%s' in %s\n", 
           var, op, value, funcname, full_name);
}

// Update generate_if_else_statement to use the new helper
void generate_if_else_statement(const char *var, const char *op, int value, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create the if-else statement code with proper indentation
    char if_else_statement[256];
    snprintf(if_else_statement, sizeof(if_else_statement), 
             "    if (%s %s %d) {\n        // TODO: Add logic for if condition\n    } else {\n        // TODO: Add logic for else condition\n    }\n",
             var, op, value);
    
    // Create a new file with the if-else statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write if-else statement
    fputs(if_else_statement, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("If-else statement for '%s %s %d' added to function '%s' in %s\n", 
           var, op, value, funcname, full_name);
}

// Update generate_switch_statement to use the new helper
void generate_switch_statement(const char *var, int cases, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and variable exists in function
    if (!variable_exists_in_function(var, funcname, filename)) {
        printf("Error: Variable '%s' not found in function '%s' in file '%s'.\n", 
               var, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Create buffer for the switch statement
    char *switch_code = (char *)malloc(1024);
    if (!switch_code) {
        free(file_content);
        perror("Memory allocation error");
        return;
    }
    
    // Start the switch statement with proper indentation
    sprintf(switch_code, "    switch (%s) {\n", var);
    
    // Add the specified number of cases
    for (int i = 1; i <= cases; i++) {
        char case_code[256];
        sprintf(case_code, "        case %d:\n            // TODO: Add logic for case %d\n            break;\n", i, i);
        strcat(switch_code, case_code);
    }
    
    // Add default case and close the switch
    strcat(switch_code, "        default:\n            // TODO: Add logic for default case\n            break;\n    }\n");
    
    // Create a new file with the switch statement inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(switch_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write switch statement
    fputs(switch_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(switch_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Switch statement for '%s' with %d cases added to function '%s' in %s\n", 
           var, cases, funcname, full_name);
}

void generate_case_statement(int value, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for case statement");
        return;
    }

    fprintf(fp, "    case %d:\n        // TODO: Add logic for case %d\n", value, value);
    fclose(fp);
    printf("Case %d added to %s\n", value, full_name);
}

void generate_default_case(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for default case");
        return;
    }

    fprintf(fp, "    default:\n        // TODO: Add logic for default case\n");
    fclose(fp);
    printf("Default case added to %s\n", full_name);
}

void generate_break_statement(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file for break statement");
        return;
    }

    fprintf(fp, "        break;\n");
    fclose(fp);
    printf("Break statement added to %s\n", full_name);
}

void generate_close_brace(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    FILE *fp = fopen(full_name, "a");
    if (!fp) {
        perror("Error opening file to close brace");
        return;
    }

    fprintf(fp, "}\n");
    fclose(fp);
    printf("Closing brace added to %s\n", full_name);
}

void generate_array(const char *array_name, int start, int end, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);

    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Calculate array size
    int size = end - start + 1;
    if (size <= 0) {
        printf("Error: Invalid array range (start: %d, end: %d).\n", start, end);
        free(file_content);
        return;
    }
    
    // Create array declaration and initialization
    char *array_code = (char *)malloc(size * 20 + 256); // Allocate enough space
    if (!array_code) {
        free(file_content);
        perror("Memory allocation error");
        return;
    }
    
    // Create array declaration with proper indentation
    sprintf(array_code, "    int %s[%d] = {", array_name, size);
    
    // Initialize array with values
    for (int i = 0; i < size; i++) {
        char value[20];
        sprintf(value, "%d", start + i);
        
        // Add comma except for the last element
        if (i < size - 1) {
            strcat(value, ", ");
        }
        
        strcat(array_code, value);
        
        // Add line break every 10 elements for readability
        if ((i + 1) % 10 == 0 && i < size - 1) {
            strcat(array_code, "\n        ");
        }
    }
    
    // Close the array initialization
    strcat(array_code, "};\n");
    
    // Create a new file with the array inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(array_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write array code
    fputs(array_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(array_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Array '%s' with range [%d-%d] (size: %d) added to function '%s' in %s\n", 
           array_name, start, end, size, funcname, full_name);
}

void generate_array_iteration(const char *array_name, const char *index_var, const char *funcname, const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    fclose(fp_check);
    
    // Check if function exists and array exists in function
    if (!variable_exists_in_function(array_name, funcname, filename)) {
        printf("Error: Array '%s' not found in function '%s' in file '%s'.\n", 
               array_name, funcname, full_name);
        return;
    }
    
    // Read the entire file content
    FILE *fp = fopen(full_name, "r");
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp);
    file_content[read_size] = '\0';
    fclose(fp);
    
    // Find the proper insertion point (at the end of the function)
    long insert_pos = find_insertion_point_in_function(file_content, funcname);
    if (insert_pos < 0) {
        printf("Function '%s' not found in %s or its structure is invalid.\n", funcname, full_name);
        free(file_content);
        return;
    }
    
    // Try to determine array size
    char *array_size = NULL;
    char *array_decl_pos = strstr(file_content, array_name);
    if (array_decl_pos) {
        char *open_bracket = strchr(array_decl_pos, '[');
        if (open_bracket) {
            char *close_bracket = strchr(open_bracket, ']');
            if (close_bracket && close_bracket > open_bracket) {
                int size = close_bracket - open_bracket - 1;
                array_size = (char *)malloc(size + 1);
                strncpy(array_size, open_bracket + 1, size);
                array_size[size] = '\0';
            }
        }
    }
    
    // Create the array iteration code
    char *iteration_code = (char *)malloc(512);
    if (!iteration_code) {
        free(file_content);
        if (array_size) free(array_size);
        perror("Memory allocation error");
        return;
    }
    
    if (array_size) {
        // If we found the array size, use it
        sprintf(iteration_code, 
                "    // Iterating through array %s\n    for (int %s = 0; %s < %s; %s++) {\n"
                "        // TODO: Process %s[%s]\n"
                "        // Example: printf(\"%%d \", %s[%s]);\n"
                "    }\n",
                array_name, index_var, index_var, array_size, index_var,
                array_name, index_var, array_name, index_var);
        free(array_size);
    } else {
        // If we couldn't determine the size, add a placeholder
        sprintf(iteration_code, 
                "    // Iterating through array %s\n    for (int %s = 0; %s < ARRAY_SIZE; %s++) {\n"
                "        // TODO: Replace ARRAY_SIZE with the actual size of %s\n"
                "        // TODO: Process %s[%s]\n"
                "        // Example: printf(\"%%d \", %s[%s]);\n"
                "    }\n",
                array_name, index_var, index_var, index_var, array_name,
                array_name, index_var, array_name, index_var);
    }
    
    // Create a new file with the iteration code inserted
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        free(iteration_code);
        perror("Error creating temporary file");
        return;
    }
    
    // Write content before insertion point
    fwrite(file_content, 1, insert_pos, out);
    
    // Write iteration code
    fputs(iteration_code, out);
    
    // Write remaining content
    fputs(file_content + insert_pos, out);
    
    fclose(out);
    free(file_content);
    free(iteration_code);
    
    // Replace original file with the modified one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Array iteration for '%s' using index '%s' added to function '%s' in %s\n", 
           array_name, index_var, funcname, full_name);
}

void optimize_code(const char *filename) {
    char full_name[100];
    snprintf(full_name, sizeof(full_name), "%s.c", filename);
    
    // Check if file exists
    FILE *fp_check = fopen(full_name, "r");
    if (!fp_check) {
        printf("Error: File '%s' does not exist.\n", full_name);
        return;
    }
    
    // Read the entire file content
    fseek(fp_check, 0, SEEK_END);
    long file_size = ftell(fp_check);
    fseek(fp_check, 0, SEEK_SET);
    
    char *file_content = (char *)malloc(file_size + 1);
    if (!file_content) {
        fclose(fp_check);
        perror("Memory allocation error");
        return;
    }
    
    size_t read_size = fread(file_content, 1, file_size, fp_check);
    file_content[read_size] = '\0';
    fclose(fp_check);
    
    // Create a new temporary file
    FILE *out = fopen("temp.c", "w");
    if (!out) {
        free(file_content);
        perror("Error creating temporary file");
        return;
    }
    
    // Track changes made
    int changes = 0;
    char *optimized_content = strdup(file_content);
    if (!optimized_content) {
        free(file_content);
        fclose(out);
        perror("Memory allocation error");
        return;
    }
    
   
    char *ptr = optimized_content;
    while ((ptr = strstr(ptr, "int ")) != NULL) {
        // Check if variable is used
        char var_name[100] = {0};
        if (sscanf(ptr + 4, "%99[a-zA-Z0-9_]", var_name) == 1) {
          
            char *first_use = ptr;
            char *next_use = ptr + strlen(var_name) + 4;
            
           
            char search_pattern[150];
            snprintf(search_pattern, sizeof(search_pattern), "%s", var_name);
            
            int usage_count = 0;
            char *search_pos = optimized_content;
            while ((search_pos = strstr(search_pos, search_pattern)) != NULL) {
                // Check if this is a proper variable usage
                char prev_char = (search_pos > optimized_content) ? *(search_pos - 1) : ' ';
                char next_char = *(search_pos + strlen(search_pattern));
                
                if ((prev_char == ' ' || prev_char == '\t' || prev_char == '(' || prev_char == '=') &&
                    (next_char == ' ' || next_char == ';' || next_char == ')' || next_char == ',' || 
                     next_char == '+' || next_char == '-' || next_char == '*' || next_char == '/')) {
                    usage_count++;
                }
                search_pos += strlen(search_pattern);
            }
            
            // If used exactly once (declaration), mark for potential optimization
            if (usage_count == 1) {
                // We would normally optimize this, but for now we'll just notify
                changes++;
            }
        }
        ptr++;
    }
    
    // 2. Optimize loop conditions
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "for (")) != NULL) {
        char init[100], cond[100], incr[100];
        // Try to parse the for loop components
        if (sscanf(ptr + 5, "%99[^;];%99[^;];%99[^)]", init, cond, incr) == 3) {
            // Check if we can optimize the loop
            if (strstr(cond, "<") && !strstr(cond, "=")) {
                // Convert "i < n" to "i != n" for certain loops where appropriate
                if (strstr(incr, "++") || strstr(incr, "+=1")) {
                    char *lt_pos = strstr(cond, "<");
                    if (lt_pos) {
                        // Replace < with != where it makes sense
                        // This is a heuristic optimization that works in some cases
                        memcpy(lt_pos, "!=", 2);
                        changes++;
                    }
                }
            }
        }
        ptr++;
    }
    
    // 3. Optimize redundant code
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "if (")) != NULL) {
        // Look for redundant conditions like "if (x == true)" or "if (x == false)"
        char cond[100];
        if (sscanf(ptr + 4, "(%99[^)])", cond) == 1) {
            if (strstr(cond, "== true")) {
                // Replace "x == true" with "x"
                char *true_pos = strstr(cond, "== true");
                size_t prefix_len = true_pos - cond;
                
                // Ensure we have space for the string manipulation
                char *new_condition = (char *)malloc(strlen(cond) + 1);
                if (new_condition) {
                    strncpy(new_condition, cond, prefix_len);
                    new_condition[prefix_len] = '\0';
                    strcat(new_condition, true_pos + 7); // Skip "== true"
                    
                    // Replace in optimized content
                    char *start_of_condition = ptr + 4;
                    char *end_of_condition = strchr(start_of_condition, ')');
                    if (end_of_condition) {
                        size_t old_len = end_of_condition - start_of_condition;
                        size_t new_len = strlen(new_condition);
                        
                        if (new_len <= old_len) {
                            // Overwrite in place
                            memcpy(start_of_condition, new_condition, new_len);
                            // Fill rest with spaces
                            memset(start_of_condition + new_len, ' ', old_len - new_len);
                            changes++;
                        }
                    }
                    free(new_condition);
                }
            }
            else if (strstr(cond, "== false")) {
                // Replace "x == false" with "!x"
                char *false_pos = strstr(cond, "== false");
                size_t prefix_len = false_pos - cond;
                
                // Ensure we have space for the string manipulation
                char *new_condition = (char *)malloc(strlen(cond) + 2); // +2 for '!' and null terminator
                if (new_condition) {
                    new_condition[0] = '!';
                    strncpy(new_condition + 1, cond, prefix_len);
                    new_condition[prefix_len + 1] = '\0';
                    strcat(new_condition, false_pos + 8); // Skip "== false"
                    
                    // Replace in optimized content
                    char *start_of_condition = ptr + 4;
                    char *end_of_condition = strchr(start_of_condition, ')');
                    if (end_of_condition) {
                        size_t old_len = end_of_condition - start_of_condition;
                        size_t new_len = strlen(new_condition);
                        
                        if (new_len <= old_len) {
                            // Overwrite in place
                            memcpy(start_of_condition, new_condition, new_len);
                            // Fill rest with spaces
                            memset(start_of_condition + new_len, ' ', old_len - new_len);
                            changes++;
                        }
                    }
                    free(new_condition);
                }
            }
        }
        ptr++;
    }
    
    // 4. Loop unrolling optimization detection
    ptr = optimized_content;
    while ((ptr = strstr(ptr, "for (")) != NULL) {
        int loop_count = 0;
        // Check if this is a simple counting loop
        if (sscanf(ptr, "for (int %*[^=]= %*d; %*[^<]< %d; %*[^{]{", &loop_count) == 1) {
            // If the loop count is very small, consider unrolling
            if (1 <= loop_count && loop_count <= 3) {
                // For demonstration we're just marking potential unroll candidates
                changes++;
            }
        }
        ptr++;
    }
    
    // 5. Constant folding optimization
    ptr = optimized_content;
    while ((ptr = strstr(ptr, " = ")) != NULL) {
        int a, b, result;
        char op;
        
        // Match patterns like: x = 5 + 3; or x = 10 * 2;
        if (sscanf(ptr + 3, "%d %c %d;", &a, &op, &b) == 3) {
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b != 0) result = a / b; 
                    else goto next_expr; // Skip division by zero
                    break;
                default: goto next_expr; // Skip if not a basic arithmetic operator
            }
            
            // Format the replacement expression
            char new_expr[50];
            snprintf(new_expr, sizeof(new_expr), " = %d;", result);
            
            // Find the end of the original expression
            char *expr_end = strchr(ptr + 3, ';');
            if (expr_end) {
                size_t old_len = (expr_end - ptr) - 2; // -2 to exclude " = "
                size_t new_len = strlen(new_expr) - 3;  // -3 to exclude " = "
                
                // Replace the expression
                if (new_len <= old_len) {
                    memcpy(ptr + 3, new_expr + 3, new_len);
                    // Fill rest with spaces
                    memset(ptr + 3 + new_len, ' ', old_len - new_len);
                    changes++;
                }
            }
        }
next_expr:
        ptr++;
    }
    
    // Write optimized content to the output file
    fputs(optimized_content, out);
    fclose(out);
    free(file_content);
    free(optimized_content);
    
    // Replace original file with the optimized one
    remove(full_name);
    rename("temp.c", full_name);
    
    printf("Code optimization complete for %s. %d potential optimization points identified.\n", 
           full_name, changes);
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