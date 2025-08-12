/*
*  Author:
*
* ╭━╮╭━╮╱╱╭━━━╮╭━━╮╱╭━━━╮╭━━━╮╭╮╱╱╱╭━╮╱╭╮╭━━━╮╭━━━╮╭━━━╮╭━━━╮╭━━━╮
* ┃┃╰╯┃┃╱╱┃╭━╮┃┃╭╮┃╱╰╮╭╮┃┃╭━━╯┃┃╱╱╱┃┃╰╮┃┃┃╭━╮┃┃╭━╮┃┃╭━╮┃┃╭━━╯┃╭━╮┃
* ┃╭╮╭╮┃╱╱┃┃╱┃┃┃╰╯╰╮╱┃┃┃┃┃╰━━╮┃┃╱╱╱┃╭╮╰╯┃┃┃╱┃┃┃╰━━╮┃╰━━╮┃╰━━╮┃╰━╯┃
* ┃┃┃┃┃┃╱╱┃╰━╯┃┃╭━╮┃╱┃┃┃┃┃╭━━╯┃┃╱╭╮┃┃╰╮┃┃┃╰━╯┃╰━━╮┃╰━━╮┃┃╭━━╯┃╭╮╭╯
* ┃┃┃┃┃┃╭╮┃╭━╮┃┃╰━╯┃╭╯╰╯┃┃╰━━╮┃╰━╯┃┃┃╱┃┃┃┃╭━╮┃┃╰━╯┃┃╰━╯┃┃╰━━╮┃┃┃╰╮
* ╰╯╰╯╰╯╰╯╰╯╱╰╯╰━━━╯╰━━━╯╰━━━╯╰━━━╯╰╯╱╰━╯╰╯╱╰╯╰━━━╯╰━━━╯╰━━━╯╰╯╰━╯
*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
#define _ 0
#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define ull unsigned long long
#define all(X) (X).begin(),(X).end()
#define allr(X) (X).rbegin(),(X).rend()
#define Take(X) for (auto &it:(X)) cin >> it;
#define Out(X) for (auto &it:(X))cout << it << " ";
#define TAKE(X, S) for (auto &it:(X)) cin >> it, (S) += it;
#define Fast_IO ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
const int mod = 998244353;
const double pi = acos(-1);
const ll oo = LLONG_MAX;
const int OO = 0x7f7f7f7f;

ll Lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }

int mult(int a, int b) { return (1LL * a * b) % mod; }

int mult(int a, int b, int mm) { return (1LL * a * b) % mm; }

int modSum(ll a, ll b) {
    a = (a % mod + mod) % mod, b = (b % mod + mod) % mod;
    return (a + b) % mod;
}

int modSub(ll a, ll b) { return modSum(a, -b); }
//___________________________________________________________________________

#define int ll
typedef vector<ll> vi;
typedef vector<pii > vpi;
typedef vector<ll> vl;
#define ld long double
const int N = 2e5 + 5;

void blow_it() {
    int n, ans = 1;
    cin >> n;
    vi edges[n + 1];
    vi inDeg(n + 1);
    vi order;
    for (int i = 1, m; i <= n; ++i) {
        cin >> m;
        inDeg[i] = m;
        for (int j = 0, u; j < m; ++j) {
            cin >> u;
            edges[u].emplace_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
        sort(all(edges[i]));

    set<int>s;
    for (int i = 1; i <= n; ++i)
        if(!inDeg[i])
            s.insert(i);

    int u = 0;
    while (!s.empty()){
        auto it = s.lower_bound(u);
        if(it == s.end())
            u = *s.begin();
        else
            u = *it;
        for(int &i : edges[u]) {
            --inDeg[i];
            if (!inDeg[i]) {
                s.insert(i);
            }
        }
        order.push_back(u);
        s.erase(u);
    }
    if(order.size() != n){
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < order.size() - 1; ++i) {
        ans += order[i] > order[i + 1];
    }
    cout << ans << '\n';
}

void preprocess() {
}

int32_t main() {
    Fast_IO;
//    freopen("censor.in", "r", stdin);
//    freopen("censor.out", "w", stdout);
//    cout << fixed << sextprecision(9);
    int t = 1, cases = 1;
    cin >> t;
    preprocess();
    while (t--) {
        // cout << "Case #" << cases++ << ": ";
        blow_it();
    }
    return (0 ^ _ ^ 0);
}
