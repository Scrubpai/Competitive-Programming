#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
typedef long long ll;
#define nl '\n'
int n; ll k, a[MM], cnt[MM]; vector<int> val; unordered_map<int, int> mp;
void solve(int tc) {
    cin >> n >> k; val.push_back(0);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
        val.push_back(a[i]);
    }
    if (k > tot) { cout << -1 << nl; return; }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for (int i = 0; i < (int)val.size(); i++) mp[val[i]] = i;
    for (int i = 1; i <= n; i++) cnt[mp[a[i]]]++;
    ll rem = n, tmp1 = -1, tmp2 = -1;
    for (int i = 1; i < (int)val.size(); i++) {
        //cur: # of appointments for each animal
        //rem: # of animals left
        //k: # of doctor examinations left
        int cur = val[i] - val[i-1];
        ll cycles = k / rem;
        if (cycles >= cur) {
            k -= 1ll*rem*cur;
            rem -= cnt[i];
        } else {
            k -= 1ll*rem*cycles;
            tmp1 = val[i];
            tmp2 = cur - cycles;
            break;
        }
    }
    if (rem == 0) return;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (a[i] < tmp1) continue;
        if (!k) {
            cout << i << ' ';
        } else {
            k--;
            if (a[i] == tmp1) {
                if (tmp2 > 1) res.push_back(i);
            } else {
                res.push_back(i);
            }
        }
    }
    for (int x : res) cout << x << ' ';
    cout << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}