#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string a, s, b=""; cin >> a >> s;
        bool flag = 1;
        int i, j;
        for (i=(int)a.size()-1, j=(int)s.size()-1; j>=0; i--, j--) {
            int x = 0, y = s[j]-'0';
            if (i>=0) x = a[i]-'0';
            if (x > y) {
                j--;
                if (j<0) { flag = 0; break; }
                y = 10*(s[j]-'0')+y;
            }
            int dif = y-x;
            if (dif>=0 && dif<=9) { b = to_string(dif) + b; }
            else { flag = 0; break; }
        }
        if (!flag || i>=0) { cout << -1 << '\n'; }
        else {
            b.erase(0, b.find_first_not_of('0'));
            cout << b << '\n';
        }
    }
}