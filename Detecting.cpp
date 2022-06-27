typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<pair<p64, ll>> vpp64;
typedef set<ll> s64;
typedef set<p64> sp64;
typedef multiset<ll> ms64;
typedef multiset<p64> msp64;
typedef map<ll, ll> m64;
typedef map<ll, v64> mv64;
typedef unordered_map<ll, v64> uv64;
typedef unordered_map<ll, ll> u64;
typedef unordered_map<p64, ll> up64;
typedef unordered_map<ll, vp64> uvp64;
typedef priority_queue<ll> pq64;
typedef priority_queue<ll, v64, greater<ll>> pqs64;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define ie insert
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define al(arr, n) arr, arr + n
#define sz(x) ((ll)(x).size())

ll n, m;
bool isvalid(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    return true;
}

ll fun(ll i, ll j1, ll j2, vv64 &arr, vv64 &dp)
{
    if (i == n)
    {
        if (j1 == j2)
        {
            return arr[i][j1];
        }
        return arr[i][j1] + arr[i][j2];
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    // now we will form all cases
    ll maxx = 0;
    for (ll x = -1; x <= 1; x++)
    {
        for (ll y = -1; y <= 1; y++)
        {
            ll J1 = j1 + x, J2 = j2 + y;
            if (isvalid(i, J1) && isvalid(i, J2))
            {
                if (j1 == j2)
                {
                    maxx = max(arr[i][j1] + fun(i + 1, J1, J2, arr, dp), maxx);
                }
                else
                {
                    maxx = max(arr[i][j1] + arr[i][j2] + fun(i + 1, J1, J2, arr, dp), maxx);
                }
            }
        }
    }
    return dp[i][j1][j2] = maxx;
}

void solve()
{
    cin >> n >> m;
    vv64 arr(n + 10, v64(m + 10, 0));
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            cin >> arr[i][j];
        }
    }

    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            cout << arr[i][j] << " ";
        }
        cout << ln;
    }
    // now we will do the dp part using recursion
    cout << fun(1, 1, m, arr, dp) << ln;
}

int main()
{
    fast_cin();
    //#ifndef ONLINE_JUDGE
    //  freopen("revegetate.in", "r", stdin);
    // freopen("revegetate.out", "w", stdout);
    //#endif
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}

/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
*/
