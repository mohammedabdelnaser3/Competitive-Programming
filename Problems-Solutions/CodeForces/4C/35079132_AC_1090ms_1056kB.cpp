#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<string,int>data;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        if (data.count(s)==true)
        {
            cout<<s<<++data[s]<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
            data.insert({s,0});
        }

    }
    return 0;
}