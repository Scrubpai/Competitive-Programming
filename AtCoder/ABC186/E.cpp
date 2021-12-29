#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
ll inv(ll a, ll m){
    ll b=m, x=1, y=0;
    while(b>0){
        ll t=a/b;
        swap(a-=t*b, b);
        swap(x-=t*y, y);
    }
    return (x%m+m)%m;
}
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll n, s, k;
void solve(int tc) {
    cin >> n >> s >> k;
    /*
     * Let x be the answer
     * S + x * k = 0 (mod N)
     *
     * S + x * k is a multiple of N. i.e. = y * N
     * S + x * k = y * N
     * y * N - x * k = S. Linear Diophantine Equation.
     * There exists a sol only if gcd(N, k) is a divisor of S.
     *
     * Anyway
     * S + x * k = 0 (mod N)
     * x = -S / k (mod N)
     * x = (N-S) * inv(k)
     */
    ll g = gcd(n, k);
    if (s % g != 0) { cout << -1 << nl; return; }
    n /= g; k /= g; s /= g;
    cout << inv(k, n) * (n - s) % n << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}