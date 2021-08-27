#include <iostream>
#include <bits/stdc++.h>
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
    int count=0,prevcount=0;
    for (int i = 0; sentence[i]!='\0'; i++)
    {
        if(sentence[i]!=' ')
        {
            count++;
        }
        else
        {
            // check
                prevcount=max(prevcount,count);
                count=0;
        }
    }
    return max(prevcount,count);
}
int main()
{
    string sentence;
    getline(cin, sentence);
    check(sentence);
    cout << "The no of words in this sentence are = " << words << endl;
    cout << "The no of vowels in this sentence are = " << vowels << endl;
    cout << "The no of consonants in this sentence are = " << consonants << endl;
    cout<<"The length of largest word is = "<<largestword(sentence);
    return 0;
}