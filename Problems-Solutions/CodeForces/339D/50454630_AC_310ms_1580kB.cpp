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

struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    bool build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            st[node] = v[start];
            return 1;
        }

        int mid = (start + ending) / 2;
        bool flag = build(start, mid, 2 * node + 1, v);

        build(mid + 1, ending, 2 * node + 2, v);

        if (flag)
            st[node] = st[node * 2 + 1] | st[node * 2 + 2];
        else
            st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];

        return !flag;
    }

    int query(int start, int ending, int l, int r, int node) {
        if (start > r || ending < l) {
            return 0;
        }

        if (start >= l && ending <= r) {
            return st[node];
        }

        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;
    }

    bool update(int start, int ending, int node, int index, int value) {
        if (start == ending) {
            st[node] = value;
            return 1;
        }

        int mid = (start + ending) / 2;
        bool flag;
        if (index <= mid)
            flag = update(start, mid, 2 * node + 1, index, value);
        else
            flag = update(mid + 1, ending, 2 * node + 2, index, value);
        if(flag)
            st[node] = st[node * 2 + 1] | st[node * 2 + 2];
        else
            st[node] = st[node * 2 + 1] ^ st[node * 2 + 2];

        return !flag;
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};


void blow_it() {
    int n, q;
    cin >> n >> q;

    vi v(1 << n);
    for(int &i : v) cin >> i;
    segmenttree st;
    st.init(1 << n);
    st.build(v);
    while (q--){
        int a, b;
        cin >> a >> b;
        st.update(--a, b);
        cout << st.query(0, (1 << n) - 1) << '\n';
    }
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
