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
ll t,x;
int n;
cin>>t>>n>>x;
    if (t==1){
        ll p=0,sum=0;
        while (n>0){
              sum+=(n%10)* pow(x,p);
              n/=10;
              p++;
        }
        cout<<sum;
        return;
    }
    else{
        ll ans=0;
        while (n>0){
           ans*=10;
           ans+=(n%x);
           n/=x;
        }
        cout<<ans;
    }
}
void solve1() {
    int r1, c1;
    cin >> r1 >> c1;
    int arr[r1][c1];
    f(0, r1)for (int j = 0; j < c1; ++j) {
            cin >> arr[i][j];
        }
    int r2, c2;
    cin >> r2 >> c2;
    int arr1[r2][c2];
    f(0, r2) {
        for (int j = 0; j < c2; ++j) {
            cin >> arr1[i][j];
        }
    }
    int arr2[r1][c2];
    /* for (int i = 0; i < ; ++i) {
         for (int j = 0; j < ; ++j) {
             for (int k = 0; k < ; ++k) {

             }
         }
     }
    */
}
void solve3(){
    ll n;
    cin>>n;
    cout<<n/2520;
}

int main() {

    fast()
    int t = 1;
    //cin>>t;
    while (t--) {
    solve3();

    }
    return 0;
}