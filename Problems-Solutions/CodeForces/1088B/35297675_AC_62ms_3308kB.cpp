#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
    fast();
 int size,q,val=0;
 cin>>size>>q;
 ll arr[100001]={0};
    set<int>ar;
    for (int i = 0; i < size; ++i) {
        //cin>>arr[i];
        int s;
        cin >> s;
        ar.insert(s);
    }
    set<int>::iterator it=ar.begin();
    for (int i = 0; i < q; ++i) {
        if (it==ar.end()) {
            cout << "0\n";
            continue;
        }
        cout<<(*it-val)<<"\n";
        val+=(*it-val);
        it++;
    }
    return 0;
}