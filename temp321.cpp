#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

void build(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn)
{
    if (s == e)
    {
        tree[tn] = arr[s];
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    tree[tn] = tree[2 * tn] + tree[(2 * tn) + 1];
}

ll query(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn, ll l, ll r)
{
    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        return 0;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }

    ll ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    ll ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);
    return ans1 + ans2;
}

void update(vector<int>&arr, vector<int>&tree, ll s, ll e, ll tn, ll idx, ll val)
{
    if (s == e)
    {
        arr[idx] = val;
        tree[tn] = val;
        return;
    }
    ll mid = (s + e) / 2;
    if (idx > mid)
    {
        update(arr, tree, mid + 1, e, (2 * tn) + 1, idx, val);
    }
    else
    {
        update(arr, tree, s, mid, 2 * tn, idx, val);
    }
    tree[tn] = tree[2 * tn] + tree[(2 * tn) + 1];
}

void generatePaths(vector<string> &paths, string currentPath, int rows, int cols, int r, int c)
{
    if (r == rows && c == cols)
    {
        paths.push_back(currentPath);
        return;
    }
    if (c < cols)
    {
        generatePaths(paths, currentPath + "E", rows, cols, r, c + 1);
    }
    if (r < rows)
    {
        generatePaths(paths, currentPath + "S", rows, cols, r + 1, c);
    }
}

string findKthPath(int rows, int cols, int k)
{
    vector<string> paths;
    generatePaths(paths, "", rows, cols, 0, 0);
    sort(paths.begin(), paths.end());
    if (k <= paths.size())
    {
        return paths[k - 1];
    }
    else
    {
        return "";
    }
}

int main()
{
    int rows, cols, k;
    cin >> rows;
    cin >> cols;
    cin >> k;
    cout << findKthPath(rows, cols, k) << endl;
    return 0;
}