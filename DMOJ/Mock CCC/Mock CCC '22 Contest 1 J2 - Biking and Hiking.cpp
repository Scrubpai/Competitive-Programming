#include <bits/stdc++.h>
using namespace std;
int N, K; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> s;
    int ans = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'U' && K>0) K--;
        else if (s[i] == 'D') K++;
        if (!K) ans++;
    }
    cout << ans << '\n';
}