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

void dbg() { cerr << endl; }
template<typename Head, typename... Tail> void dbg(Head H, Tail... T) { cerr << ' ' << H; dbg(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif
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

const int mod = 1e9 + 7;
const double pi = acos(-1);
const ll oo = LLONG_MAX;
const int OO = 0x7f7f7f7f;
/*___________________________________________________________________________*/
#define int long long
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int>> vpi;
#define ld long double
const int N = 1e6 + 5;

int n, q;
struct node1 {
    int v, mx;
    node1 operator+(const node1& x) const {
        return {v + x.v, max(mx, x.mx)};
    }
    
};


vi tree, lazy, v;
vector<node1> tree1;

int build(int l = 0, int r = n-1, int node = 1){
    if(l == r)
        return tree[node] = v[l];
    return tree[node] = gcd(build(l, (r + l) / 2 ,node << 1) , build((r + l) / 2 + 1, r, (node << 1 )| 1));
}

node1 build1(int l = 0, int r = n - 1, int node = 1) {
    if (l == r) {
        tree1[node] = node1{v[l], v[l]};
        return tree1[node];
    }
    return tree1[node] = build1(l, (l + r) / 2, node << 1) + build1((l + r) / 2 + 1, r, (node << 1) | 1);
}

void prop(int node, int s, int e){
    if (lazy[node] == 0) return;
    tree[node] |= lazy[node];
    if (s != e) {
        lazy[node << 1] |= lazy[node];
        lazy[(node << 1) | 1] |= lazy[node];
    }
    lazy[node] = 0;
}

void update(int l,int r, int v, int node = 1, int s = 0, int e = n - 1){
    prop(node, s, e);
    if (s > r || e < l) return;
    if(s >= l && e <= r){
        lazy[node] |= v;
        prop(node, s, e);
        return;
    }
    update(l, r, v, node << 1, s, (e + s) / 2);
    update(l, r, v, (node << 1) | 1, (s + e) / 2 + 1, e);
    tree[node] = tree[node << 1] & tree[(node << 1) | 1];
}

int query(int l, int r, int node = 1, int s = 0, int e = n - 1){
    prop(node, s, e);
    if (s > r || e < l) return -1;
    if(l <= s && e <= r)return tree[node];
    return (query(l, r, node << 1, s, (s + e) / 2) & query(l, r, (node << 1) | 1, (s + e) / 2 + 1, e));
}
node1 query1(int l, int r, int node = 1, int s = 0, int e = n - 1) {
    if (s > r || e < l) return {0, 0};
    if (l <= s && e <= r) return tree1[node];
    int mid = (s + e) / 2;
    return query1(l, r, node << 1, s, mid) + query1(l, r, (node << 1) | 1, mid + 1, e);
}


void blow_it()  {
    cin >> n >> q;
    tree.resize(4 * n);
    lazy.resize(4 * n);
    vector<vi> querys;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        --l,--r;
        querys.push_back({l, r, k});
        update(l, r, k);
    }
    
    for (int i = 0; i < querys.size(); ++i){
        if(query(querys[i][0], querys[i][1]) != querys[i][2])
            return void(cout << "NO\n");
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << query(i,i) << ' ';


    /*sort(all(idx));
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    n = idx.size() - 1;
    dbg(idx);
    function<int(int)> get = [&](int v){
        return lower_bound(all(idx), v) - idx.begin();
    };
*/

}

void preprocess() {
}

int32_t main() {
    Fast_IO;
    freopen("erorr.txt", "w", stderr);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
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