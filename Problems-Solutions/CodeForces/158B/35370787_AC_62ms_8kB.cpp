#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){ 
fast();
int n, s, freq[5]= {0}; 
cin>>n; 
while (n--) { 
cin>>s; 
freq[s] ++;
} 
int ans = freq[4] + freq[3] + freq[2] /2; 
freq[1] -= freq[3];
if (freq[2] % 2 == 1) { 
ans += 1;
freq[1] -= 2; 
} 
if (freq[1] > 0) { 
ans += (freq[1] + 3) / 4; 
} 
cout<<ans; 
return 0;
}

