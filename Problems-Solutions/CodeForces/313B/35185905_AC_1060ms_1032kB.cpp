#include <bits/stdc++.h>
#include <time.h>
#include <ctime>
using namespace std;
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
int main(){
    clock_t start,end;
    start =clock();
   string s;
   int count=0,q;
   cin>>s>>q;
   long long freq[100001]={};
    for (int i = 1; i <s.size() ; ++i) {
        if(s[i]==s[i-1])
            count++;
        freq[i]=count;
    }
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin>>a>>b;
        cout<<freq[b-1]-freq[a-1]<<endl;
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