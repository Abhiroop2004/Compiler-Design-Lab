#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char* removeComments(const char* code) {
    int n = strlen(code);
    int j = 0;

    char *result = malloc(n + 1);  // allocate memory for result
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    bool inSingleLineComment = false;
    bool inMultiLineComment = false;

    for (int i = 0; i < n; i++) {
        if (inSingleLineComment) {
            if (code[i] == '\n') {
                inSingleLineComment = false;
                result[j++] = '\n';  // keep the newline
            }
        }
        else if (inMultiLineComment) {
            if (code[i] == '*' && code[i + 1] == '/') {
                inMultiLineComment = false;
                i++;  // skip '/'
            }
        }
        else if (code[i] == '/' && code[i + 1] == '/') {
            inSingleLineComment = true;
            i++;
        }
        else if (code[i] == '/' && code[i + 1] == '*') {
            inMultiLineComment = true;
            i++;
        }
        else {
            result[j++] = code[i];
        }
    }

    result[j] = '\0';  // terminate string
    return result;
}

int main() {
    const char code[] =
        "int main() { // This is a single line comment\n"
        "   printf(\"Hello, World!\"); /* This is a \n"
        "   multi-line comment */\n"
        "   return 0;\n"
        "}";

    char* cleanedCode = removeComments(code);
    printf("Code after removing comments:\n%s\n", cleanedCode);

    free(cleanedCode);  // free allocated memory
    return 0;
}
