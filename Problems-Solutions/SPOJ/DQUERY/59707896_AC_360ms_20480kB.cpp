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
const int block = 320;

struct query{
    int l, r, i;

    bool operator<(query &other){
        return l / block != other.l / block ?
         l / block < other.l / block : r < other.r;
    }
};

int n, q;
int arr[N], out[N], freq[N];
query queries[N];
int curr = 0;

void add(int i){
    curr += (freq[arr[i]] == 0);
    freq[arr[i]]++;
}

void remove(int i){
    freq[arr[i]]--;
    curr -= (freq[arr[i]] == 0);
    
}

void blow_it()  {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].i = i;
    }

    sort(queries, queries + q);
    int s = 0, e = -1;
    for (int i = 0; i < q; ++i){
        int l = queries[i].l, r = queries[i].r, j = queries[i].i;
        
        while(e < r)
            ++e, add(e);
        while(s > l)
            --s, add(s);


        while(e > r)
            remove(e), e--;
        while(s < l)
            remove(s), s++;

        out[j] = curr;
    }

    for (int i = 0; i < q; ++i)
        cout << out[i] << '\n';
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