#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int digit(ll x){
    ll ans=0;
    while (x>0){
        ans++;
        x/=10;
    }
    return ans;
}

int main(){
    fast();
    ull a,b,x,lo=0,hi,mid;
    cin>>a>>b>>x;
    ull ans=0;
        hi=1000000000;
    while (lo<=hi) {
        mid = lo + (hi - lo) / 2;
        if ((a * mid) + (b * digit(mid)) < x) {
            ans = mid;
            lo = mid+1;
        } else if ((a * mid) + (b * digit(mid)) > x) {
            hi = mid - 1;
        } else if ((a * mid) + (b * digit(mid)) == x) {
            cout << mid;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
/*
//bool check(int mid,int pos[],int n,int cows){
//    int ans=1;
//    int start=0;
//    for (int i = 1; i < n; ++i) {
//        if((pos[i]-pos[start])>=mid){
//            ans++;
//            start=i;
//            if (ans>=cows)
//                return true;
//        }
//    }
//        return false;
//}
//void bs(int n,int pos[],int cows){
//    int lo=1,hi=pos[n-1]-pos[0],ans;
//    while (lo<=hi){
//        int mid=(hi+lo)/2;
//        if (check(mid,pos,n,cows)){
//            ans=mid;
//            lo=mid+1;
//        }else {
//            hi=mid-1;
//        }
//    }
//    cout<<ans<<"\n";
//    return;
//}*/