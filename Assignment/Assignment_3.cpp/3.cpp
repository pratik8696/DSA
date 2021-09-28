#include <stdio.h>
int main()
{
    char s[1000];
    gets(s);
    int vowels = 0, consonants = 0, characters = 0, space = 0, i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == '0' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == '0' || s[i] == 'U')
        {
            vowels++;
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            consonants++;
        }
        else if (s[i] == ' ')
        {
            space++;
        }
        else
        {
            characters++;
        }
        i++;
    }
    printf("The number of vowels in the string is: %d\n", vowels);
    printf("The number of consonants in the string is: %d\n", consonants);
    printf("The number of space in the string is: %d\n", space);
    printf("The number of words in the string is: %d\n", space + 1);
    printf("The number of characters in the string is: %d\n", characters + vowels + consonants + space);
    return 0;
}
