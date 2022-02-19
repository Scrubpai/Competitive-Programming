#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n-1; i++)
            if (a[i] > a[i+1]) { cout << "YES\n"; goto next; }
        cout << "NO\n";
        next: ;
    }
}