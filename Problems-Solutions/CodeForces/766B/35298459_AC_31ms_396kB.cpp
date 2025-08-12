#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*
int main(){
    fast();
int t;
cin>>t;
    while (t--){
        int n,min1=0,min2=0,ans=0;
        cin>>n;
        int arr1[n];
        int arr2[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr1[i];
            min1=min(min1,arr1[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin>>arr1[i];
            min2=min(min2,arr2[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (arr1[i]>min1 &&arr2[i]>min2){
                int s=min((arr1[i]-min1),(arr2[i]-min2));
                ans+=s;
                arr1[i]-=s;
                arr2[i]-=s;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (arr1[i]>min1){
                ans+=(arr1[i]-min1);
            }
            if (arr2[i]>min2){
                ans+=(arr2[i]-min2);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}*/

int main(){
    fast();
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for (int i = 1; i < n-1; ++i) {
        int a,b,c;
        a=arr[i-1];
        b=arr[i];
        c=arr[i+1];
        if (a + b > c && a + c > b && b + c > a){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}