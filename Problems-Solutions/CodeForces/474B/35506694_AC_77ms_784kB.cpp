#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int cubes(int n){
    return n*n*n;
}
int main(){
    fast()
    ll n,m;
    cin>>n;
    ll arr[n+1];
    arr[0]=0;
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    cin>>m;
    for (int i = 0; i < m; ++i) {
        ll y;
        cin>>y;
        ll lo=0,hi=n,md,ans;
        while (lo<=hi){
            md=lo+(hi-lo)/2;
            if(arr[md]>=y) {
                ans = md;
                hi = md - 1;
            }
            else {
               lo=md+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
int main(){
    ll n,m,cntc=0,cntb=0;
    cin>>n>>m;
    map<ll,multiset<ll>>v;
    multimap<ll,ll>v1;
    for (int i = 0; i < n; ++i){
    ll x,y;
    cin>>x>>y;
        if (v.count(y)==true)
            v[y].insert(x);
        else
        v.insert({y,{x}});
    }
    for (int i = 0; i < m; ++i) {
    ll x,y;
    cin>>x>>y;
    v1.insert({x,y});
        if (v.count(y)==true) {
            cntc++;
           if (v[y].count(x)== true)
                cntb++;
                }
    }
cout<<cntc<<" "<<cntb;
}*/