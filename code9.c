#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};
int isKeyword(char *s) {
    for (int i = 0; i < 32; i++)
        if (strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    char str[50];
    printf("Enter a string: ");
    scanf("%s", str);

    // Rule 1: must start with letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_')) {
        printf("Invalid identifier\n");
        return 0;
    }

    // Rule 2: remaining characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            printf("Invalid identifier\n");
            return 0;
        }
    }

    // Rule 3: cannot be a keyword
    if (isKeyword(str)) {
        printf("Invalid identifier (keyword)\n");
    } else {
        printf("Valid identifier\n");
    }

    return 0;
}
