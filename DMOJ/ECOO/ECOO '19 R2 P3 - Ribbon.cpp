#include <bits/stdc++.h>
using namespace std;
int N, K; map<int, int> ribbon;
void output() {
    int mx = 0, thick = 0, l = 0, r = 0; bool first = false;
    for (auto next: ribbon) {
        thick += next.second;
        mx = max(mx, thick);
        if (!first) {
            first = true;
            l = next.first;
        }
        r = next.first;
    }
    cout << r-l << " " << mx << '\n';
}
void fold(int i, char dir) {
    map<int, int> ribbon2;
    if (dir == 'L') {
        int tot = 0;
        for (auto next: ribbon) {
            if (next.second == 0) continue;
            if (next.first < i) {
                ribbon2[i+(i-next.first-1)+1] += -next.second;
                tot += next.second;
            } else {
                ribbon2[next.first] += next.second;
            }
        }
        ribbon = ribbon2;
        ribbon[i] += 2*tot;
    } else {
        int tot = 0, extra = 0;
        for (auto next: ribbon) {
            if (next.second == 0) continue;
            if (next.first > i+1) {
                ribbon2[i-(next.first-i-1)+1] += -next.second;
            } else {
                if (next.first == i+1) {
                    extra = next.second;
                } else {
                    tot += next.second;
                    ribbon2[next.first] += next.second;
                }
            }
        }
        ribbon = ribbon2;
        tot = 2*tot + extra;
        ribbon[i+1] = -tot;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int tt=0; tt<10; tt++) {
        cin >> N >> K; ribbon.clear();
        ribbon[1] = 1; ribbon[N+1] = -1;
        for (int i=0, p; i<K; i++) {
            char dir; cin >> p >> dir;
            fold(p, dir);
        }
        output();
    }
}