#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
#define read(x) for (auto &it:(x))cin >> it;
#define readpair(x) for (auto &it:(x))cin >> it.first >> it.second;
#define print(x) for (auto &it:(x))cout << it << " ";
#define printpair(x) for (auto it:(x))cout << it.first << " " << it.second << '\n';
#define prec(x) fixed<<setprecision(x)
#define skip continue
#define stop break
#define ll long long
#define ull unsigned long long
#define ld long double
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef pair <int, int> pii;
typedef vector<pair <int, int>> vpii;
typedef vector<pair <ll, ll>> vpll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define dd double
#define Fill(x, n) memset(x, n, sizeof x)
#define sz(x) int(x.size())
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define loop(i,n) for(int i=0; i<n; i++)
#define loop1(i,n) for(int i=1; i<=n; i++)
#define loopi(i,s,e) for(int i=s; i <= e; i++)
#define loopiRev(i,s,e) for(int i=s; i >= e; i--)
#define sum_vt(x) accumulate(all(x),0)
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
ll di[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const ld pi = acos(-1);
const int N = 2e5 + 1 , MOD = 1e9 + 7;

void start(){
	FAST();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	freopen("error.txt", "w",stderr);
#endif
}

void runTestCase(){
    int n, counter = 0, ans = 0;
    cin >> n;
    debug(n);
    vi v(n);
    vb flag(1e9+5);
    priority_queue<int>q;
    loop(i,n) {
        cin >> v[i];
        if (flag[v[i]])
            counter++;
        if (!flag[v[i]]) {
            q.push(v[i]);
            flag[v[i]] = true;
        }
    }/*
    while (q.size()) {
        cerr << q.top() << '\n';
        q.pop();
    }*/
    debug(counter);
    loop1(i,n) {
        if (flag[i]) {
            debug(i,flag[i]);
            ans++;
            skip;
        }

        if (!flag[i] && (q.top() <= i || q.empty()) && !counter) {
            debug(i,q.top());
            ans = i - 1;
            stop;
        }

        if (!flag[i]) {
            debug(i,ans);
            if (counter > 1) {
                debug(i,counter,ans);
                counter -= 2;
                flag[i] = true;
                ans ++;
                debug(i,counter , ans);
            }
            else if (counter && q.top() > i && !q.empty()) {
                debug(i,counter,q.top(),ans);
                counter = 0;
                flag[q.top()] = false;
                q.pop();
                ans++;
                flag[i] = true;
                debug(i,counter,q.top(),ans);
            }
            else if (q.top() > i&& !q.empty()) {
                debug(i,q.top(),ans,q.empty());
                flag[q.top()] = false;
                q.pop();
                if (q.top() > i&& !q.empty()) {
                    flag[q.top()] = false;
                    q.pop();
                    ans++;
                    flag[i] = true;
                    debug(i,q.top(),ans,q.empty());
                }
                else
                    stop;
            }
            debug(i,ans);
        }
    }
    cout << ans << '\n';
}
int main() {
    start();
    int t = 1;
    //cin >> t;
    while (t--)
      runTestCase();
    return 0;
}

