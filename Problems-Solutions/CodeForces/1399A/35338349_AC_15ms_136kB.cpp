#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast();
int t;
cin>>t;
while(t--) {
    bool f= false;
    int n;
    cin>>n;
    set<int>arr;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        arr.insert(s);
    }
    if(arr.size()==1){
        cout<<"YES\n";
        continue;
    }
    set<int>::iterator it=arr.begin();
    set<int>::iterator it1=arr.begin();
    it1++;
    for (; it1 !=arr.end(); ++it,++it1) {
        if (*it - *it1 > 1 || *it1 - *it > 1 ) {
            f= true;
            break;
        }
    }
    cout<<((f== true)? "NO\n":"YES\n");
 }
    return 0;
}