#include <stdio.h>
#include <ctype.h>

int main() {
    char line[1024];

    // Read line by line from standard input
    while (fgets(line, sizeof(line), stdin)) {
        char *ptr = line;

        // Skip leading whitespace
        while (*ptr && isspace(*ptr)) {
            ptr++;
        }

        // Check if the first non-whitespace character is '#'
        if (*ptr == '#') {
            printf("%s", line);
        }
    }

    return 0;
}
