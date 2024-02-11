#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution
{
public:
    vector<int> spf;

    void sieve()
    {
        spf[1] = 1;
        for (int i = 2; i < spf.size(); i++)
            spf[i] = i;

        for (int i = 4; i < spf.size(); i += 2)
            spf[i] = 2;

        for (int i = 3; i * i < spf.size(); i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j < spf.size(); j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }

    int perfectArray(int n, vector<int> &arr)
    {
        spf.resize(n + 10);
        sieve();
        int ans = 0;
        map<int, int> k;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            int prod = 1;
            map<int, int> mp;
            while (x != 1)
            {
                int z = spf[x];
                x = x / z;
                mp[z]++;
                if (mp[z] % 2 != 0)
                    prod = prod * z;
                else
                    prod = prod / z;
            }

            k[prod]++;
            if (prod != 1)
                ans = max(ans, k[prod]);
        }
        return ans;
    }
};

int main()
{
    freopen("1input.txt", "r", stdin);
    freopen("1output.txt", "w", stdout);
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> Arr(N);
        Array::input(Arr, N);

        char x;
        cin >> x;

        Solution obj;
        int res = obj.perfectArray(N, Arr);

        cout << res << endl;
        cout << "~" << endl;
    }
}
