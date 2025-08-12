#include<bits/stdc++.h>

using namespace std;
#ifndef ONLINE_JUDGE

#include "debug.h"

#else
#define debug(...)
#endif
#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define read(x) for (auto &it:(x))cin >> it;
#define readpair(x) for (auto &it:(x))cin >> it.first >> it.second;
#define print(x) for (auto &it:(x))cout << it << " ";
#define printpair(x) for (auto it:(x))cout << it.first << " " << it.second << '\n';
#define prec(x) fixed<<setprecision(x)
#define skip continue
#define stop break
typedef unsigned int ui;
typedef long long ll;
typedef __int128 lll;
#define ull unsigned long long
#define ld long double
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define dd double
#define Fill(x, n) memset(x, n, sizeof x)
#define sz(x) int(x.size())
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; list[a].pb(b); list[b].pb(a);}
#define loop(i, n) for(int i=0; i<n; i++)
#define loop1(i, n) for(int i=1; i<=n; i++)
#define loopi(i, s, e) for(int i=s; i <= e; i++)
#define loopiRev(i, s, e) for(int i=s; i >= e; i--)
#define sum_vt(x) accumulate(all(x),0)
#define each(x, y) for(auto &x:y)
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
ll di[] = {1, 0, -1, 0, 1, -1, 1, -1};
const ld pi = acos (-1);

void start() {
    FAST();
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    freopen ("error.txt", "w", stderr);
#endif
}

ll power(ll x, ll y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power (x, y / 2) * power (x, y / 2);
    else
        return x * power (x, y / 2) * power (x, y / 2);
}

ll fac(ll n) {
    if (n <= 1)
        return 1;
    return n * fac (n - 1);
}

ll Log2(ll i) {
    if (i <= 1)
        return 0;
    return Log2 (i / 2) + 1;
}

ll gcd(ll a, ll b) {
    return (a ? gcd (b % a, a) : b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd (a, b);
}

const ll N = 1e4 + 5, MOD = 1e9 + 7;
ll n, s;
vector<pair<pair<ld, ld>, int>> v (N);

bool check(ld md) {
    ll sum = 0;
    loop(i, n)
        if (v[i].ff.ff * v[i].ff.ff + v[i].ff.ss * v[i].ff.ss <= md * md)
            sum += v[i].ss;
    return sum + s >= 1e6;
}

void runTestCase(int t) {
    cin >> n >> s;
    ld sum = 0, ans = 0.0;
    loop(i,n) {
        cin >> v[i].ff.ff >> v[i].ff.ss >> v[i].ss;
        sum += v[i].ss;
    }
    if (s + sum < 1e6) {
        cout << -1;
        return;
    }
    ld lo = 0.0, hi = 100001.0, md = 0.0;
    while ( hi - lo >= 0.00000001){
        md = (lo + hi) * 0.5;
        if (check (md)){
            ans = sqrt(md*md);
            hi = md;
        }
        else
            lo = md;
    }
    cout << prec(7) << ans;
}

int main() {
    start ();
    int t = 1;
//    cin >> t;
    loop1(i,t)
        runTestCase (i);
}