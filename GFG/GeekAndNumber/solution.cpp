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

class Solution {
  public:
    string magicNumber(int n, vector<long long> &arr) {
        sort(begin(arr),end(arr));
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                return false;
            }
        }
        int crt_able=1;
        vector<int> cnt(n);
        for(int mod=2;mod<=n/2;mod++)
        {
            fill(begin(cnt),end(cnt),0);
            for(int i=1;i<=n;i++)
            {
                cnt[arr[i]%mod]++;
            }
            if(*min_element(begin(cnt),end(cnt))>=2)
            {
                crt_able=0;
            }
        }
        return (crt_able==1?"True":"False");
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        vector<int> Arr(N);
        Array::input(Arr, N);

        Solution obj;
        string res = obj.magicNumber(N, Arr);

        cout << res << endl;
    }
}


