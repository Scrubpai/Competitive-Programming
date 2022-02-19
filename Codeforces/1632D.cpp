#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5, LOG=18;
int n, a[MM], ans[MM], st[LOG][MM];
int query(int l, int r) {
    int k = (int)log2(r-l+1);
    return __gcd(st[k][l], st[k][r-(1<<k)+1]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        st[0][i] = a[i];
    }
    for (int i=1; i<LOG; i++) {
        for (int j=1; j+(1<<i)-1<=n; j++) {
            st[i][j] = __gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    int last = 1;
    for (int i=1; i<=n; i++) {
        int cur_gcd = a[i], pos = i;
        while (pos >= last) {
            int lo = last, hi = pos;
            while (lo < hi) {
                int mid = (lo+hi)/2;
                if (query(mid, i) == cur_gcd) hi = mid;
                else lo = mid+1;
            }
            if (cur_gcd >= i-pos+1 && cur_gcd <= i-hi+1) { ans[i]++; last = i+1; break; }
            pos = hi-1;
            cur_gcd = query(pos, i);
        }
        ans[i] += ans[i-1];
        cout << ans[i] << ' ';
    }
}
//btw, the 2pointer solution is really nice