#include <stdio.h>

int main() {
    FILE *fp = fopen("test.c", "r");  // change file name if needed
    int c, start = 0;
    int found = 0;

    if (!fp) {
        printf("Could not open file.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (!start && c == '/' && (c = fgetc(fp)) == '*') {
            start = 1;
            found = 1;
            printf("/*");
            continue;
        }
        if (start) {
            printf("%c", c);
            if (c == '*' && (c = fgetc(fp)) == '/') {
                printf("/\n\n");
                start = 0;
            }
        }
    }

    if (!found)
        printf("No multi-line comments found.\n");

    fclose(fp);
    return 0;
}
