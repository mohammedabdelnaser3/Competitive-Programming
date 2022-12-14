#include<bits/stdc++.h>
using namespace std;
/*#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif*/
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
ll power(ll x, ll i) { if (i == 0) return 1; else if (i % 2 == 0) return ((power(x, i / 2)%MOD) * (power(x, i / 2)%MOD))%MOD; else return ((x%MOD) * (power(x, i / 2)%MOD) * (power(x, i / 2)%MOD))%MOD;}
ll leastBit(ll num) { return (num & -num); }
void bitnum(ll num){if (num==0){cerr<<"\n";return;}bitnum(num>>1);cerr<<(num&1);}
void runTestCase() {
    int n,m;
    cin >> n >> m;
    vpii v(n+1,{0,0});
    vi  speed(n+1);
    loop1(i,n){
        cin >> v[i].ss >> speed[i];
        v[i].ss += v[i-1].ss;
        v[i].ff = v[i-1].ss;
    }
    vpii v1(m+1, {0, 0});
    vi  speed1(m+1);
    loop1(i,m){
        cin >> v1[i].ss >> speed1[i];
        v1[i].ss += v1[i-1].ss;
        v1[i].ff = v1[i-1].ss;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int temp = speed1[i];
        for (int j = 1; j <= n; ++j) {
            if (v[j].ff < v1[i].ss && v[j].ss > v1[i].ff)
                temp = min(temp,speed[j]);
        }
        ans = max(ans , speed1[i] - temp);
    }
    cout << ans;
}

int main() {
    FAST();
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--)
        runTestCase();
}
