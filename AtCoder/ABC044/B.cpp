#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string w; int freq[26];
void solve(int tc) {
    cin >> w;
    for (int i = 0; i < (int)w.size(); i++) freq[w[i]-'a']++;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) { cout << "No" << nl; return; }
    }
    cout << "Yes" << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}