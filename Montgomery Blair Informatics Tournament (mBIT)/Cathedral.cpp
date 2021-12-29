#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5 + 5;
#define nl '\n'
int N, M, P[MM]; ll psa[MM];
void solve(int tc) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) { cin >> psa[i]; psa[i] += psa[i-1]; }
    for (int i = 1, s, k; i <= M; i++) {
        cin >> s >> k;
        //let L be lft sum (in interval [s, s+k-1]) and R be rit sum (in interval [s+k, s+2*k-1])
        //for a value b (0 <= b <= k-1), let x = psa[L+y-1] - psa[L-1]; let y = psa[L+k+y-1] - psa[L+k-1];
        //lft sum = L - x + y, rit sum = R - y + x --> minimize abs(lft sum - rit sum)
        int lo = 0, hi = k - 1, b = 0; ll L = psa[s+k-1] - psa[s-1], R = psa[s+2*k-1] - psa[s+k-1];
        //find largest b such that the difference is positive
        //the greater b is, the smaller L-R-2*(x-y) gets since x increase more than y
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            ll x = psa[s+mid-1] - psa[s-1], y = psa[s+k+mid-1] - psa[s+k-1];
            if (L-R-2*(x-y) >= 0) lo = mid + 1, b = max(b, mid);
            else hi = mid - 1;
        }
        ll x = psa[s+b-1] - psa[s-1], y = psa[s+k+b-1] - psa[s+k-1], ans = L-R-2*(x-y);
        if (b < k - 1) b++;
        x = psa[s+b-1] - psa[s-1]; y = psa[s+k+b-1] - psa[s+k-1]; ans = min(ans, abs(L-R-2*(x-y)));
        cout << ans << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}