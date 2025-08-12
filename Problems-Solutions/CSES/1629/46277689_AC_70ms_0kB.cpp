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


using namespace std;



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

/*___________________________________________________________________________*/
#define int ll
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<ll> vl;
#define ld long double
const int N = 2e5 + 5;

int ask(string s, int l, int r) {
    cout << s << ' ' << l << ' ' << r << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int sum(int l, int r) {
    int And = ask("and", l, r);
    int Or = ask("or", l, r);
    int Xor = ~And & Or;
    return 2 * And + Xor;
}

ll power(ll x, ll y) {
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return power(x, y / 2) * power(x, y / 2);
    else
        return x * power(x, y / 2) * power(x, y / 2);
}
void blow_it() {
    int n;
    cin >> n;
    vector<pair<int,int>>v(n);
    for(auto &i : v) cin >> i.second >> i.first;

    sort(all(v));
    int ans = 1, finished = v[0].first;
    for (int i = 1; i < n; ++i){
        if (v[i].second >= finished){
            ++ans;
            finished = v[i].first;
        }
    }

    cout << ans << '\n';

}


void preprocess() {

}


int32_t main() {
    Fast_IO;
//    freopen("dim_sum_delivery_input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    cout << fixed << setprecision(9);
    int t = 1, cases = 1;
    // cin >> t;
    //std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    preprocess();
    while (t--) {
        // cout << "Case #" << cases++ << ": ";
        blow_it();
    }
    //std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //cerr << "Time : " << (end - start).count() / (1000000.0l) << " ms \n";
    return (0 ^ _ ^ 0);
}