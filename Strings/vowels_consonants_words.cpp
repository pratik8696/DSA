#include <iostream>
using namespace std;
static int words = 1;
static int consonants;
static int vowels;

void check(string sentence)
{

    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if(i==0&&sentence[i]==' ')
        {
            continue;
        }
        else
        if (sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U' || sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
        {
            vowels++;
        }
        
        else if (sentence[i] == ' ' && (sentence[i - 1] != ' '))
        {
            words++;
        }

        else
        {
            if(sentence[i]==' ')
            {continue;}
            consonants++;
        }
    }
}
int largestword(string sentence)
{
}
int main()
{
    string sentence;
    getline(cin, sentence);
    check(sentence);
    cout << "The no of words in " << sentence << " are = " << words << endl;
    cout << "The no of vowels in " << sentence << " are = " << vowels << endl;
    cout << "The no of consonants in " << sentence << " are = " << consonants << endl;
    return 0;
}