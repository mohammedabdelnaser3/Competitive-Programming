#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*
int main(){
    fast();
 int size,q,val=0;
 cin>>size>>q;
 ll arr[100001]={0};
    for (int i = 0; i < size; ++i)
        cin>>arr[i];
    sort(arr,arr+size);
    for (int i = 0; i < q; ++i) {
        if((arr[i]==0||arr[i]-val==0) &&i<size){
            q++;
            continue;}
        if(arr[i]==0&&i>=size){
            cout<<arr[i]<<endl;
            continue;}
        cout<<arr[i]-val<<endl;
        val+=(arr[i]-val);
    }
    return 0;
}*/

int main(){
    fast();
    int n,sum1=0,i=0,ans=0;
    cin>>n;
    int arr[101]={0};
    for (int i = 0; i <n ; ++i) {
        cin>>arr[i];
        sum1+=arr[i];
    }
    sort(arr,arr+n);
    double sum2=4.5*n;
    while (sum1<sum2){
        sum1+=(5-arr[i]);
        i++;
        ans++;
    }
        cout<<ans;
}