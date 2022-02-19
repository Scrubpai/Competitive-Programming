#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MM = 2e5+5, P=2, PR[P] = {31, 43}, MD[P] = {1000000007, 998244353};
string s, t; int n, m, cnt[26], cnt2[26]; ll hsh[P][MM], p[P][MM], ans; set<pll> st;
void init() {
    for (int i=0; i<P; i++) {
        p[i][0]=1;
        for (int j=1; j<=m; j++) {
            hsh[i][j] = (hsh[i][j-1] * PR[i] + (t[j-1]-'a')) % MD[i];
            p[i][j] = (p[i][j-1] * PR[i]) % MD[i];
        }
    }
}
ll sub(int id, int l, int r) {
    ll ret = hsh[id][r] - (hsh[id][l-1] * p[id][r-l+1]) % MD[id];
    ret %= MD[id]; ret += MD[id]; ret %= MD[id];
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s >> t; n = s.length(); m = t.length(); init();
    for (int i=0; i<n; i++) cnt[s[i]-'a']++;
    for (int i=0; i<n-1; i++) cnt2[t[i]-'a']++;
    for (int i=n; i<=m; i++) {
        cnt2[t[i-1]-'a']++;
        pll curHash = make_pair(sub(0, i-n+1, i), sub(1, i-n+1, i));
        bool flag = true;
        for (int j=0; j<26; j++) {
            if (cnt[j] != cnt2[j]) {
                flag = false;
                break;
            }
        }
        if (flag && !st.count(curHash)) {
            st.insert(curHash);
            ans++;
        }
        cnt2[t[i-n]-'a']--;
    }
    cout << ans << '\n';
}