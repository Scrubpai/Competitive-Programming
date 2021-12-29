#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define nl '\n'

const int MM = 1e5 + 5;
int n, m; deque<int> pile[MM]; vector<pii> ord;

void solve (int tc) {

    cin >> n >> m;
    for (int i = 1, r; i <= m; i++) {
        cin >> r;
        for (int j = 0, t; j < r; j++) {
            cin >> t;
            pile[i].push_back(t);
        }
    }
    for (int i = 1; i < m; i++) {
        while (!pile[i].empty()) {
            ord.push_back({i, m});
            pile[m].push_front(pile[i].front());
            pile[i].pop_front();
        }
    }
    while (!pile[m].empty()) {
        int x = pile[m].front(); pile[m].pop_front();
        if (x == m) ord.push_back({m, 1}), pile[1].push_front(x);
        else ord.push_back({m, x}), pile[x].push_front(x);
    }
    while (!pile[1].empty()) {
        int x = pile[1].front(); pile[1].pop_front();
        if (x == 1) ord.push_back({1, 2}), pile[2].push_front(x);
        else ord.push_back({1, m}), pile[m].push_front(x);
    }
    while (!pile[2].empty()) {
        int x = pile[2].front();
        if (x != 1) break;
        pile[2].pop_front();
        ord.push_back({2, 1});
    }
    cout << ord.size() << nl;
    for (pii p : ord) cout << p.first << " " << p.second << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}