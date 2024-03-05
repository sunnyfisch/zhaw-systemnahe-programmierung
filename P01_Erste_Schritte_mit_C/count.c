#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    (void) printf("Enter a text and press ENTER: ");
    int wordCount = 0;
    int charCount = 0;
    int input, lastChar = ' ';

    while ((input = getchar()) != '\n' ) {
        charCount++;
        if ((input == ' ' || input == '\t') && (lastChar != ' ' && lastChar != '\t')) {
            wordCount++;
        }
        lastChar = input;
    }
    if (lastChar != ' ' && lastChar != '\t') {
        wordCount++;
    }
    printf("Word-count: %i\n", wordCount);
    printf("Char-count: %i\n", charCount);
    return EXIT_SUCCESS;
}
