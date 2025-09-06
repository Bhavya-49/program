#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    char text[10000];

    printf("Text: ");
    if (!fgets(text, sizeof(text), stdin))
        return 0;

    int letters = 0;
    int words = 0;
    int sentences = 0;
    int in_word = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isalpha((unsigned char)c))
        {
            letters++;
        }

        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }

        // Define characters that belong to a word:
        int is_word_char = isalpha((unsigned char)c) || c == '\'' || c == '-';

        if (is_word_char)
        {
            if (!in_word)
            {
                words++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
    }

    if (words == 0)  // empty / no words
    {
        printf("Before Grade 1\n");
        return 0;
    }

    float L = (letters * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    float index = 0.0588f * L - 0.296f * S - 15.8f;
    int grade = (int) roundf(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}
