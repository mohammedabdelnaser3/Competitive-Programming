#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;
const ll N = 1e6+5;
ll d[N];

void div () {
     for (int i = 1; i < N; ++i)
        for (int j = i ; j < N; j += i)
            d[j]++;
}

struct node {
    ll sum = 0;
    ll mx = 0;
    // change
    node() {
    }
    node(ll x) {
        sum = mx = x;
    }
    
};


struct segtree {
    ll tree_size;
    vector<node> segdata;

    segtree(ll n) {
        tree_size = 1;
        while (tree_size < n) tree_size <<= 1;
        segdata.assign(2 * tree_size, node());
    }

    // change
    node merge(node &lf, node &ri) {
        node ans = node();
        ans.sum = lf.sum + ri.sum;
        ans.mx = max(lf.mx,ri.mx);
        return ans;
    }

    void init(vector<ll> &arr, ll ni, ll lx, ll rx) {
        if (rx - lx == 1) {
            if(lx < arr.size())
                segdata[ni] = node(arr[lx]);
            return;
        }
        ll mid = (lx + rx) / 2;
        init(arr, 2 * ni + 1, lx, mid);
        init(arr, 2 * ni + 2, mid, rx);
        segdata[ni] = merge(segdata[2 * ni + 1], segdata[2 * ni + 2]);
    }

    void init(vector<ll> &arr) {
        init(arr, 0, 0, tree_size);
    }

    // change
    void set(ll l, ll r, ll ni, ll lx, ll rx) {
        if (lx >= r || rx <= l) return;
        if (segdata[ni].mx <= 2) return;
        if (rx - lx == 1) {
            segdata[ni].sum = segdata[ni].mx = d[segdata[ni].sum];
            return;
        }

        ll mid = (lx + rx) / 2;
        set(l, r, 2 * ni + 1, lx, mid);
        set(l, r, 2 * ni + 2, mid, rx);
        segdata[ni] = merge(segdata[2 * ni + 1], segdata[2 * ni + 2]);
    }

    void set(ll l, ll r) {
        set(l, r, 0, 0, tree_size);
    }

    node get(ll l, ll r, ll ni, ll lx, ll rx) {
        if (lx >= r || rx <= l) return node();
        if (lx >= l && rx <= r) return segdata[ni];
        ll mid = (lx + rx) / 2;
        node lf = get(l, r, 2 * ni + 1, lx, mid);
        node rf = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, rf);
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, tree_size).sum;
    }
};

int main() {
    div();
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segtree st(n);
    st.init(arr);

    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll l , r;
            cin >> l >> r; l--;
            st.set(l, r);
        } else if (op == 2) {
            ll l, r;
            cin >> l >> r; l--;
            cout << st.get(l, r) << '\n';
        }
    }
}
