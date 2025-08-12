#include <iostream>
using namespace std;
using ll = long long;

const ll m = 1e9 + 7;
const ll n = 1e9 + 6;

ll mul(ll a, ll b) {
    return ((a % m) * (b % m)) % m;
}
ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll ret=1;
    if (b&1) ret=a%m;
    ll x=powmod(a,b/2);
    ret=mul(ret,mul(x,x));
    return ret%m;
}



ll pf(ll a, ll b) {
    ll ans = 1;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ll cnt = 0;
            while (a % i == 0) a /= i,cnt++;

            
            ll pow =(cnt * (b % n)) % n;
            ll x =(powmod(i, pow + 1) - 1 + m) % m;
            ll inv = powmod(i-1, m - 2);
            ans = mul(ans, mul(x, inv));
        }
    }
    if (a > 1) {
        if ((a-1)%m==0) ans=mul(ans,b+1);
        else {
            ll x = (powmod(a, b + 1) - 1 + m) % m;
            ll inv = powmod(a-1, m - 2);
            ans = mul(ans, mul(x, inv));
        }
    }

    return ans;
}

int main() {

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    ll a, b;
    cin >> a >> b;
    cout << pf(a,b);
}
