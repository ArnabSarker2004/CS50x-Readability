#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float words = 1; // there are no space before the first word
float letters = 0;
float sentences = 0;
int index;

int main(void)
{
    string text = get_string("Text: ");

    for (int i = 0, len = strlen(text) ; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == ':') //increases sentence count if the condition is true
        {
            sentences++;
        }

        if (text[i - 1] == ' ' && isalpha(text[i]))  //increases word count if the conditions are true
        {
            words++;
        }

        if (isalpha(text[i])) //increases word count if the conditions are true
        {
            letters++;
        }

        index = round(0.0588 * (letters * 100 / words) - 0.296 * (sentences * 100 / words) - 15.8); // formula for determining the grade level of reading passage

    }

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


