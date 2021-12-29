#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    s.erase(remove(s.begin(), s.end(), 'x') - s.begin()); sort(s.begin(), s.end());
    long long ans = s[0]-'0'; printf("%c", s[0]);
    for (int i=1; i<(int)s.size(); i++) { ans *= 1ll*(s[i]-'0'); printf("x%c", s[i]); }
    printf("\n%lld", ans);
}