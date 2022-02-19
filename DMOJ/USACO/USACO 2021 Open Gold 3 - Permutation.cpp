#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
typedef array<int, 3> Tri;
#define x first
#define y second
const int mod = 1e9+7;
int N; ll dp[41][41][41], cnt[41][41][41], fac[41], inv[41], ans; pt p[41]; vector<Tri> triangles;
ll qpow(ll b, ll exp) {
    ll ret = 1;
    for (; exp; exp>>=1) {
        if (exp&1) ret = (ret * b) % mod;
        b = (b * b) % mod;
    }
    return ret;
}
void init() {
    fac[0] = inv[0] = 1;
    for (int i=1; i<=N; i++) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = qpow(fac[i], mod-2);
    }
}
ll perm(ll a, ll b) {
    return fac[a] * inv[a-b] % mod;
}
ll cross(pt a, pt b, pt c) {
    return abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
bool inside(pt a, pt b, pt c, pt d) {
    return (cross(a, b, c) + cross(a, c, d) + cross(a, d, b) == cross(b, c, d));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N; init();
    for (int i=1; i<=N; i++) cin >> p[i].x >> p[i].y;
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            for (int k=j+1; k<=N; k++) {
                triangles.push_back({i, j, k});
            }
        }
    }
    sort(triangles.begin(), triangles.end(), [&](Tri &a, Tri &b) { return cross(p[a[0]], p[a[1]], p[a[2]]) < cross(p[b[0]], p[b[1]], p[b[2]]); });
    Tri &lst = triangles.back();
    for (Tri &t: triangles) {
        int ins = 0;
        for (int i=1; i<=N; i++) {
            if (i == t[0] || i == t[1] || i == t[2]) continue;
            if (inside(p[i], p[t[0]], p[t[1]], p[t[2]])) ins++;
        }
        cnt[t[0]][t[1]][t[2]] = N-3-ins;
    }
    if (cnt[lst[0]][lst[1]][lst[2]]) { cout << 0 << '\n'; return 0; }
    dp[lst[0]][lst[1]][lst[2]] = 1;
    for (int i=(int)triangles.size()-1; i>=0; i--) {
        Tri &t = triangles[i];
        ll x = cnt[t[0]][t[1]][t[2]];
        for (int j=1; j<=N; j++) {
            if (j == t[0] || j == t[1] || j == t[2]) continue;
            for (int k=0; k<3; k++) {
                pt a = p[t[k]], b = p[t[(k+1)%3]], c = p[t[(k+2)%3]], d = p[j];
                if (inside(a, b, c, d)) {
                    array<int, 3> arr = {t[(k+1)%3], t[(k+2)%3], j}; sort(arr.begin(), arr.end());
                    ll y = cnt[arr[0]][arr[1]][arr[2]];
                    dp[t[0]][t[1]][t[2]] = (dp[t[0]][t[1]][t[2]] + perm(x-1, x-y-1) * dp[arr[0]][arr[1]][arr[2]] % mod) % mod;
                }
            }
        }
        ans = (ans + 6 * perm(N-3, N-3-cnt[t[0]][t[1]][t[2]]) % mod * dp[t[0]][t[1]][t[2]] % mod) % mod;
    }
    cout << ans << '\n';
}