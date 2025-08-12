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
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n;
        ll sum1[100001];
        make_array(n,sum1);
        prefix_sum(n, sum1);
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << sum1[r] - sum1[l - 1] << endl;
        }
    }
    return 0;
}*/
/*
void test(){
    int n;
    string s;
    cin>>n>>s;
    map<int,int> cnt;
    cnt[0]++;
    ll sum=0,total=0;
    for(int i=0;i<n;i++)
    {
        sum+=(s[i]-'0')-1;
        total+=cnt[sum];
        cnt[sum]++;
    }
    cout<<total<<endl;
}
 */
/*
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--){
//        ull num;
//        ll arr[100001];
//        int size;
//        cin>>size>>num;
//        int i=0,sum=0,ans=0;
//        for (int i = 0; i < size; ++i){
//            arr[i]=(num%10);
//            num/=10;
//        }
//        reverse(arr,arr+size);
//        for (int j = 0; j < size; ++j) {
//            if (arr[j]==1)
//                ans++;
//            sum=arr[j];
//            for (int k = (j+1); k < size; ++k) {
//                sum+=arr[k];
//                if(sum ==(k-j+1))
//                    ans++;
//            }
//        }
//        cout<<ans<<endl;
    }
    }*/
int main(){
  /*  map<char,int>freq;
    map<char,int>pile;
    string name,host,letters;
    cin>>name>>host>>letters;
    for (int i = 0; i < name.size(); ++i) {
        if(freq.count(name[i]==0))
        freq.insert({name[i],1});
        else
            freq[name[i]]++;
    }
    for (int i = 0; i < host.size(); ++i) {
        if(freq.count(host[i]==0))
            freq.insert({host[i],1});
        else
            freq[host[i]]++;
    }
    for (int i = 0; i < letters.size(); ++i) {
        if(pile.count(letters[i]==0))
            pile.insert({letters[i],1});
        else
            pile[letters[i]]++;
    }
    map<char,int>::iterator it2=freq.begin();
    for (auto it1 =pile.begin(); it1 != pile.end(); ++it1) {
        if(it1->first==it2->first) {
            if (it1->second != it2->second) {
                cout << "NO";
                return 0;
            }
        }
        else{
            cout << "NO";
            return 0;
        }
        it2++;
    }
    cout<<"YES";
    */
 int freq[123]={0};
 int freq1[123]={0};
    memset(freq,0, sizeof(freq));
    memset(freq1,0, sizeof(freq1));
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (auto it:s1) {
        freq[int(it)]++;
    }
    for (auto it:s2) {
        if(it==' ')continue;
        freq1[int(it)]++;
        if (freq1[int(it)]>freq[int(it)]) {
            cout << "NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
