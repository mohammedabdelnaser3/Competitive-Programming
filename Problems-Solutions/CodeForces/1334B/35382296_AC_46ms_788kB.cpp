#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    fast();
  int t;
  cin>>t;
  while(t--){
      ll n,saving,count=0,ans=0;
      cin>>n>>saving;
      ll arr[n];
      for (int i = 0; i < n; ++i) {
          cin>>arr[i];
      }
      sort(arr,arr+n);
      for (int i = n-1,j=1; i >=0 ; --i,++j) {
          count+=arr[i];
          if ((count/j)>=saving) {
              ans++;
              if(i==0)
                  cout<<n<<"\n";
              continue;
          }
          else{
              cout<<ans<<"\n";
              break;
          }
      }
     /* sort(arr,arr+n);
      for (int i = n-1; i >=0 ; --i) {
          if (arr[i]>saving) {
              count += (arr[i] - saving);
              ans++;
          }
          else if (arr[i]<saving&&count>=(saving-arr[i])){
              count-=(saving-arr[i]);
              arr[i]+=(saving-arr[i]);
              ans++;
          }
          else
              break;

      }
      cout<<ans<<"\n";
      */
  }
    return 0;
}