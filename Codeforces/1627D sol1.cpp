#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, mx, ans, val[MM], nxt[MM]; bool vis[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0, a; i<n; i++) { cin >> a;val[a] = vis[a] = 1; mx = max(mx, a); }
    for (ll i=2; i<=mx; i++) {
        if (nxt[i]) continue;
        nxt[i] = i;
        for (ll j=i*i; j<=mx; j+=i) nxt[j] = i;
    }
    for (int i=mx; i>=1; i--) {
        if (val[i] == 1) {
            vector<int> vec; vec.push_back(1);
            int tmp = i;
            while (tmp > 1) {
                int div = nxt[tmp], sz = (int)vec.size();
                for (int j=0; j<sz; j++) vec.push_back(vec[j]*div);
                tmp /= nxt[tmp];
            }
            for (int num : vec) {
                if (!val[num]) val[num] = i/num;
                else val[num] = gcd(val[num], i/num);
            }
            if (!vis[i]) ans++;
        }
    }
    cout << ans << '\n';
}