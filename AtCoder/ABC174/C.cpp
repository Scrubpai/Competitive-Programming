#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll k;
ll pwmd(ll b, ll exp) {
    ll ret = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ret = (ret * b) % k;
        exp /= 2;
        b = (b * b) % k;
    }
    return ret;
}
void solve(int tc) {
    cin >> k;
    if (k % 7 == 0) k /= 7;
    k *= 9;
    if (gcd(10, k) != 1) { cout << -1 << nl; return; }
    for (int i = 1; i < k; i++) {
        if (pwmd(10, i) == 1) { cout << i << nl; return; }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}