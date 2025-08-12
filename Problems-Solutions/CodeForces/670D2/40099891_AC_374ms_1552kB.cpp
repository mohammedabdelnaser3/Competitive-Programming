/*
ID: Mohamed Abdelnasser (21210271)
TASK: gift1
LANG: C++
*/
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
#define ll long long
#define ull unsigned long long
#define ld long double
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef pair <int, int> pii;
typedef vector<pair <int, int>> vpii;
typedef vector<pair <ll, ll>> vpll;
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
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define loop(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define loopi(i,s,e) for(int i=s; i <= e; i++)
#define loopiRev(i,s,e) for(int i=s; i >= e; i--)
#define sum_vt(x) accumulate(all(x),0)
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
ll di[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const ld pi = acos(-1);
const int N = 2e5 + 1 , MOD = 1e9 + 7;


void start(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    freopen("error.txt", "w",stderr);
#endif
}

ll n, k;
vl a, b;

bool check(ll md) {
    ll cnt = 0;
    loop(i, n) {
        cnt += max((md * a[i]) - b[i],0LL);
        if (cnt > k)
            stop;
    }
    debug( md,cnt);
    return cnt <= k;
}

void runTestCase() {
    cin >> n >> k;
    a = b = vl(n);
    read(a)
    read(b)
    debug(n,k);
    debug(a);
    debug(b);
    ll lo = 0, hi = 2e9+5, md, ans = 0;
    while (lo <= hi) {
        md = ((lo + hi)/2);
        if (check(md)) {
            ans = md;
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }
    cout << ans;
}

int main() {
    start();
    int t = 1;
    //cin >> t;
    while (t--)
        runTestCase();
    return 0;
}

