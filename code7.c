#include <stdio.h>

int main() {
    char line[300];
    printf("Enter a line of C code: ");
    fgets(line, sizeof(line), stdin);

    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '"') {      // start of a string literal
            printf("\"");
            i++;
            while (line[i] != '"' && line[i] != '\0') {
                putchar(line[i]);
                i++;
            }
            if (line[i] == '"') {  // closing quote
                printf("\"\n");
            }
        }
        i++;
    }
    return 0;
}
