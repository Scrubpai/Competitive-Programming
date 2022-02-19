#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N; set<int> x, dif; x.insert(0);
        for (int i=0, a; i<N; i++) { cin >> a; x.insert(a); }
        for (int a: x) {
            for (int b: x) {
                if (b-a > 0) dif.insert(b-a);
            }
        }
        int ans = 0;
        for (int a: dif) {
            for (int b: dif) {
                for (int c: dif) {
                    if (a <= b && b <= c) {
                        bool flag = 1;
                        for (int y: x) {
                            if (y != 0 && y != a && y != b && y != c && y != a+b && y != b+c && y != c+a && y != a+b+c) { flag = 0; break; }
                        }
                        if (flag) ans++;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}