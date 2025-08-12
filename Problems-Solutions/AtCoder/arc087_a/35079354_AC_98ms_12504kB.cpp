/*#include <bits/stdc++.h>
using namespace std;
int main() {
/*
    int t,counter=0;
    cin>>t;
    while (t--)
    {
        int n,pos,it;
        cin >> n>>pos;
        priority_queue<int>jobs;
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin>>k;
            jobs.push(k);
            if (i==pos)
            {
                it = k;
            }
            while (it!=jobs.top())
            {
                counter++;
                jobs.pop();
            }
            cout<<++counter;
        }
    }
    */

/*
int t;
cin>>t;
    while (t--){
        int n,r;
        cin>>n>>r;
        map<int,int>data;
        for (int i = 0; i < n; ++i) {
            int l,m;
            cin>>l>>m;
            data.insert(pair<int,int>(l,m));
        }
        for () {

        }
    }


    return 0;
}
*/




/*

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ip;

int max3(int x,int y,int z) {
    int mx;
    if (x>=y&&x>=z)
        mx=x;
    else if (y>=x&&y>=z)
        mx=y;
    else if (z>=x&&z>=y)
        mx=z;
    return mx; }
int min3(int x,int y,int z) {
    int mn;
    if (x<=y&&x<=z) mn=x;
    else if (y<=x&&y<=z)
        mn=y;
    else if (z<=x&&z<=y)
        mn=z;
    return mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int c=0;
    auto it=s.begin();
    for (;it!=s.end();it++){
        if (s.count(*it)!=*it){
            c+=(s.count(*it)-*it);
        }
    }
    cout << c;
    return 0;
}

*/



/*


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,ans;
    cin>>n;
    multiset<int>boxes;
    ans=n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin>>k;
        boxes.insert(k);
    }
    multiset <int> ::iterator it=boxes.end();
    it--;
    while (it!= prev(boxes.begin())) {
        x=*it;
        multiset <int> ::iterator it1=it;
        it1--;
        while (it1!= prev(boxes.begin())) {
            if (*it1<x){
                x=*it1;
                boxes.erase(it1);
                ans--;
            }
//            if (it1==boxes.begin())
//                break;
            it1--;
        }
       // if (it==boxes.begin())
         //   break;
        it--;
    }
cout<<ans;
    return 0;
}
 */





#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;

  cin>>n;
  multiset<int>seq;
  map<int,int>freq;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        seq.insert(t);
        freq.insert({t,0});
    }
    for (auto it:freq){
        int i=it.first;
        it.second=seq.count(i);
        if (it.first>it.second){
            ans+=it.second;
        }
        else if (it.second>it.first){
            ans+=(it.second-it.first);
        }
    }
    cout<<ans<<endl;


    return 0;
}
