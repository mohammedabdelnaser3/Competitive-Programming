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

vi v, tree;
void build(){
    // tree = v;
    for (int i = 1; i < tree.size(); ++i){
        int p = i + (i & -i);
        if(p < tree.size())
            tree[p] += tree[i];
    }
}

int qry(int l){
    int ans = 0;
    while(l){
        ans += tree[l];
        l -= l & -l;
    }
    // dbg(ans);
    return ans;
}

void add(int l, int x){
    while(l < tree.size()){
        tree[l] += x;
        l += l & -l;
    }
}

void blow_it()  {
    int n, q;
    cin >> n >> q;
    ++n;
    tree.resize(2 * n + 1);
    vi v(n - 1);
    for(int&i:v) cin >> i;
    vi edges[n];
    for (int i = 0, u, v; i < n - 2; ++i){
        cin >> u >> v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
    vi s(n), e(n), tf;
    int timer = 1;
    function<void(int)> dfs = [&](int node){
        s[node] = timer++;
        tf.emplace_back(node);
        for(auto & child: edges[node])
            if(!s[child])
                dfs(child);
        e[node] = timer++;
        tf.emplace_back(node);
    };

    dfs(1);
    for (int i = 0; i < n - 1; ++i)
        tree[s[i + 1]] = v[i];
    
    build();
    dbg(tree);

    while(q--){
        int op, l, x;
        cin >> op >> l;
        // dbg(op, l);
        if(op == 1){
            cin >> x;
            add(s[l], x - v[l - 1]);
            v[l-1] = x;
            //dbg(tree);
        }else{
            dbg(e[l], s[l], qry(e[l]));
            cout << qry(e[l]) - qry(s[l] - 1) << '\n';
        }
        
    }
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