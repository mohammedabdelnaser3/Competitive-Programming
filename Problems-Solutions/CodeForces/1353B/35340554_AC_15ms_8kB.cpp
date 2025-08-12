#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast();
int t;
cin>>t;
while(t--) {
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for (int i = 0; i <n ; ++i)
        cin>>a[i];
    for (int i = 0; i < n; ++i)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for (int i = 0; i < k; ++i) {
        if (b[n-i-1]>a[i])
            swap(b[n-i-1],a[i]);
        else break;
    } int sum=0;
    for (auto it:a)
        sum+=it;
    cout<<sum<<"\n";
    }
    return 0;
}