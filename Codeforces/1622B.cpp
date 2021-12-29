#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int t, n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n; vector<int> p(n); vector<char> like(n);
        int cnt = 0; queue<int> q;
        for (int i=0; i<n; i++) cin >> p[i];
        for (int i=0; i<n; i++) {
            cin >> like[i];
            if (like[i]=='1') cnt++;
        }
        for (int i=0; i<n; i++) {
            if (like[i]=='0' && p[i]>=n-cnt+1) q.push(i);
        }
        for (int i=0; i<n; i++) {
            if (like[i]=='1' && p[i]<n-cnt+1) {
                swap(p[i], p[q.front()]);
                q.pop();
            }
        }
        for (int i=0; i<n; i++) cout << p[i] << " ";
        cout << '\n';
    }
}