#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MM = 1e5 + 5;
int n, dsu[MM]; unordered_set<int> st;

int Find(int x) {
    if (dsu[x] == x) return x;
    else return dsu[x] = Find(dsu[x]);
}

void solve(int tc) {


    for (int t = 0; t < 2; t++) {
        st.clear(); cin >> n;
        for (int i = 1; i <= n; i++) dsu[i] = i;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            int fu = Find(x), fv = Find(i);
            if (fu != fv) dsu[fu] = fv;
        }
        for (int i = 1; i <= n; i++) st.insert(Find(i));
        cout << st.size() << " ";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}