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
    int n, ans = 0;
    cin >> n;
    vi v(n + 1), final, a(n);
    for (int i = 1; i <= n ; ++i)
        cin >> v[i];


    for (int i = 0; i < n; ++i) cin >> a[i];
    set<pair<int,pii>>left, right;
    while (n--){
        final.push_back(ans);
        int x = a[n];
        auto it1 = right.lower_bound({x - 1, {0, 0}}), it2 = left.lower_bound({x + 1, {0, 0}});
        pair<int, pii> t = {x, {x, v[x]}};
        if(it1 != right.end() && it1->first == x - 1) {
            t.first = it1->second.first;
            t.second = {x, v[x] + it1->second.second};
            left.erase({it1->second.first, {it1->first, it1->second.second}});
            right.erase(it1);
        }
        if (it2 != left.end() && it2->first == x + 1) {
            t.second.first = it2->second.first;
            t.second.second += it2->second.second;
            left.erase(it2);
            right.erase({it2->second.first, {it2->first, it2->second.second}});
        }
        left.insert(t);
        right.insert({t.second.first, {t.first, t.second.second}});
        ans = max(ans, t.second.second);
    }

    for (int i = final.size() - 1; i >= 0 ; --i)
        cout << final[i] << '\n';
}

void preprocess() {
}

int32_t main() {
    Fast_IO;
//    freopen("slalom.in", "r", stdin);
//    freopen("slalom.out", "w", stdout);
//    cout << fixed << sextprecision(9);
    int t = 1, cases = 1;
//    cin >> t;
    preprocess();
    while (t--) {
        // cout << "Case #" << cases++ << ": ";
        blow_it();
    }
    return (0 ^ _ ^ 0);
}
