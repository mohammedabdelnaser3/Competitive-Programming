/*#include <bits/stdc++.h>
using namespace std;
int main() {
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
        cout << ans;
    return 0;
}
 */





#include <bits/stdc++.h>
using namespace std;


/*
int main() {
    int n,min,ans;
    cin>>n;
    map<int,int>days;
    for (int i = 1; i <=n ; ++i) {
        int t;
        cin>>t;
        days.insert({i,t});
    }
    min=days[1]+days[2];
    ans=days[1];
    for (int i = 1; i < n; ++i) {
        if(days[i]+days[i+1]<=min){
            min=days[i]+days[i+1];
            if (days[i]>days[i+1]){
                ans=days[i];
            }
            else
            {
                ans=days[i+1];
            }
        } else{
            continue;
        }
    }
    cout<<ans;
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
int t;
cin>>t;
while(t--) {
    int maxlong, cars, moves_lift = 0,moves_right;
    cin >> maxlong >> cars;
    maxlong *= 100;
    map<int, int> side_lift;
    map<int, int>::iterator it_lift = side_lift.begin();
    map<int, int> side_right;
    map<int, int>::iterator it_right = side_right.begin();
    for (int i = 1; i <= cars; ++i) {
        int len;
        string side;
        cin >> len >> side;
        if (side[0] == 'l') {
            side_lift.emplace_hint(it_lift, i, len);
            it_lift++;
        } else if (side[0] == 'r') {
            side_right.emplace_hint(it_right, i, len);
            it_right++;
        }

    }
    it_right = side_right.begin();
    it_lift = side_lift.begin();
    if (side_lift.empty()){
        moves_lift++;
    }
    else
    {
        auto it_lift1=it_lift;
        it_lift1++;
        int e=it_lift->second;
        for (int i = 0; i < side_lift.size(); ++i) {
            if(it_lift->first==(it_lift1->first-1) && (e+it_lift1->second)<=maxlong){
                e+=it_lift1->second;
                it_lift++;
                it_lift1++;
                continue;
            }
            else
            {
                side_lift.erase(side_lift.begin(),it_lift1);
                it_lift1++;
                it_lift=it_lift1;
                it_lift--;
                e=it_lift->second;
                moves_lift++;
            }
            if (it_lift->first==(it_lift1->first-1) && (e+it_lift1->second)>maxlong){
                side_lift.erase(side_lift.begin(),side_lift.find(it_lift1->first));
                it_lift++;
                it_lift1++;
                e=it_lift->second;
                moves_lift++;
            }
            if (it_lift->first!=(it_lift1->first-1))
            {
                side_lift.erase(side_lift.begin(),side_lift.find(it_lift1->first));
                it_lift++;
                it_lift1++;
                e=it_lift->second;
                moves_lift++;
            }
            if (!side_lift.empty()&&side_lift.size()==1) {
                moves_lift++;
                break;
            }
        }
    }
    if (!side_right.empty()) {
        auto it_right1 = it_right;
        it_right1++;
        int e = it_right->second;
        for (int i = 0; i < side_right.size(); ++i) {
            if (it_lift->first == (it_right1->first - 1) && (e + it_right1->second) <= maxlong) {
                e += it_right1->second;
                it_right++;
                it_right1++;
            } else {
                e = 0;
                side_right.erase(side_right.begin(), side_right.find(it_right1->first));
                moves_right++;
            }
            if (!side_right.empty() && side_right.size() == 1)
                moves_right++;
        }
    }
    cout<<moves_lift<<endl<<moves_right<<endl;
    if (moves_lift>moves_right)
        cout<<(moves_lift*2)-1<<endl;
    else
        cout<<moves_right*2<<endl;
}
    return 0;
}
*/


/*
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    string s;
    vector<char>money;
    cin>>s;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i-2]=='.')
            break;
        money.push_back(s[i]);
    }


    return 0;
}
*/

/*
int main(){
    int t,num;
    string name,taxi="taxi",pizza="pizza",girls="girls";
    cin>>t;
    map<string,map<string ,string>>phones;
    while (t--){
        cin>>num>>name;
        for (int i = 0; i < num; ++i) {
            string number;
            cin>>number;
            set<char>digit;
            digit.emplace(number[0]);
            digit.emplace(number[1]);
            digit.emplace(number[3]);
            digit.emplace(number[4]);
            digit.emplace(number[6]);
            digit.emplace(number[7]);
            if (digit.size()==6)
                phones.insert({pizza,{name,{phones[name]+1}}});
            else if(digit.size()==1)
                phones.insert({taxi,{name}});
            else
                phones.insert({girls,{name}});
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
}*/

//#include <bits/stdc++.h>

//using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int cars;
        int Long;

        cin >> Long >> cars;

        Long *= 100;
        vector<int> len(cars);
        vector< queue<int> > sides(2);

        for(int i = 0; i < cars; ++i)
        {
            int l;
            string side;
            cin >> l >> side;

            if(side[0] == 'l')
                sides[0].push(i);
            else
                sides[1].push(i);

            len[i] = l;
        }

        int side = 0;
        int moves = 0;

        while(!sides[0].empty() || !sides[1].empty())
        {
            int c = 0;
            while(!sides[side].empty() && len[sides[side].front()] + c <= Long)
            {
                c += len[sides[side].front()];
                sides[side].pop();
            }
            ++moves;
            side = (side + 1) % 2;
        }

        cout << moves << "\n";
    }

    return 0;
}