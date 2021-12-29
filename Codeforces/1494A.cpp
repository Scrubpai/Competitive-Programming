#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s;
void solve(int tc) {
    cin >> s;
    int n = s.size();
    for (int a=0; a<2; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                int cnt = 0; bool flag = 1;
                for (int i=0; i<n; i++) {
                    if (s[i]=='A') {
                        if (a) cnt++;
                        else cnt--;
                    } else if (s[i] == 'B') {
                        if (b) cnt++;
                        else cnt--;
                    } else {
                        if (c) cnt++;
                        else cnt--;
                    }
                    if (cnt<0) {
                        flag = 0;
                        break;
                    }
                }
                if (cnt==0 && flag) { cout << "YES" << nl; return; }
            }
        }
    }
    cout << "NO" << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }