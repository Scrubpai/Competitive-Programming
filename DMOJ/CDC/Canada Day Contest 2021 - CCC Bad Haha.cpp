#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string n; int k;
void solve(int tc) {
    cin >> n >> k;
    if (!k) { cout << n << nl; return; }
    vector<char> vec; deque<int> idx[10];
    int sz = (int)n.size();
    for (int i=0; i<sz; i++) idx[n[i]-'0'].push_back(i);
    for (int i=0; i<sz; i++) {
        for (int c=0; c<=9; c++) {
            if (idx[c].empty()) continue;
            if (idx[c].front() - i <= k) {
                k -= (idx[c].front() - i);
                i = idx[c].front();
                break;
            }
        }
        for (int c=0; c<=9; c++) {
            while (!idx[c].empty() && idx[c].front()<=i) {
                if (idx[c].front() < i) vec.push_back(n[idx[c].front()]), idx[c].push_back(sz);
                else if (i!=sz) cout << n[idx[c].front()];
                idx[c].pop_front();
            }
        }
    }
    sort(vec.begin(), vec.end());
    for (char c : vec) cout << c;
    cout << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }