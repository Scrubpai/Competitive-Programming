#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;

int T, N; unordered_map<string, int> mp; string s; vector<pair<int, int> > type;

void solve() {

    cin >> T;
    for (int i=1; i<=T; i++) {
        cin >> s;
        mp[s] = i;
    }

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> s;
        type.push_back({mp[s], i});
    }

    sort(type.begin(), type.end());
    for (pair<int, int> p : type) {
        cout << p.second << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}