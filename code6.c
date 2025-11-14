#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[200];
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    for (int i = 0; line[i] != '\0'; i++) {
        // Character constant (e.g., 'a')
        if (line[i] == '\'' && line[i+2] == '\'') {
            printf("Character: '%c'\n", line[i+1]);
            i += 2;
        }

        // Number constant (integer or float)
        else if (isdigit(line[i])) {
            char num[50];
            int j = 0, hasDot = 0;

            while (isdigit(line[i]) || line[i] == '.') {
                if (line[i] == '.') hasDot = 1;
                num[j++] = line[i++];
            }
            num[j] = '\0';
            if (hasDot)
                printf("Float: %s\n", num);
            else
                printf("Integer: %s\n", num);
        }
    }
    return 0;
}
