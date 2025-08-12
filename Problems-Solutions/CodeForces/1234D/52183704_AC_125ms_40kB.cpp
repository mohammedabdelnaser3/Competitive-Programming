/*
*  Author:
*
* ╭━╮╭━╮╱╱╭━━━╮╭━━╮╱╭━━━╮╭━━━╮╭╮╱╱╱╭━╮╱╭╮╭━━━╮╭━━━╮╭━━━╮╭━━━╮╭━━━╮
* ┃┃╰╯┃┃╱╱┃╭━╮┃┃╭╮┃╱╰╮╭╮┃┃╭━━╯┃┃╱╱╱┃┃╰╮┃┃┃╭━╮┃┃╭━╮┃┃╭━╮┃┃╭━━╯┃╭━╮┃
* ┃╭╮╭╮┃╱╱┃┃╱┃┃┃╰╯╰╮╱┃┃┃┃┃╰━━╮┃┃╱╱╱┃╭╮╰╯┃┃┃╱┃┃┃╰━━╮┃╰━━╮┃╰━━╮┃╰━╯┃
* ┃┃┃┃┃┃╱╱┃╰━╯┃┃╭━╮┃╱┃┃┃┃┃╭━━╯┃┃╱╭╮┃┃╰╮┃┃┃╰━╯┃╰━━╮┃╰━━╮┃┃╭━━╯┃╭╮╭╯
* ┃┃┃┃┃┃╭╮┃╭━╮┃┃╰━╯┃╭╯╰╯┃┃╰━━╮┃╰━╯┃┃┃╱┃┃┃┃╭━╮┃┃╰━╯┃┃╰━╯┃┃╰━━╮┃┃┃╰╮
* ╰╯╰╯╰╯╰╯╰╯╱╰╯╰━━━╯╰━━━╯╰━━━╯╰━━━╯╰╯╱╰━╯╰╯╱╰╯╰━━━╯╰━━━╯╰━━━╯╰╯╰━╯
*
*/

#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
/*
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;
*/
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

// void dbg() { cerr << endl; }
// template<typename Head, typename... Tail> void dbg(Head H, Tail... T) { cerr << ' ' << H; dbg(T...); }
// #ifndef ONLINE_JUDGE
// #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
// #else
// #define dbg(...)
// #endif
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

#define int long long
const int mod = 1e9 + 7;
const double pi = acos(-1);
const ll oo = LLONG_MAX;
const int OO = 0x7f7f7f7f;
/*___________________________________________________________________________*/
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int>> vpi;
#define ld long double
const int N = 100;


template<typename T>
struct segmentTree{
    int n = 0;
    vector<T> tree;
    segmentTree(string &v){
        n = v.size();
        tree.resize(4 * n);
        bulid(0, n - 1, 1, v);
    }
    T bulid(int l, int r, int node, string &v){
        if(l == r)
            return tree[node] = 1 << (v[l] - 'a');

        int mid = (l + r) >> 1;

        return tree[node] = bulid(l, mid, node * 2, v) | bulid(mid + 1, r, node * 2 + 1, v);
    }


    void update(int l, int r, int node, int indx, char val) {
        if (l == r) {
            tree[node] = 1 << (val - 'a');
            return;
        }
        int mid = (l + r) >> 1;
        if (indx <= mid) {
            update(l, mid, node * 2, indx, val);
        } else {
            update(mid + 1, r, node * 2 + 1, indx, val);
        }
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    }

    T query(int l, int r, int node, int L, int R) {
        if (L > r || R < l) {
            return 0;
        }
        if (L <= l && r <= R) {
            return tree[node];
        }
        int mid = (l + r) >> 1;
        return query(l, mid, node * 2, L, R) | query(mid + 1, r, node * 2 + 1, L, R);
    }

    void update(int idx, char val) {
        update(0, n - 1, 1, idx, val);
    }

    T query(int L, int R) {
        return query(0, n - 1, 1, L, R);
    }
};

void blow_it() {
    int q;
    string s;
    cin >> s >> q;
    segmentTree<bitset<26>>st(s);
    while(q--){
        int op;
        cin >> op;
        if( op == 1){
            int idx;
            char val;
            cin >> idx >> val;
            st.update(idx - 1, val);
        }else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            bitset<26>ans = st.query(l, r);
            cout << ans.count() << '\n';
        }
    }
}

void preprocess() {

}

int32_t main() {
    Fast_IO;
    freopen("erorr.txt", "w", stderr);
//    freopen("blist.in", "r", stdin);b
//    freopen("blist.out", "w", stdout);
//    cout << fixed << setprecision(9);
    int t = 1, cases = 1;
    // cin >> t;
    //std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
   preprocess();
    while (t--) {
        //cout << "Case #" << cases++ << ':' << endl;
        blow_it();
    }
    //std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //cerr << "Time : " << (end - start).count() / (1000000.0l) << " ms \n";
    return (0 ^ _ ^ 0);
}