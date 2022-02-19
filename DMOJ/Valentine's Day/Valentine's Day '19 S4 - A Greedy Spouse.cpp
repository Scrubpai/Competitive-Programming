#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef pair<int, int> pii;
#define f first
#define s second
int N, K;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K; vector<pii> tasks(N);
    for (int i=0; i<N; i++) cin >> tasks[i].f >> tasks[i].s;
    sort(tasks.begin(), tasks.end());
    vector<pii> used, disc;
    int cur = -1;
    for (int i=0; i<N; i++) {
        if (tasks[i].f > cur) {
            cur = tasks[i].s;
            used.push_back(tasks[i]);
        } else {
            disc.push_back(tasks[i]);
        }
    }
    sort(disc.begin(), disc.end(), [](pii a, pii b) { return a.s < b.s; });
    int ans = (int)used.size(), mx1 = 0, mx2 = 0;
    for (int k=1; k<=K; k++) {
        for (int i=k-1, j=0; i<(int)used.size()-k+1; i++) {
            int l = i>=k?used[i-k].s:0, r = i<(int)used.size()-1?used[i+1].f:(int)1e9+1, cnt = 0;
            while (j<(int)disc.size() && disc[j].s < r) {
                if (disc[j].f > l) l = disc[j].s, cnt++;
                j++;
            }
            ans = max(ans, (int)used.size() - k + cnt);
            if (k==1) {
                if (cnt > mx1) mx2 = mx1, mx1 = cnt;
                else if (cnt > mx2) mx2 = cnt;
            }
        }
    }
    if (K==2) ans = max(ans, (int)used.size() + mx1 + mx2 - 2);
    cout << ans << '\n';
}