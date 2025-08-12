#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast();
int t;
cin>>t;
while(t--) {
    int k, n,ans=1000000000;
    cin >> k >> n;
    ll arr[20001]={0};
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr, arr + k);
    for (int i = 0; i <= k - n; ++i) {
        int s=(arr[i+n-1]-arr[i]);
        ans = min(ans, s);
    }
cout<<ans<<endl;
}
    return 0;
}