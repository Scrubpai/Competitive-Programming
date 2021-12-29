#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define nl '\n'

const int MM = 2e5 + 5;
ll n, a[MM]; set<pii> st;

void solve(int tc) {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll sum = 0; int k = -1;
        for (int j = 31; j >= 0; j--) {
            if (a[i] & (1 << j)) { k = j; break; }
        }
        for (int j = i; j >= 1; j--) {
            sum += a[j];
            if (sum - a[j] - a[i] > (1 << (k + 1))) break;
            if (i - j + 1 >= 3 && (a[i] ^ a[j]) == sum - a[i] - a[j]) {
                st.insert({j, i});
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        ll sum = 0; int k = -1;
        for (int j = 31; j >= 0; j--) {
            if (a[i] & (1 << j)) { k = j; break; }
        }
        for (int j = i; j <= n; j++) {
            sum += a[j];
            if (sum - a[j] - a[i] > (1 << (k + 1))) break;
            if (j - i + 1 >= 3 && (a[i] ^ a[j]) == sum - a[i] - a[j]) {
                st.insert({i, j});
            }
        }
    }
    cout << st.size() << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}