#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define ms(x, y) memset(x, y, sizeof(x))

const int MM = 1e5 + 5, LOG = 16;
int N, K, Q, a[MM], mx[MM][LOG+5], mn[MM][LOG+5], st[MM][LOG+5], len[MM];

int querymax(int l, int r) {
    int k = log2(r-l+1);
    return max(mx[l][k], mx[r-(1<<k)+1][k]);
}

int querymin(int l, int r) {
    int k = log2(r-l+1);
    return min(mn[l][k], mn[r-(1<<k)+1][k]);
}

int query(int l, int r) {
    int k = log2(r-l+1);
    return max(st[l][k], st[r-(1<<k)+1][k]);
}

void solve(int tc) {

    cin >> N >> K; ms(mx, -1); ms(mn, -1);
    for (int i = 1; i <= N; i++) { cin >> a[i]; mx[i][0] = mn[i][0] = a[i]; }
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i + (1<<j) - 1 <= N; i++) {
            mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
            mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i = 1; i <= N; i++) {
        int l = 1, r = i, idx = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (querymax(mid, i) - querymin(mid, i) <= K) idx = min(idx, mid), r = mid - 1;
            else l = mid + 1;
        }
        len[i] = st[i][0] = i - idx + 1;
    }
    for (int j = 1; j <= LOG; j++) {
        for (int i = 1; i + (1<<j) - 1 <= N; i++) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    cin >> Q;
    for (int i = 1, l, r; i <= Q; i++) {
        cin >> l >> r;
        int idx = l-1, lo = l, hi = r;
        //find biggest idx where the subarray extends past L
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid - len[mid] + 1 < l) idx = max(idx, mid), lo = mid + 1;
            else hi = mid - 1;
        }
        if (idx == r || idx - l + 1 >= query(idx+1, r)) cout << l << " " << idx << nl;
        else {
            int ans = query(idx+1, r), tmp = r; lo = idx + 1; hi = r;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (query(idx+1, mid) == ans) tmp = min(tmp, mid), hi = mid - 1;
                else lo = mid + 1;
            }
            cout << tmp - ans + 1 << " " << tmp << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}