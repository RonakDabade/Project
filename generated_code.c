void create_test() {
    FILE *fp = fopen("test.txt", "w");
    if (fp) {
        fprintf(fp, "File created successfully.\n");
        fclose(fp);
    } else {
        printf("Error creating the file.\n");
    }
}

