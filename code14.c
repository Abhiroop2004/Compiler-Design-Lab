#include <stdio.h>

int main() {
    FILE *fp = fopen("test.c", "r");   // change filename if needed
    int freq[256] = {0};
    int ch;

    if (!fp) {
        printf("Could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        freq[ch]++;   // count each character
    }

    fclose(fp);

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (i == '\n')
                printf("'\\n' : %d\n", freq[i]);
            else if (i == '\t')
                printf("'\\t' : %d\n", freq[i]);
            else
                printf("'%c' : %d\n", i, freq[i]);
        }
    }

    return 0;
}
