#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){ 
fast();
ll t; 
cin>>t; 
while(t--) 
{
ll cnt=0,k=0,sum=0; 
ll n; 
string s, s1; 
cin>>n;
if(n%2 and n>=3)
s+='7', n-=3; 
while(n>1 and n%2==0)
{ 
s1+='1';
n-=2; 
}
s+=s1; 
cout<<s<<endl; 
} 
return 0;
}
