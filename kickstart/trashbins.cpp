#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        int N;
        cin >> N;
        string str;
        cin >> str;
        int result = 0;
        int rightres =INT_MAX;
        int leftres = INT_MAX;
        int i = 0;
        for (i = 0; i < N; i++)
        {
            if (str[i] == '1')
            {
                result += 0;
            }
            else
            {

                if (i < N - 1)
                {
                    for (int j = i + 1; j < N; j++)
                    {
                        if (str[j] == '1')
                        {
                            rightres = 0;
                            rightres = abs(i - j);
                            break;
                        }
                    }
                }
                else
                {
                    rightres = INT_MAX;
                }

                if(i>0)
                {
                for (int j = i - 1; j >= 0; j--)
                {

                    if (str[j] == '1')
                    {
                        leftres=0;
                        leftres = abs(i - j);
                        break;
                    }
                }
                }
                else{
                    leftres=INT_MAX;
                }
                result += min(leftres, rightres);                
            }
        }
        if(result>100000)
        {
            result=0;
        }
        cout << "Case #" << x << ": " << result << endl;
    }

    return 0;
}