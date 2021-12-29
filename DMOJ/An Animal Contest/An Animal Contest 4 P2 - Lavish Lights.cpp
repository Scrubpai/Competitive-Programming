#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
const int MM = 1e6+5;
int N, Q; ll a[MM], pre[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> Q >> a[1]; pre[1] = a[1];
    for (int i=2; i<=N; i++) {
        cin >> a[i];
        if (pre[i-1] > (ll)1e9) { pre[i] = pre[i-1]; continue; }
        pre[i] = pre[i-1]*a[i]/__gcd(pre[i-1], a[i]);
    }
    for (int i=1, t; i<=Q; i++) {
        cin >> t;
        int lo = 1, hi = N+1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (t % pre[mid] == 0) lo = mid+1;
            else hi = mid;
        }
        printf("%d\n", hi>N?-1:hi);
    }
}