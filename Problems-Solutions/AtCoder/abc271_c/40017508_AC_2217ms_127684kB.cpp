#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
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
	FAST();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	freopen("error.txt", "w",stderr);
#endif
}

bool check(vi v,int  ans){
    int counter = 0, counter1 = 0;
    vb flag(1e9+5);
    for(auto it:v) {
        if (!flag[it] && it <= ans)
            counter1++;
        if (flag[it] || it > ans)
            counter++;
        if (it <= ans)
        flag[it] = true;
    }
    return (counter1 + (counter / 2) >= ans);
}

void runTestCase(){
   int n;
    cin >> n;
    vi v(n);
    read(v)
    ll lo = 0, hi = 1e9, md, ans = 0;
    while (lo <= hi) {
        md = lo + (hi - lo) / 2;
        debug(lo,hi,md);
        if (check(v,md)) {
            ans = md;
            lo = md + 1;
        }
        else
            hi = md - 1;
        debug(ans);
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

