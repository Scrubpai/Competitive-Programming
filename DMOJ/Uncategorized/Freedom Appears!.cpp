#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, ll> pll;
int N; ll sx, sy, sz, x, y, z; set<pll> st;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%lld %lld %lld %d", &sx, &sy, &sz, &N);
    for (int i=0; i<N; i++) {
        scanf("%lld %lld %lld", &x, &y, &z);
        ll dx = x-sx, dy = y-sy, dz = z-sz, g = gcd(gcd(abs(dx), abs(dy)), abs(dz));
        st.insert({{dx/g, dy/g}, dz/g});
    }
    cout << st.size() << '\n';
    return 0;
}