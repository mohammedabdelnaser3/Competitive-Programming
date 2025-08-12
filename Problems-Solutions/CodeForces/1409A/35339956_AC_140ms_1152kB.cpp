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
    ld a, b,ans;
    ll test;
    cin >> a >> b;
    if (a == b)
        cout << "0\n";
    else if (a > b) {
    ans=((a - b) / 10.0);
        test=((a - b) / 10);
        cout <<((ans>test)? (test+1):test);cout<<"\n";
    }
    else if (b>a) {
        ans=((b - a) / 10.0);
        test=((b - a) / 10);
        cout <<((ans>test)? (test+1):test);cout<<"\n";
    }
}
    return 0;
}