#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
#define nl '\n'
int n, k; string str; char tmp;
void solve(int tc) {
    cin >> n >> k >> str;
    if (n % k != 0) { cout << -1 << nl; return; }
    vector<int> cnt(26), pre(26), cur(26);
    for (int i=0; i<n; i++) cnt[str[i]-'a']++, cnt[str[i]-'a']%=k;
    bool flag = 1;
    for (int i=0; i<26; i++) { if(cnt[i]%k) { flag = 0; }}
    if (flag) { cout << str << nl; return; }
    for (int i=n-1; i>=0; i--) {
        cnt[str[i]-'a'] = (cnt[str[i]-'a']-1+k)%k;
        int tot = 0;
        for (int j=0; j<26; j++) {
            pre[j] = (k-cnt[j])%k;
            cur[j] = (k-(cnt[j]+1)+k)%k;
            tot += (k-cnt[j])%k;
        }
        for (int j=str[i]-'a'+1; j<26; j++) {
            if (tot-pre[j]+cur[j] <= n-i-1) {
                int fill = (n-i-1) - (tot-pre[j]+cur[j]);
                for (int p=0; p<i; p++) cout << str[p];
                tmp = 'a'+j; cout << tmp;
                for (int p=0; p<fill; p++) cout << 'a';
                for (int l=0; l<26; l++) {
                    if (l==j) {
                        for (int p=0; p<cur[l]; p++) { tmp = 'a'+l; cout << tmp; }
                    } else {
                        for (int p=0; p<pre[l]; p++) { tmp = 'a'+l; cout << tmp; }
                    }
                }
                cout << nl;
                return;
            }
        }
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }