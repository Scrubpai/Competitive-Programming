#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N1, N2, T, dir[26]; string s1, s2;
void solve(int tc) {
    cin >> N1 >> N2 >> s1 >> s2 >> T;
    reverse(s1.begin(), s1.end());
    for (int i=0; i<N1; i++) dir[s1[i]-'A'] = 0;
    for (int i=0; i<N2; i++) dir[s2[i]-'A'] = 1;
    string res = s1 + s2;
    while (T--) {
        for (int i=1; i<res.size(); i++) {
            if (dir[res[i]-'A']==1 && dir[res[i-1]-'A']==0) {
                swap(res[i-1], res[i]);
                i++;
            }
        }
    }
    cout << res << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }