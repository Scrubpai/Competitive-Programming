#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, K, a[MM], ans[MM]; ll sum;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    int M = min(N, K); deque<int> q;
    for (int i=0; i<N; i++) { cin >> a[i]; sum += a[i]; }
    ll cur = 0;
    for (int i=1; i<=M; i++) {
        cur += a[N-i];
        if (!cur) q.push_back(i);
        else cur--;
    }
    if (!M) {
        cout << a[0];
        for (int i=1; i<N; i++) cout << " " << a[i];
        cout << '\n';
        return 0;
    }
    for (int i=0; i<N; i++) {
        while (!q.empty() && q.back()+i>M) q.pop_back();
        int tmp = (!q.empty()&&q.back()==M-i)?0:1;
        if (sum<N && K>N) ans[(i+K)%N] = max(tmp, a[i]-(int)q.size());
        else ans[i] = max(tmp, a[i]-(int)q.size());
        q.push_front(-i);
        while (!q.empty() && a[i]>0) q.pop_front(), a[i]--;
    }
    cout << ans[0];
    for (int i=1; i<N; i++) cout << " " << ans[i];
    cout << '\n';
}