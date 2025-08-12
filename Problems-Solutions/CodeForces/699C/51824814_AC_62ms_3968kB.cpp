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
const int N = 100;


void blow_it() {
    int n;
    cin >> n;
    vi v(n);
    int arr[n][2] = {};
    for(int i = 0; i < n ; ++i){
        cin >> v[i];
        if(v[i] == 1)
            arr[i][0] = 1;
        else if(v[i] == 2)
            arr[i][1] = 1;
        else if(v[i] == 3)
            arr[i][0] = arr[i][1] = 1;
    }

    int dp[n][2];
    memset(dp, -1, sizeof(dp));

    function<int(int, int)> solve = [&](int i,int j){
        if(i == n)
            return 0ll;
        if(~dp[i][j])
            return dp[i][j];

        return dp[i][j] = max(solve(i + 1, j), solve(i + 1, !j) + arr[i][j]);
    };


    /*dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dbg(dp[0][0], dp[0][1]);
    for (int i = 1; i < n; ++i){
        dp[i][0] = dp[i - 1][1] + arr[i][0];
        dp[i][1] = dp[i - 1][0] + arr[i][1];
        dbg(dp[i][0], dp[i][1]);
    }
*/
    cout << n - max(solve(0, 0), solve(0, 1)) << '\n';
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