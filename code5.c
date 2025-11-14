#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char line[200];
    printf("Enter C code (end with an empty line):\n");

    fgets(line, sizeof(line), stdin);
    if (line[0] == '\n') exit(1);  // stop on empty line

    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];

        // Arithmetic operators
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
            printf("%c → Arithmetic operator\n", c);

        // Relational operators
        else if ((c == '=' && line[i+1] == '=') || 
                    (c == '!' && line[i+1] == '=') || 
                    (c == '<' && (line[i+1] == '=' || line[i+1] != '=')) ||
                    (c == '>' && (line[i+1] == '=' || line[i+1] != '='))) {
            if (line[i+1] == '=') {
                printf("%c= is Relational operator\n", c);
                i++;
            } else if (c == '<' || c == '>')
                printf("%c is Relational operator\n", c);
        }

        // Logical operators
        else if ((c == '&' && line[i+1] == '&') || (c == '|' && line[i+1] == '|')) {
            printf("%c%c is Logical operator\n", c, line[i+1]);
            i++;
        } else if (c == '!' && line[i+1] != '=')
            printf("%c is Logical operator\n", c);
    }
    return 0;
}
