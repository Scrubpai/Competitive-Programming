#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
#define nl '\n'
int psa[3][MM], cnt[3]; string s;
void solve(int tc) {
    cin >> s;
    int N = s.size();
    for (int i=1; i<=N; i++) {
        psa[s[i-1]-'A'][i]++; cnt[s[i-1]-'A']++;
        psa[0][i]+=psa[0][i-1]; psa[1][i]+=psa[1][i-1]; psa[2][i]+=psa[2][i-1];
    }
    int ans = 1e9;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i==j) continue;
            for (int k=cnt[i]+cnt[j]; k<=N; k++) {
                int swaps = cnt[i]-(psa[i][k-cnt[j]]-psa[i][k-cnt[j]-cnt[i]]), num = min(psa[j][k-cnt[j]]-psa[j][k-cnt[j]-cnt[i]], psa[i][k]-psa[i][k-cnt[j]]);
                swaps += cnt[j]-(psa[j][k]-psa[j][k-cnt[j]]+num);
                ans = min(ans, swaps);
            }
        }
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }