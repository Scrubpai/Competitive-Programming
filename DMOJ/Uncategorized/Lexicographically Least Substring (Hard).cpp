#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5, base = 131;
char s[MM]; int K; ll p[MM], hsh[MM];
ll getSubHash(int l, int r) { return hsh[r] - hsh[l-1] * p[r-l+1]; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    scanf("%s %d", s+1, &K);
    int n = strlen(s+1);
    p[0] = 1;
    for (int i=1; i<=n; i++) {
        p[i] = p[i-1] * base;
        hsh[i] = hsh[i-1] * base + s[i];
    }
    int idx = 1;
    for (int i=2; i+K-1<=n; i++) {
        if (s[i] < s[idx]) idx = i;
        else if (s[i] == s[idx]) {
            int lo = 1, hi = K-1;
            while (lo < hi) {
                int mid = lo + hi >> 1;
                if (getSubHash(idx, idx+mid) == getSubHash(i, i+mid)) lo = mid + 1;
                else hi = mid;
            }
            if (s[idx+hi] > s[i+hi]) idx = i;
        }
    }
    for (int i=idx; i<=idx+K-1; i++) printf("%c", s[i]);
}