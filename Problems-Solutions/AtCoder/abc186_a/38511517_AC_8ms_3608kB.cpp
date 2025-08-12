
#include <bits/stdc++.h>
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
#define vt vector
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef pair <int, int> pii;
typedef vector<pair <int, int>> vpii;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
#define sz(x) ((int)(x).size())
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define dd double
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
/*vvi a,b,ans;
int ra,ca,rb,cb;*/

void solve(int t){
    int n,m;cin>>n>>m;
    cout<<n/m;
}
int main() {
    FAST();
    #ifndef ONLINE_JUDGE
       clock_t tStart = clock();freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w", stderr);
    #endif
    int t = 1;
    //cin >> t;
     for (int i = 1; i < t+1; ++i) solve(i);
    #ifndef ONLINE_JUDGE
        cerr<< "\n>> Runtime: "<< (double) (clock() - tStart) / CLOCKS_PER_SEC<<"s\n";
    #endif
    return 0;
}




