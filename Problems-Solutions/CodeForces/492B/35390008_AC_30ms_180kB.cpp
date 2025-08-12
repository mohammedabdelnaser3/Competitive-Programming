#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast();
    ll n;
     ld ans=0,dif,l;
    cin>>n>>l;
    ld arr[n],arr1[n+1];
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = 0; i <= n; ++i) {
        if (i==0){
           arr1[i]=arr[i];
            ans= max(ans,arr1[i]);
        }
        else if(i==n){
            arr1[i]=(l-arr[i-1]);
            ans= max(ans,arr1[i]);
        }
        else
        {
            arr1[i]=(arr[i]-arr[i-1])/2.0;
            ans= max(ans,arr1[i]);
        }
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}