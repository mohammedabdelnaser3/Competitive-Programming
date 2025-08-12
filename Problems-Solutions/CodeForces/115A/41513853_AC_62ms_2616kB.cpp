#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define FAST() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define read(x) for (auto &it:(x))cin >> it;
#define readpair(x) for (auto &it:(x))cin >> it.first >> it.second;
#define print(x) for (auto &it:(x))cout << it << " ";
#define printpair(x) for (auto it:(x))cout << it.first << " " << it.second << '\n';
#define prec(x) fixed<<setprecision(x)
#define skip continue
#define stop break
typedef unsigned int ui;
typedef long long ll;
// typedef __int128 lll;
#define ull unsigned long long
#define ld long double
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
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
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define loop(i, n) for(int i=0; i<n; i++)
#define loop1(i, n) for(int i=1; i<=n; i++)
#define loopi(i, s, e) for(int i=s; i <= e; i++)
#define loopiRev(i, s, e) for(int i=s; i >= e; i--)
#define sum_vt(x) accumulate(all(x),0)
#define each(x, y) for(auto &x:y)
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
ll di[] = {1, 0, -1, 0, 1, -1, 1, -1};
const ld pi = acos (-1);
const ll N = 1e5 + 5, MOD = 1e9 + 7;

ll Log2(ll i) {
    if (i <= 1)
        return 0;
    return Log2 (i / 2) + 1;
}
int mx = 0;
vi edges[N];
vb vis(N);
void bfs(int i,int ans = 0){
	if (vis[i]){
		mx = max(ans, mx);
		return;
	}
	vis[i] = true;
	each(it,edges[i])
		bfs(it, ans + 1);
	mx = max(ans, mx);
	vis[i] = false;
}
void runTestCase() {
	int n;
	cin >> n;
	loop(i,n){
		int x;
		cin >> x;
		if (x != -1){
			--x;
			edges[x].pb(i);
			debug(edges[x]);
			// edges[i].pb(x);
		}
	}
	loop(i,n){
		bfs(i, 0);
		vis[i] = false;
	}
	cout << mx + 1;
}

int main() {
	FAST();
    int t = 1;
   // cin >> t;
    while (t--)
        runTestCase ();
}