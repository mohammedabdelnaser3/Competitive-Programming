#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(v) v.begin(),v.end()
#define f(x,n) for(int i = x; i < (n); ++i)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
    int n;
    cin>>n;
    int arr[n][n];
    f(0,n){
        for (int j = 0; j <= i; ++j) {
            if (j==i||j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
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