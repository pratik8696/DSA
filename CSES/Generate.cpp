#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[1000];
    scanf("%s", &s);
    switch (s[n - 1])
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        printf("Vowel Found");
        break;

    default:
        printf("Consonants Found");
    }
    return 0;
}