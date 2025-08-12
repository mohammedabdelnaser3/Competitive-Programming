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
const int maxChar = 26;

class Trie {
public:
    struct node {
        vector<node *> child;
        bool leaf;
        int mx = 0, word = 0;

        node() {
            child = vector<node *>(2, NULL);
            leaf = true;
            mx = word = 0;
        }
    };

    node *root = new node;

    void build(int x) {
        node *current = root;
//        current->tot += 1;

        for (int i = 31; i >= 0; --i) {
            int ch = ((1 << i) & x ? 1 : 0);

            if (current->child[ch] == NULL) {
                current->leaf = false;
                current->child[ch] = new node;
            }

            current = current->child[ch];
//            current->tot += 1;
        }

//        current->tot += 1;
    }

    void destroy(int x) {
        node *current = root;
//        current->tot -= 1;

        for (int i = 31; i >= 0; --i) {
            int ch = ((1 << i) & x ? 1 : 0);
            current = current->child[ch];
//            current->tot -= 1;
        }

//        current->tot -= 1;
    }
};

struct segmenttree {
    int n;
    vector<int> st;
    vector<multiset<int>>divs;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n);
        divs.resize(n);
    }

    void build(int start, int ending, int node, vector<int> &v) {
        if (start == ending) {
            if(!divs[start].empty()) {
                st[node] = *divs[start].begin();
                divs[start].erase(divs[start].begin());
            }
            else{
                st[node] = 1;
            }
            return;
        }

        int mid = (start + ending) / 2;

        build(start, mid, 2 * node + 1, v);

        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = max(st[node * 2 + 1] , st[node * 2 + 2]);
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return max(q1, q2);
    }

    void update(int start, int ending, int node, int l, int r) {
        // base case
        if(st[node] == 1)
            return;

        if (start == ending) {
            if (divs[start].empty())
                st[node] = 1;
            else {
                st[node] = *divs[start].begin();
                divs[start].erase(divs[start].begin());
            }

            return;
        }

        int mid = (start + ending) / 2;

        if(l <=  mid ){
            update(start, mid, 2 * node + 1, l, r);
        }
        if(r > mid){
            update(mid + 1, ending, 2 * node + 2, l, r);
        }
        int x = 1, y = 1;
        x = st[node * 2 + 1];
        y = st[node * 2 + 2];
        st[node] = {max(x, y)};
        return;
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
    int n, m;
    cin >> n >> m;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    segmenttree st;
    st.init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j * j <= v[i] ; ++j) {
            while (v[i] % j == 0){
                st.divs[i].insert(j);
                v[i] /= j;
            }
        }
        if(v[i] != 1)
            st.divs[i].insert(v[i]);
    }
    st.build(v);
    while (m--){
        int op, l, r;
        cin >> op >> l >> r;
        if(op)
            cout << st.query(--l, --r) << ' ';
        else
            st.update(--l, --r);
    }
    cout << '\n';
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
