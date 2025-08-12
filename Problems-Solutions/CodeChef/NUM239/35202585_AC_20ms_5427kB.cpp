#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
/*
void make_prefix(int n,long long prefix[]) {
    unsigned long long num;
    cin>>num;
    prefix[0]=num%10;
    num/=10;
    for(int i=1;i<n;i++) {
        prefix[i] = (num % 10)+prefix[i-1];
        num/=10;
    }
    //reverse(prefix,prefix+n);
    return;
}
*/
/*
void make_array(int n,ll sum1[]){
    sum1[0]=0;
for (int i = 1; i <= n; ++i)
cin>>sum1[i];
}
void prefix_sum(int n,ll sum1[]){
    for (int i = 0; i <= n; ++i)
        sum1[i]=sum1[i-1]+sum1[i];
}*/

/*
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 int t;
 cin>>t;
 while(t--){
     int n;
     cin>>n;
     ll arr[n];
     ll freq[100009]={0};
     memset(freq,0, sizeof(freq));
     for (int i = 0; i < n; ++i) {
     cin>>arr[i];
         freq[arr[i]]++;
     }
     for (int i = 0; i < n; ++i) {
             cout<<((freq[arr[i]]>1)? "ne krasivo\n":"prekrasnyy\n");
                break;
     }
 }
    return 0;
}*/
/*
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n;
        ll array[100001];
        ull sum[100001];
        for (int i = 0; i < n; ++i)
            cin>>array[i];
        sum[0]=array[0];
        for (int i = 1; i < n; ++i)
            sum[i]=array[i]+sum[i-1];
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << ((l==1)? sum[r-1]:(sum[r-1] - sum[l - 2]) )<< endl;
        }
    }
    return 0;
}
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        ll freq[100001]={0};
        memset(freq,0, sizeof(freq));
        int num1,num2;
        cin >> num1>>num2;
        for (int i = num1; i <= num2; ++i) {
            if (i%10==2||i%10==3||i%10==9)
                freq[i]++;
        }
        cout <<100001-count(freq,freq+100001,0)<<endl;
    }
    return 0;
}