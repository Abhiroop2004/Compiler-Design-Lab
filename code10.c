#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *s) {
    char *keywords[] = {
        "int","float","char","double","if","else","while","for","return",
        "void","long","short","signed","unsigned","struct","switch","case"
    };
    for (int i = 0; i < 16; i++)
        if (strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    FILE *fp;
    char filename[100], line[300];
    int lineNum = 0;

    printf("Enter source filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    int in_comment = 0;  // track unfinished /* */

    while (fgets(line, sizeof(line), fp)) {
        lineNum++;
        int i = 0;

        // Check for unclosed string literal
        int quotes = 0;

        while (line[i] != '\0') {

            /* ---------- Check for string literals ---------- */
            if (line[i] == '"' && !in_comment) {
                quotes++;
                i++;
                while (line[i] != '"' && line[i] != '\0')
                    i++;
                if (line[i] == '"') quotes++;
            }

            /* ---------- Check for start of block comment ---------- */
            if (!in_comment && line[i] == '/' && line[i+1] == '*') {
                in_comment = lineNum;  // store start line
            }

            /* ---------- Check for end of block comment ---------- */
            if (in_comment && line[i] == '*' && line[i+1] == '/') {
                in_comment = 0;
            }

            /* ---------- Detect invalid identifiers ---------- */
            if (!in_comment && isdigit(line[i])) {
                int start = i;

                while (isalnum(line[i]) || line[i] == '_') i++;

                if (i > start + 1) {
                    printf("Line %d: Invalid identifier starting with digit: %.*s\n",
                           lineNum, i - start, &line[start]);
                }
                continue;
            }

            i++;
        }

        /* ---------- Print unclosed string literal error ---------- */
        if (quotes % 2 == 1) {
            printf("Line %d: Unclosed string literal\n", lineNum);
        }
    }

    /* ---------- Unfinished comment error ---------- */
    if (in_comment) {
        printf("Line %d: Unfinished block comment (/*)\n", in_comment);
    }

    fclose(fp);
    return 0;
}
