typedef long long ll;

bool isvalid(ll row, ll col, vector<string> s, ll n)
{
    // same row and col mai koi ni hoga
    for (ll i = 0; i < n; i++)
    {
        if (s[row][i] == 'Q')
        {
            return false;
        }
        if (s[i][col] == 'Q')
        {
            return false;
        }
    }
    // diagonal mai koi ni hoga
    // {-1,-1},{+1,+1},{-1,+1},{+1,-1}
    ll r = row, c = col;
    while (r >= 0 && c >= 0)
    {
        if (s[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c--;
    }
    // {-1,-1},{+1,+1},{-1,+1},{+1,-1}
    r = row, c = col;
    while (r < n && c < n)
    {
        if (s[r][c] == 'Q')
        {
            return false;
        }
        r++;
        c++;
    }
    // {-1,-1},{+1,+1},{-1,+1},{+1,-1}
    r = row, c = col;
    while (r >= 0 && c < n)
    {
        if (s[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c++;
    }
    // {-1,-1},{+1,+1},{-1,+1},{+1,-1}
    r = row, c = col;
    while (r < n && c >= 0)
    {
        if (s[r][c] == 'Q')
        {
            return false;
        }
        r++;
        c--;
    }
    return true;
}

void solve(ll n, vector<string> s, ll col, vector<vector<string>> &ans, ll cc)
{
    // start for column 0;
    if (col == n)
    {
        if (cc == n)
        {
            ans.push_back(s);
        }
        return;
    }
    else
    {
        for (ll row = 0; row < n; row++)
        {
            if (isvalid(row, col, s, n))
            {
                s[row][col] = 'Q';
                solve(n, s, col + 1, ans, cc + 1);
                // backtrack
                s[row][col] = '.';
            }
        }
    }
}

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> s;
        string t = "";
        for (ll j = 0; j < n; j++)
        {
            t.push_back('.');
        }
        for (ll i = 0; i < n; i++)
        {
            s.push_back(t);
            cout << t << endl;
        }
        vector<vector<string>> ans;
        solve(n, s, 0, ans, 0);
        return ans;
    }
};