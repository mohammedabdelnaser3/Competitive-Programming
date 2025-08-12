#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ()ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){
ll freq[30]={0};
ll odd=0; 
string s; 
cin>>s; 
for(int i=0; i<s.length(); i++) 
freq[s[i]-'a']++; 
for(int i=0; i<26; i++) { 
if(freq[i]&1) 
odd++;
} 
if( (odd==0) || (odd&1)) 
cout<<"First"<<endl;
else 
cout<<"Second"<<endl;
return 0;
}
