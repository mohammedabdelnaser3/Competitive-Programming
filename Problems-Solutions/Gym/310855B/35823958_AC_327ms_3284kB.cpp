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
ll a,b;
cin>>a>>b;
      cout<<(a*(a-1))/2+(b*(b-1))/2;
}
void solve1(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    f(0,n)for (int j = 0; j < m; ++j) {
            cin>>arr[i][j];
        }
    f(0,m) {
        for (int j = 0; j < n; ++j) {
            cout << arr[j][i] << ' ';
        }
        cout<<endl;
    }
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