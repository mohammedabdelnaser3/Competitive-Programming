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
int n,r;
cin>>n>>r;
cout<<fac(n)/(fac(r)* fac(n-r))<<' '<<fac(n)/ fac(n-r);
}
int main() {

    fast()
    int t = 1;
    //cin>>t;
    while (t--) {
    solve();

    }
    return 0;
}