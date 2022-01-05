#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

/*
 * Two digits: (b-1, b-1) --> b * (b-1) + b-1 >= X, b^2 - 1 >= X --> smallest b such that 2 digits
 * when change base
 * (y y) in base b. b * y + y = X, y * (b + 1) = X, b + 1 is a factor of X
 */
int X; vector<int> ans;
bool check(int x, int b) {
    vector<int> a;
    while (x != 0) a.push_back(x % b), x /= b;
    for (int l = 0, r = a.size() - 1; l < r; l++, r--) {
        if (a[l] != a[r]) return 0;
    }
    return 1;
}

void solve(int tc) {

    cin >> X;
    for (int b = 2; b*b < X+1; b++) {
        if (check(X, b)) ans.push_back(b);
    }
    for (int y = sqrt(X+1); y >= 1; y--) {
        if (X % y == 0) {
            int b = X / y - 1;
            if (1ll * b * b - 1 >= 1ll * X) ans.push_back(b);
        }
    }
    for (int b : ans) cout << b << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}