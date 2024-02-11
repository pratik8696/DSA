#include <bits/stdc++.h>
typedef long long ll;

class node
{
public:
    ll front_ans = 0;
    ll back_ans = 0;
    ll curr_ans = 0;
    ll front_parity = 0;
    ll back_parity = 0;
    ll curr_size = 0;
    node operator+(const node &c)
    {
        node result;
        if (this->back_ans == 0 && c.back_ans == 0)
        {
            return result;
        }
        if (c.back_ans == 0)
        {
            result.front_ans = this->front_ans;
            result.back_ans = this->back_ans;
            result.curr_ans = this->curr_ans;
            result.curr_size = this->curr_size;
            result.front_parity = this->front_parity;
            result.back_parity = this->back_parity;
            return result;
        }
        if (this->back_ans == 0)
        {
            return c;
        }
        result.curr_size = this->curr_size + c.curr_size;
        result.front_parity = this->front_parity;
        result.back_parity = c.back_parity;
        result.back_ans = c.back_ans;
        result.front_ans = this->front_ans;
        result.curr_ans = max(this->curr_ans, c.curr_ans);
        ll temp = 0;
        if (this->back_parity != c.front_parity)
        {
            temp = this->back_ans + c.front_ans;
        }
        if (temp >= result.curr_ans)
        {
            result.curr_ans = temp;
            if (temp - this->back_ans == c.curr_size)
            {
                result.back_ans = max(temp, result.back_ans);
            }
            if (temp - c.front_ans == this->curr_ans)
            {
                result.front_ans = max(temp, result.front_ans);
            }
        }
        return result;
    }
    void print()
    {
        cout << this->front_ans << " " << this->back_ans << " " << this->curr_ans << " " << this->front_parity << " " << this->back_parity << " " << this->curr_size << endl;
    }
};

void build(vector<int> &arr, node tree[], ll s, ll e, ll tn)
{
    if (s == e)
    {
        tree[tn].front_ans = 1;
        tree[tn].back_ans = 1;
        tree[tn].front_parity = arr[s] % 2;
        tree[tn].back_parity = arr[s] % 2;
        tree[tn].curr_size = 1;
        tree[tn].curr_ans = 1;
        return;
    }
    ll mid = (s + e) / 2;
    build(arr, tree, s, mid, 2 * tn);
    build(arr, tree, mid + 1, e, (2 * tn) + 1);
    tree[tn] = tree[2 * tn] + tree[(2 * tn) + 1];
}

node query(vector<int> &arr, node tree[], ll s, ll e, ll tn, ll l, ll r)
{
    ll mid = (s + e) / 2;
    // out
    if (s > r || l > e)
    {
        node res;
        return res;
    }
    // in
    if (s >= l && r >= e)
    {
        return tree[tn];
    }

    node ans1 = query(arr, tree, s, mid, 2 * tn, l, r);
    node ans2 = query(arr, tree, mid + 1, e, (2 * tn) + 1, l, r);
    return ans1 + ans2;
}

void update(vector<int> &arr, node tree[], ll s, ll e, ll tn, ll idx, ll val)
{
    if (s == e)
    {
        arr[idx] = val;
        tree[tn].front_ans = 1;
        tree[tn].back_ans = 1;
        tree[tn].front_parity = arr[idx] % 2;
        tree[tn].back_parity = arr[idx] % 2;
        tree[tn].curr_size = 1;
        tree[tn].curr_ans = 1;
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

vector<int> f(int n, vector<int> &arr, int q, vector<vector<int>> &queries)
{
    node tree[4 * n + 10];
    build(arr, tree, 0, n - 1, 1);
    vector<int> ans;
    for (auto t : queries)
    {
        int type = t[0];
        int l = t[1] - 1;
        if (type == 1)
        {
            int r = t[2];
            update(arr, tree, 0, n - 1, 1, l, r);
        }
        else
        {
            int r = t[2] - 1;
            ans.push_back(query(arr, tree, 0, n - 1, 1, l, r).curr_ans);
        }
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> arr(n);
    forn(i, n)
    {
        cin >> arr[i];
    }
    ll q;
    cin >> q;
    vector<vector<int>> queries;
    forn(i, q)
    {
        int a, b, c;
        cin >> a >> b >> c;
        queries.pb({a, b, c});
    }
    for (auto t : f(n, arr, q, queries))
    {
        cout << t << " ";
    }
    cout << endl;
}

int main()
{
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}
