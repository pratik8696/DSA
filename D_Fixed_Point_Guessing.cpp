
struct DSU
{
    v64 e, sz;
    DSU(ll n)
    {
        e.assign(n + 1, -1);
        sz.assign(n + 1, 1);
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll size(ll x) { return sz[find(x)]; }
    ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    void join(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (sz[a] < sz[b])
            {
                swap(a, b);
            }
            e[b] = a;
            sz[a] += sz[b];
        }
    }
};
