#include <bits/stdc++.h>
#include <time.h>
#include <ctime>
using namespace std;
#define ll long long
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
void prefix_sum(int n,ll sum1[],ll sum2[]){
    sum1[0]=sum2[0]=0;
    for (int i = 1; i <= n; ++i) {
        cin>>sum1[i];
        sum2[i]=sum1[i];
    }
    sort(sum2,sum2+(n+1));
    for (int i = 1; i <=n ; ++i) {
        sum1[i]=sum1[i-1]+sum1[i];
        sum2[i]=sum2[i-1]+sum2[i];
    }
}
int main(){
    clock_t start,end;
    start =clock();
    int n,q;
    cin>>n;
    ll sum1[n+1];
    ll sum2[n+1];
    prefix_sum(n,sum1,sum2);
    cin>>q;
    while (q--){
        int t,l,r;
        cin>>t>>l>>r;
        if (t==1) cout<<sum1[r]-sum1[l-1]<<endl;
        if (t==2) cout<<sum2[r]-sum2[l-1]<<endl;
    }
    end=clock()-start;
    //cout<<"time="<<end/(double )CLOCKS_PER_SEC<<endl;
    return 0;
}

/*
 * int Q,n;
        cin>>n;
        long long vec[n + 1];
        long long freq[n + 1];
        make_prefix(n,vec,freq);
        cin>>Q;
        for (int i = 0; i < Q; ++i){
            int a, b;
            cin >> a >> b;
            if ((a - 1) == 0) {
                cout << freq[b]<<endl;
            }
            else {
                cout << freq[b] - freq[a - 1]<<endl;
            }
        }
 */