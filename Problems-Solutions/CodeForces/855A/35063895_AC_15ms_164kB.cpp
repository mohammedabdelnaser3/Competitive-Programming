#include <bits/stdc++.h>
using namespace std;
int main() {
/*
    int t,counter=0;
    cin>>t;
    while (t--)
    {
        int n,pos,it;
        cin >> n>>pos;
        priority_queue<int>jobs;
        for (int i = 0; i < n; ++i)
        {
            int k;
            cin>>k;
            jobs.push(k);
            if (i==pos)
            {
                it = k;
            }
            while (it!=jobs.top())
            {
                counter++;
                jobs.pop();
            }
            cout<<++counter;
        }
    }
    */
int n;
bool f;
cin>>n;
vector<string>names(n);
    for (int i = 0; i < n; ++i)
        cin>>names[i];
    for (int i = 0; i < n; ++i) {
        f = false;
        for (int j = 0; j < i; ++j) {
            if (names[i] == names[j]) {
                f = true;
                break;
            } else {
                continue;
            }

        }
        if (f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }


    return 0;
}










