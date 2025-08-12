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
   int n,p2=60;
    while (true){
        cin>>n;
        if (n==0)
            break;
        bool f= true;
        int p1=0,p2=60,ans;
        while (p2<=60){
            ans= cubes(p2)- cubes(p1);
            if(ans>n)
                p2--;
            else if (ans<n){
                p2++;
                p1++;
            }
            else if (ans==n){
                f= false;
                cout<<p2<<" "<<p1<<"\n";
                break;
            }
        }
        if (f)
            cout<<"No solution\n";
//        for (int i = 0 ; i <=60 ; ++i) {
//            for (int j = 60; j > i ; --j) {
//                if (cubes(j)- cubes(i)==n){
//                    f= false;
//                    cout<<j<<" "<<i<<"\n";
//                    break;
//                }
//            }
//        }
//        if (f)
//            cout<<"No solution\n";
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