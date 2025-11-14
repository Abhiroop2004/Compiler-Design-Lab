#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100], c, prev = 0;
    int lines = 0, tokens = 0, comments = 0;
    int in_comment_block = 0, in_token = 0;

    printf("Enter source filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {

        // Count lines
        if (c == '\n') lines++;

        // Detect comment start
        if (!in_comment_block && prev == '/' && c == '/') {
            comments++;
        }
        if (!in_comment_block && prev == '/' && c == '*') {
            in_comment_block = 1;
        }
        if (in_comment_block && prev == '*' && c == '/') {
            comments++;
            in_comment_block = 0;
        }

        // Token detection (simple: sequences of letters/digits/underscores)
        if (!in_comment_block) {
            if (isalnum(c) || c == '_') {
                if (!in_token) {
                    tokens++;
                    in_token = 1;
                }
            } else {
                in_token = 0;
            }
        }

        prev = c;
    }

    fclose(fp);

    printf("Total lines: %d\n", lines);
    printf("Total tokens: %d\n", tokens);
    printf("Total comments: %d\n", comments);

    return 0;
}