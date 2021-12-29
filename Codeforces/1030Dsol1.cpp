#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
#define nl '\n'
ll n, m, k, cntn[MM], cntm[MM], pn = -1, pm = -1;
void solve(int tc) {
    cin >> n >> m >> k;
    ll tmp = n;
    for (int i = 2; i <= sqrt(1e9); i++) {
        while (tmp > 1 && tmp % i == 0) {
            tmp /= i;
            cntn[i]++;
        }
    }
    if (tmp > 1) pn = tmp;
    tmp = m;
    for (int i = 2; i <= sqrt(1e9); i++) {
        while (tmp > 1 && tmp % i == 0) {
            tmp /= i;
            cntm[i]++;
        }
    }
    if (tmp > 1) pm = tmp;
    bool flag = 0; tmp = k;
    for (int i = 2; i <= sqrt(1e9); i++) {
        while (tmp > 1 && tmp % i == 0) {
            if (cntn[i]) {
                if (!flag) { flag = 1; cntn[2]++; }
                cntn[i]--;
            } else if (cntm[i]) {
                if (!flag) { flag = 1; cntm[2]++; }
                cntm[i]--;
            } else if (!flag && i == 2) {
                flag = 1;
            } else {
                cout << "NO" << nl; return;
            }
            tmp /= i;
        }
    }
    if (tmp > 1) {
        if (pn == tmp) pn = -1;
        else if (pm == tmp) pm = -1;
        else { cout << "NO" << nl; return; }
    }
    ll b = 1, h = 1;
    if (pn != -1) b = pn;
    if (pm != -1) h = pm;
    for (int i = 2; i <= sqrt(1e9); i++) {
        while (cntn[i] > 0) {
            b *= i;
            cntn[i]--;
        }
        while (cntm[i] > 0) {
            h *= i;
            cntm[i]--;
        }
    }
    cout << "YES" << nl << 0 << " " << 0 << nl << b << " " << 0 << nl << b << " " << h << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}