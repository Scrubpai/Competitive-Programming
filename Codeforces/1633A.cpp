#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n%7==0) cout << n << '\n';
        else {
            int x = n-n%10;
            for (int i=0; i<10; i++) {
                if ((x+i)%7==0) {
                    cout << x+i << '\n';
                    break;
                }
            }
        }
    }
}