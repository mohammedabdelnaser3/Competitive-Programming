#include <bits/stdc++.h>
using namespace std;
/*
int main() {
    int n,ans;
    cin>>n;
    set<int>test;
    set<int>::iterator it=test.begin();
    vector<pair<int,bool>>day;
    vector<pair<int,bool>>::iterator it1=day.begin();
    for (int i = 0; i < n; ++i) {
        int k;
        cin>>k;
        test.insert(it,k);
        day.insert(it1,{k, true});
        it++;
        it1++;
    }
    it=test.begin();
    cout<<test.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (day[j].first==*it){
                day[j].second= false;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (day[j].second== false&&day[j+1].second== false){
                ans= max(day[j].first,day[j+1].first);
                cout<<ans;
                return 0;
            }
        }
        it++;
    }

    return 0;
}
*/
/*

typedef stack<string> ss;
typedef vector<ss> vss;

inline bool isValidCard(string c1, string c2)
{
    return c1[0] == c2[0] or c1[1] == c2[1];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string current;
    while (cin >> current and current != "#")
    {
        vss piles(1);
        piles[0].push(current);

        for (int i = 1; i < 52; ++i)
        {
            cin >> current;

            ss p;
            p.push(current);
            piles.push_back(p);
            bool change = false;

            do
            {
                change = false;

                for (int j = 1; j < piles.size(); ++j)
                {
                    current = piles[j].top();
                    int currentIndex = j - 1;

                    if (j > 2 and isValidCard(current, piles[j - 3].top()))
                        currentIndex -= 2;

                    string card = piles[currentIndex].top();
                    if (isValidCard(card, current))
                    {
                        piles[currentIndex].push(current);
                        piles[j].pop();

                        if (piles[j].empty())
                            piles.erase(piles.begin() + j);

                        change = true;
                        break;
                    }
                }

            } while(change);
        }

        cout << piles.size() << " pile" << (piles.size() == 1?" ":"s ") <<"remaining: ";

        for (int i = 0; i < piles.size(); ++i)
        {
            cout << piles[i].size();

            if (i + 1 != piles.size())
                cout << " ";
        }

        cout << "\n";
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


int main()
{
    char s[9];
    bool row[8] = {false}, col[8] = {false};
    for (int r = 0; r < 8; ++r)
    {
        cin>> s;
        for (int c = 0; c < 9; ++c)
        {
            if (s[c] == 'W')
            {
                row[r] = true;
                col[c] = true;
            }
        }
    }
    int answer = 16 - count(row, row + 8, true) - count(col, col + 8, true);
    if (answer == 16)
    {
        answer = 8;
    }
    cout<< answer;
    return 0;
}
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