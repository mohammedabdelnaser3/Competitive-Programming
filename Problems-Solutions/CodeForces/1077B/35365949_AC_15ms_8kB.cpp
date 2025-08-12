#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fast();
    int n,ans=0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin>>arr[i];
    for (int i = 1; i < n-1; ++i) {
        if(arr[i]==0&&arr[i-1]==1&&arr[i+1]==1){
            arr[i+1]=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}