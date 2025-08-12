#include <bits/stdc++.h>
using namespace std;

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define take(x) for (auto &it:(x))cin >> it;
#define takepair(x) for (auto &it:(x))cin >> it.first >> it.second;
#define print(x) for (auto &it:(x))cout << it << " ";
#define printpair(x) for (auto it:(x))cout << it.first << " " << it.second << '\n';
#define prec(x) fixed<<setprecision(x)
#define mem(x,n) memset(x,n,sizeof x)
#define sz(x) x.size()
#define r(x) v.erase(remove(all(v),x),v.end())
#define READ(FILE) freopen(FILE,"r",stdin);
#define WRITE(FILE) freopen(FILE,"w",stdout);
#define ll long long
#define ull unsigned long long
#define ld long double
#define pq priority_queue
#define pb push_back
#define F first
#define S second
const double pi=3.14159265359;
const int N=1e5+1;
const int MOD=1e9+7;

bool isprime(int n){
    for (int i = 2; i <= sqrt(n) ; ++i) {
        if (n%i==0)
            return false;
    }
    return true;
}
void solve() {
    int n;
    cin>>n;
    map<int,int>m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        m[x]++;
    }
    for (auto it:m) {
        if (it.S!=1){
            cout<<"ne krasivo\n";
            return;
        }
    }
    cout<<"prekrasnyy\n";

}
void solve1(){


}
void solve2(){

}
void solve3(){


}
int main(){
    //READ("FILE");
    FAST();
    int t=1;
   cin >> t;
    while (t--){
        solve();
        //solve1();
        //solve2();
        //solve3();
    }
    return 0;
}
