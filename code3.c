#include <stdio.h>
#include <string.h>
#include <ctype.h>

void extractLexemes(const char *code) {
    int i = 0, len = strlen(code);
    char token[100];
    int t = 0;

    while (i < len) {
        // Skip spaces and newlines
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // If it's an operator or special character
        if (strchr("+-*/=;(),{}", code[i])) {
            if (t > 0) {
                token[t] = '\0';
                printf("%s, ", token);
                t = 0;
            }
            printf("%c, ", code[i]);
            i++;
        }
        // If it's an alphanumeric or part of an identifier/number
        else if (isalnum(code[i]) || code[i] == '_') {
            token[t++] = code[i++];
        }
        // Anything else (like quotes or other symbols)
        else {
            i++;
        }
    }

    // Print last token if exists
    if (t > 0) {
        token[t] = '\0';
        printf("%s", token);
    }

    printf("\n");
}

int main() {
    char code[] = "int a = b + 10;";
    printf("Input: %s\n", code);
    printf("Output: ");
    extractLexemes(code);
    return 0;
}
