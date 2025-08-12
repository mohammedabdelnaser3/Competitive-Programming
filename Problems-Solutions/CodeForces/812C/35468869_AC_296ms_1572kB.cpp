#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int cubes(int n){
    return n*n*n;
}/*
int main(){
   int n;
    do{
        cin>>n;
        if (n==0)
            return 0;
       bool f= false;
       int min=INT_MAX,x,y;
       for (int i = 23 ; i >=0 ; --i) {
           for (int j = 0; j <= i ; ++j) {
               if (cubes(i)- cubes(j)==n){
                   f= true;
                   x=i;
                   y=j;
                   break;
               }
           }
           if (f)
               break;
       }
       if (f== false)
   cout<<"No solution\n";
   else
       cout<<x<<" "<<y<<"\n";
   } while (n!=0);
    return 0;
}*/
ll items[100001]={0},cost[100001]={0};
ll price(ll n,ll k){
    for (int i = 1; i <= n; ++i)
        cost[i]=(items[i]+(i*k));
    sort(cost,cost+n+1);
    for (int i = 1; i <=n ; ++i) {
        cost[i]+=cost[i-1];
    }
    return cost[k];
}
int main(){
    ll n,s;
    cin>>n>>s;
    for (int i = 1; i <=n ; ++i)
        cin >> items[i];
    int lo=0,hi=n,md,cost=0,k=0;
    while (lo<=hi){
        md=lo+(hi-lo)/2;
        if (price(n,md)==s) {
            cout << md << " " << s;
            return 0;
        }
        else if (price(n,md)>s)
            hi=md-1;
        else
        {
            cost= price(n,md);
            k=md;
            lo=md+1;
        }
    }
    cout<<k<<" "<<cost;
    return 0;
}