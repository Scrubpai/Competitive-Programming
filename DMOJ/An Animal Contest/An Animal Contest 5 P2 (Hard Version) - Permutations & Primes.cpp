#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+5;
int N; ll ans[MM];
ll ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    ll ret; cin >> ret; return ret;
}
void output() {
    cout << "! " << ans[1];
    for (int i=2; i<=N; i++) cout << " " << ans[i];
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    if (N == 4) {
        for (int i=1; i<=N; i++) ans[i] = i;
        ll x = ask(1, 3), y = ask(2, 4), z = ask(1, 4);
        do {
            if (ans[1] * ans[3] == x && ans[2] * ans[4] == y && ans[1] * ans[4] == z) { output(); return 0; }
        } while (next_permutation(ans+1, ans+1+N));
    } else if (N == 5) {
        for (int i=1; i<=N; i++) ans[i] = i;
        ll x = ask(1, 3), y = ask(3, 5), z = ask(2, 4), w = ask(2, 5);
        do {
            if (ans[1] * ans[3] == x && ans[3] * ans[5] == y && ans[2] * ans[4] == z && ans[2] * ans[5] == w) { output(); return 0; }
        } while (next_permutation(ans+1, ans+1+N));
    } else {
        ll x = ask(1, 3), y = ask(3, 6), z = ask(1, 6), tx = x, ty = y, tz = z; set<ll> st;
        ll g = __gcd(x, z); x /= g; z /= g; g = __gcd(y, z); y /= g; z /= g;
        for (int i=1; i<=N; i++) st.insert(i);
        for (int i=1; i<=N; i++) {
            if (1ll*i*i==x*y) {
                ans[3] = i; break;
            }
        }
        ans[1] = tx/ans[3]; ans[6] = ty/ans[3]; st.erase(ans[1]); st.erase(ans[3]); st.erase(ans[6]);
        for (int i=5; i<=N; i+=2) {
            x = ask(i-2, i);
            ans[i] = x/ans[i-2];
            st.erase(ans[i]);
        }
        x = ask(4, 6); ans[4] = x/ans[6]; st.erase(ans[4]);
        for (int i=8; i<=N; i+=2) {
            x = ask(i-2, i);
            ans[i] = x/ans[i-2];
            st.erase(ans[i]);
        }
        ans[2] = *st.begin();
    }
    output();
}