#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define f(x,n) for(int i = x; i < (n); ++i)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
   ll n,ans=1;
   cin>>n;
    for (int i = 1; i<=n ; i++) {
    ans=(i*ans)%998244353;
    }
    cout<<ans;
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