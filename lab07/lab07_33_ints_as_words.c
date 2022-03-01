#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DigitAsWord {
    int digit;
    char *word;
};

struct DigitAsWord digit_word_arr[10] = {
    {.digit = 0, .word = "zero"},  {.digit = 1, .word = "one"},
    {.digit = 2, .word = "two"},   {.digit = 3, .word = "three"},
    {.digit = 4, .word = "four"},  {.digit = 5, .word = "five"},
    {.digit = 6, .word = "six"},   {.digit = 7, .word = "seven"},
    {.digit = 8, .word = "eight"}, {.digit = 9, .word = "nine"}};

int main(void)
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);
    int num_sz = snprintf(NULL, 0, "%d", num);
    char num_str[num_sz + 1];
    sprintf(num_str, "%d", num);

    char word_str[100];
    int word_str_sz = 0;
    for (int i = 0; i < strlen(num_str); i++) {
        for (int j = 0; j < 10; j++) {
            if (num_str[i] - '0' == digit_word_arr[j].digit) {
                strcat(word_str, digit_word_arr[j].word);
                strcat(word_str, " ");
                word_str_sz += strlen(digit_word_arr[j].word) + 1;
                break;
            }
        }
    }

    printf("%s\n", word_str);
}