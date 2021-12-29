#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s; char a[15]; int top;
void solve(int tc) {
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'B') {
            if (top) top--;
        } else {
            a[++top] = s[i];
        }
    }
    for (int i = 1; i <= top; i++) cout << a[i];
    cout << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}