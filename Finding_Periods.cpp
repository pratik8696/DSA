#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> kmp(string str)
{
    int n = str.length();
    vector<int> partial(n);
    partial[0] = 0;

    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = partial[j - 1];
        }
        if (str[i] == str[j])
        {
            j++;
        }
        partial[i] = j;
    }

    vector<int> period;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            bool flag = true;
            for (int j = i; j < n; j++)
            {
                if (partial[j] < i)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                period.push_back(i);
            }
        }
    }

    return period;
}

int main()
{
    string str;
    cin >> str;
    vector<int> period = kmp(str);
    for (int i = 0; i < period.size(); i++)
    {
        cout << period[i] << " ";
    }
    cout << endl;
    return 0;
}
