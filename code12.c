#include <stdio.h>
#include <string.h>

#define KEYWORD_COUNT 32

int main() {
    const char *keywords[KEYWORD_COUNT] = {
        "auto","break","case","char","const","continue","default","do","double",
        "else","enum","extern","float","for","goto","if","int","long","register",
        "return","short","signed","sizeof","static","struct","switch","typedef",
        "union","unsigned","void","volatile","while"
    };

    int count[KEYWORD_COUNT] = {0};
    char word[100];
    FILE *fp;

    fp = fopen("test.c", "r");   // Change filename if needed
    if (!fp) {
        printf("Could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%99s", word) == 1) {
        for (int i = 0; i < KEYWORD_COUNT; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                count[i]++;
                break;
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < KEYWORD_COUNT; i++) {
        if (count[i] > 0)
            printf("%s : %d\n", keywords[i], count[i]);
    }

    return 0;
}
