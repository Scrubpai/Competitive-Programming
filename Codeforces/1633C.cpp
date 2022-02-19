#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll hc, dc, hm, dm, k, w, a; cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        for (int i=0; i<=k; i++) {
            ll health = hc + a*i, attack = dc + w*(k-i);
            if ((hm + attack - 1) /attack <= (health + dm - 1) / dm) {
                cout << "YES\n";
                goto next;
            }
        }
        cout << "NO\n";
        next: ;
    }
}