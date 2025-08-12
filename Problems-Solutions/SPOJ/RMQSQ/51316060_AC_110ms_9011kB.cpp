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

int Log2(int x) { return 31 - __builtin_clz(x); }

int ceiledLog2(int x) { return Log2(x) + (__builtin_popcount(x) != 1); }

template<typename T>
struct Segment_tree {
    int n, levels;
    vector<T> arr, tree, lazy;

    Segment_tree(vector<T> &v) {
        arr = v;
        n = arr.size();
        levels = ceiledLog2(n) + 1;
        tree.resize(1 << levels);
        lazy.resize(1 << levels);
        build(0, n - 1, 1);
    }

    T build(int l, int r, int v) {
        if (l == r)
            return tree[v] = arr[l];
        int m = (l + r) / 2;
        return tree[v] = min(build(l, m, 2 * v), build(m + 1, r, 2 * v + 1));
    }

    void propagate(int v) {
        if (lazy[v] == 0) return;
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        tree[2 * v] += lazy[v];
        tree[2 * v + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int l, int r, int v, int L, int R, T toAdd) {
        if (L > R) return;
        if (l == L && r == R) {
            lazy[v] += toAdd;
            tree[v] += toAdd;
            return;
        }
        propagate(v);
        int m = (l + r) / 2;
        update(l, m, 2 * v, L, min(R, m), toAdd);
        update(m + 1, r, 2 * v + 1, max(m + 1, L), R, toAdd);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    T query(int l, int r, int v, int L, int R) {
        if (L > R) return 2e9;
        if (l == L && r == R) return tree[v];
        propagate(v);
        int m = (l + r) / 2;
        return min(query(l, m, 2 * v, L, min(R, m)), query(m + 1, r, 2 * v + 1, max(L, m + 1), R));
    }

    T query(int l, int r) {
        return query(0, n - 1, 1, l, r);
    }

    void update(int l, int r, int v) {
        update(0, n - 1, 1, l, r, v);
    }

};

void blow_it() {
   int n, q;
   cin >> n;
   vi v(n);
   for(int &i : v) cin >> i;
   Segment_tree<int>st(v);
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}

void preprocess() {
}

int32_t main() {
    Fast_IO;
//    freopen("censor.in", "r", stdin);
//    freopen("censor.out", "w", stdout);
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
