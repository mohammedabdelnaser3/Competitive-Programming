#include <bits/stdc++.h>
using namespace std;
#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
#define read(x) for (auto &it:(x))cin >> it;
#define readpair(x) for (auto &it:(x))cin >> it.first >> it.second;
#define print(x) for (auto &it:(x))cout << it << " ";
#define printpair(x) for (auto it:(x))cout << it.first << " " << it.second << '\n';
#define FOR(i , a , b) for (int i=a;i<b;i++)
#define prec(x) fixed<<setprecision(x)
#define READ(FILE) freopen(FILE,"r",stdin);
#define WRITE(FILE) freopen(FILE,"w",stdout);
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define pii pair<int,int>
#define sz(x) ((int)(x).size())
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
const double pi = 3.14159265359;
const int N = 2e5 + 1 , MOD = 1e9 + 7;
#ifndef ONLINE_JUDGE
	#define debug(x) cerr<<#x <<" ";debug_print(x); cerr<<'\n';
#else
	#define debug(x) 
#endif
template<class t> void debug_print(vector<t> v){cerr<<"[";for(t it:v)cerr<<it<<" ,";cerr<<"]";}
template<class t> void debug_print(set<t> v){cerr<<"[";for(t it:v)cerr<<it<<" ,";cerr<<"]";}
template<class t> void debug_print(multiset<t> v){cerr<<"[";for(t it:v)	cerr<<it<<" ,";cerr<<"]";}
template<class t,class c> void debug_print(map<t,c> v){cerr<<"[";for(auto it:v)cerr<<it.ff<<" ,"<<it.ss<<'\n';cerr<<"]";}
template<class t,class c> void debug_print(pair<t,c> v){cerr<<"["<<v.ff<<" ,"<<v.ss<<"]";}
void debug_print(int a){cerr<<a;}
void debug_print(double a){cerr<<a;}
void debug_print(ll a){cerr<<a;}
void debug_print(ld a){cerr<<a;}
void debug_print(char a){cerr<<a;}
void debug_print(string a){cerr<<a;}
void start(){
#ifndef ONLINE_JUDGE
freopen("Error.txt", "w", stderr);
#endif
}
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
void solve(){
		ll n;cin>>n;
		if (sqrt(n) != int(sqrt(n)) || n==1)
		{
			cout << "NO\n";
			return;
		}
		ll x = sqrt(n);
		for (ll i = 2; i*i <= x; ++i)
		{
			if (x%i==0)
			{
				cout<<"NO\n";
				return;
			}
		}
		cout<<"YES\n";
}

int main() {
    //READ("FILE");
    FAST();
    start();
    int t = 1;
    cin >> t;
    while (t--) {
    	solve();
     }
    return 0;
}