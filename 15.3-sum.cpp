int dp[501][51][2][2] = {};

int findGoodStrings(int n, string s1, string s2, string evil)
{
    return dfs(0, 0, true, true, n, s1, s2, evil, computeLPS(evil));
}

int dfs(int i, int evilMatched, bool leftBound, bool rightBound, int n, string &s1, string &s2, string &evil, const vector<int> &lps)
{
    if (evilMatched == evil.size())
        return 0; // contain `evil` as a substring -> not good string
    if (i == n)
        return 1; // it's a good string
    if (dp[i][evilMatched][leftBound][rightBound] != 0)
        return dp[i][evilMatched][leftBound][rightBound];
    char from = leftBound ? s1[i] : 'a';
    char to = rightBound ? s2[i] : 'z';
    int res = 0;
    for (char c = from; c <= to; c++)
    {
        int j = evilMatched; // j means the next match between current string (end at char `c`) and `evil` string
        while (j > 0 && evil[j] != c)
        {
            j = lps[j - 1];
            if (c == evil[j])
            {
                j++;
            }
        }
        res += dfs(i + 1, j, leftBound && (c == from), rightBound && (c == to), n, s1, s2, evil, lps);
        res %= 1000000007;
    }
    return dp[i][evilMatched][leftBound][rightBound] = res;
}

vector<int> computeLPS(const string &str)
{ // Longest Prefix also Suffix
    int n = str.size();
    vector<int> lps = vector<int>(n);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && str[i] != str[j])
            j = lps[j - 1];
        if (str[i] == str[j])
            lps[i] = ++j;
    }
    return lps;
}
