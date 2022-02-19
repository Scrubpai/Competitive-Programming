#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int base1 = 131, base2 = 137, mod = 1e9+7;
int N, M; unordered_set<ll> st; ll p1[26], p2[26]; string s;
ll getsub(int l, int r, vector<ll> &hsh1, vector<ll> &hsh2) {
    ll h1 = (hsh1[r] - hsh1[l-1] * p1[r-l+1] % mod + mod) % mod;
    ll h2 = (hsh2[r] - hsh2[l-1] * p2[r-l+1] % mod + mod) % mod;
    return (h1 << 31) | h2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M; p1[0] = p2[0] = 1;
    for (int i=1; i<=25; i++) p1[i] = p1[i-1] * base1 % mod, p2[i] = p2[i-1] * base2 % mod;
    for (int i=0; i<N; i++) {
        cin >> s;
        ll h1 = 0, h2 = 0;
        for (int j=0; j<(int)s.size(); j++) {
            s[j] = tolower(s[j]);
            h1 = (h1 * base1 + s[j]) % mod;
            h2 = (h2 * base2 + s[j]) % mod;
        }
        st.insert(((h1<<31)|h2));
    }
    for (int i=0; i<M; i++) {
        cin >> s;
        int sz = (int)s.size(); s = " " + s;
        vector<ll> h1(sz+1), h2(sz+1); unordered_set<ll> st2;
        for (int j=1; j<=sz; j++) {
            s[j] = tolower(s[j]);
            h1[j] = (h1[j-1] * base1 + s[j]) % mod;
            h2[j] = (h2[j-1] * base2 + s[j]) % mod;
            for (int k=1; k<=min(j, 25); k++) {
                ll sub = getsub(j-k+1, j, h1, h2);
                if (st.count(sub)) st2.insert(sub);
            }
        }
        cout << st2.size() << '\n';
    }
}