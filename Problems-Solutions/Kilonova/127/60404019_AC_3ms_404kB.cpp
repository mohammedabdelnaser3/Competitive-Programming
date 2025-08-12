#include <fstream>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

// BeginCodeSnip{Modular Inverse and Binary Exponentiation functions}
ll pow(ll a, ll b, ll m) {
	ll res = 1;
	a %= m;  // to avoid overflows when a > 1e9
	while (b) {
		if (b & 1) { res = (res * a) % m; }
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

/** The extended Euclidean algorithm used to find the inverse */
void ext(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
	} else {
		ext(b, a % b, x, y);
		ll tem = x;
		x = y;
		y = tem - (a / b) * y;
	}
}

/** @return the modular inverse of a mod m */
ll inv(ll a, ll m) {
	ll x = 0, y = 0;
	ext(a, m, x, y);
	return (x + m) % m;
}
// EndCodeSnip

int main() {
	ifstream fin("sumdiv.in");
	ll a, b;
	fin >> a >> b;

	ofstream fout("sumdiv.out");
	if (b == 0) {
		fout << '1' << '\n';  // a^0 = 1
	} else {
		ll ans = 1;
		for (ll i = 2; i * i <= a; i++) {
			if (a % i == 0) {
				// if i divides a then it is always prime in this case
				// find the maximum power of i which divides a.
				ll co = 0;
				while (a % i == 0) {
					co++;
					a /= i;
				}
				// find the value of d - 1 and (d^k - 1) modulo (10^9 + 7).
				ll d_1 = inv((i - 1 + MOD) % MOD, MOD);
				ll dk_1 =
				    (pow(i, (co * (b % (MOD - 1)) + 1) % (MOD - 1), MOD) - 1 + MOD) %
				    MOD;
				ans = (ans * ((d_1 * dk_1) % MOD)) % MOD;
			}
		}

		if (a > 1 && ((a - 1) % MOD) != 0) {
			// if a is greater than 1 and a - 1 is not divisible by 10^9 + 7
			// find the value of d - 1 and (d^k - 1) modulo (10^9 + 7).
			ll d_1 = inv((a - 1 + MOD) % MOD, MOD);
			ll dk_1 = (pow(a, (b + 1) % (MOD - 1), MOD) - 1 + MOD) % MOD;
			ans = (ans * ((d_1 * dk_1) % MOD)) % MOD;
		} else if (a > 1) {
			/*
			 * if a - 1 is divisible by 10^9 + 7,
			 * a is a prime of the form k * (10^9 + 7) + 1.
			 * this means the sum of a^i modulo (10^9 + 7), where i goes from 0 to b
			 * is (b + 1), so we multiply by (b + 1).
			 */
			ans = (ans * ((b + 1) % MOD)) % MOD;
		}

		fout << ans << '\n';
	}
}