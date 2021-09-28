#include <stdio.h>
#include <string.h>

void pr_rev(char str[])
{
    int i;
    int len = strlen(str);
    printf("The reverse string is: ");
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void count_consonant(char *str)
{
    int vowels = 0, consonants = 0;
    int i;
    char ch;

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            vowels++;
        else if (ch == ' ')
            continue;
        else
            consonants++;
    }
    printf("Consonants: %d", consonants);
}

void rever(char string[])
{
    char temp;
    int i, j;
    int n = strlen(string);
    int len = strlen(string);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
}
int main()
{
    char str[100];
    scanf("%[^\n]s", str);
    pr_rev(str);
    count_consonant(str);
    printf("\nThe string in reverse alphabetical : ");
    rever(str);
    return 0;
}
