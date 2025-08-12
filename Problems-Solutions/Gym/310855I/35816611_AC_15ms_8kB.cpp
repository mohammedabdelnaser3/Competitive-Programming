#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define f(x,n) for(int i = x; i < (n); ++i)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll fac(int n){
    ll ans=1;
    for (int i = 1; i <= n; ++i) {
        ans*=i;
    }
    return ans;
}
void solve(){
ll a,b,c,d;
cin>>a>>b>>c>>d;
        //cout<<(log10(a)> pow(c,d))? "YES":"NO");
}
void solve1(){
    ll n,ans;
    cin>>n;
    ll lo=1,hi=1414213562,md;
    while (lo<=hi){
        md=lo+(hi-lo)/2;
        if((md*(md+1))/2<=n){
            ans=md;
            lo=md+1;
        }
        else
            hi=md-1;
    }
    cout<<ans;
}
int main() {

    fast()
    int t = 1;
    //cin>>t;
    while (t--) {
    solve1();

    }
    return 0;
}