#include <bits/stdc++.h>
using namespace std;
vector<int> a[1000001];
int v[1000001] = {0}, c = 1, cc = 0;
int m[1000001] = {0};

void dfs(int s)
{
    v[s] = 1;
    for (int i = 0; i < a[s].size(); i++)
    {
        if (v[a[s][i]] == 0)
        {
            if (m[a[s][i]] == 1)
                return;
            c++;
            dfs(a[s][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y;
    cin >> n;
    int i;
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
    {
        cin >> m[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            c = 1;
            dfs(i);
            cc = max(cc, c);
        }
    }
    cout << cc;
}