#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "float", "return", "if", "else", "for", "while", "char", "double", "void"};
int isKeyword(char *word) {
    for (int i = 0; i < 10; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

int main() {
    char line[100], *word;
    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);
    word = strtok(line, " ,;(){}\n");

    while (word) {
        if (isKeyword(word))
            printf("%s is keyword\n", word);
        else if (isdigit(word[0]))
            printf("%s is constant\n", word);
        else
            printf("%s is identifier\n", word);
        word = strtok(NULL, " ,;(){}\n");
    }
    return 0;
}