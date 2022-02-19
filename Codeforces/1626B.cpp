#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string x; cin >> x;
        int n = (int)x.size(); bool flag = 0;
        for (int i=n-2; i>=0; i--) {
            int a = x[i]-'0', b = x[i+1]-'0';
            if (a+b>=10) {
                for (int j=0; j<i; j++) cout << x[j];
                cout << (a+b)/10 << (a+b)%10;
                for (int j=i+2; j<n; j++) cout << x[j];
                cout << '\n';
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        int a = x[0]-'0', b = x[1]-'0';
        cout << a+b;
        for (int j=2; j<n; j++) cout << x[j];
        cout << '\n';
    }
}