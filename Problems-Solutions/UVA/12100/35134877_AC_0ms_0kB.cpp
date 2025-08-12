#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--)
    {
        multiset<int,greater<int>>test;
        int n,pos,time=0;
        cin >> n>>pos;
        queue<pair<int,int>>jobs;
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin>>k;
            test.insert({k});
            jobs.push({k,i});
        }
        while (true){
            auto it=test.begin();
            if (jobs.front().second==pos&&jobs.front().first==*it){
                time++;
                break;
            }
            if (jobs.front().first==*it){
                jobs.pop();
                time++;
                test.erase(it);
            }else
            {
                jobs.push(jobs.front());
                jobs.pop();
            }
        }
        cout<<time<<endl;
    }
    return 0;
}

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


}
 */





//#include <bits/stdc++.h>
//using namespace std;


/*
int main() {

    return 0;
}
*/
/*
int main()
{


	return 0;
}
*/

/*
int main(){
    int n,x,t;
    cin>>n>>x;
    t=x;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        if (a>b){
            while (x<b)
                x++;
        } else if (b>a){
            while (x<a)
                x++;
        }
    }
    if(t==x)
    cout<<-1;
    else
        cout<<x-t;

    return 0;
}
*/
/*
int main(){
    int n,x;
    cin>>n>>x;
    multiset<int>pos;
    for (int i = 1; i <= n; ++i) {
        int a,b;
        cin>>a>>b;
        pos.insert(a);
        pos.insert(b);
    }
    auto it=pos.begin();
    for (int i = 1; i <n ; ++i) {
      ++it;
    }
    if (x<*it){
        cout<<*it-x;
    }else{
        cout<<"-1";
    }


 return 0;
}*/

/*
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
*/


/*
int main(){


    return 0;
}
*/
/*
int main(){
    int t,num;
    string name,taxi="taxi",pizza="pizza",girls="girls";
    cin>>t;
    map<string,map<string,int>>friends;
    map<string,multiset<string>>phones;
    while (t--) {
        cin >> num >> name;
        for (int i = 0; i < num; ++i) {
            string number;
            cin >> number;
            set<char> digit;
            digit.emplace(number[0]);
            digit.emplace(number[1]);
            digit.emplace(number[3]);
            digit.emplace(number[4]);
            digit.emplace(number[6]);
            digit.emplace(number[7]);
            if (digit.size() == 6)
                phones.insert({pizza, {name}});
            else if (digit.size() == 1)
                phones.insert({taxi, {name}});
            else
                phones.insert({girls, {name}});

            int c=phones[taxi].count(name);
            friends.insert({taxi, {name, {c}}});
            friends.insert({pizza, {name, {phones[pizza].count(name)}}});
            friends.insert({girls, {name, {phones[girls].count(name)}}});
        }
    }
    cout<<"If you want to call a taxi, you should call: ";
    for (auto it1:phones[taxi]) {
        cout<<it1;
        //if (it1 != phones[taxi].begin())
          //  cout<<", "<<it1;
    }
    cout<<endl;
    cout<<"If you want to order a pizza, you should call: ";
    for (auto it1:phones[pizza]){
        //auto it=phones[pizza].begin();
        //if (it1 != *it)
          //  cout<<", "<<it1;
        //else
            cout<<it1;
    }
    cout<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    for (auto it1:phones[girls]) {
        cout<<it1;
        //if (it1 != phones[girls].begin())
          //  cout<<", "<<*it1;
    }
    cout<<endl;




    return 0;
}
*/
/*
int main()
{

    return 0;
}*/