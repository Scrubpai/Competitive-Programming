#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s; int cnt[26];
void solve(int tc) {
    cin >> s;
    vector<int> even, odd;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < (int)s.size(); i++) {
        int v = s[i] - 'a';
        cnt[v]++;
        if (cnt[v] == 1) {
            if (v % 2 == 0) even.push_back(v);
            else odd.push_back(v);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if (even.empty()) {
        for (int v : odd) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        cout << nl;
    } else if (odd.empty()) {
        for (int v : even) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        cout << nl;
    } else if (abs(even[0] - odd[odd.size()-1]) != 1) {
        for (int v : odd) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        for (int v : even) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        cout << nl;
    } else if (abs(odd[0] - even[even.size()-1]) != 1) {
        for (int v : even) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        for (int v : odd) {
            char c = v + 'a';
            for (int i = 0; i < cnt[v]; i++) cout << c;
        }
        cout << nl;
    } else {
        cout << "No answer" << nl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}