#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int N, L; string s; vector<string> a;
void solve(int tc) {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    for (string x : a) cout << x;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}