#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end(), [](string a, string b) { return a+b>b+a; });
    for (string s : a) cout << s;
    return 0;
}