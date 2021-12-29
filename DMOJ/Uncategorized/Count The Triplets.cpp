#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6;
int n, cnt[MM+5]; ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n; vector<int> a(n);
    for (int i=0; i<n; i++) { cin >> a[i]; cnt[a[i]]++; }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i=0; i<(int)a.size(); i++) {
        for (int j=i; j<(int)a.size(); j++) {
            if (a[i] + a[j] > MM) break;
            if ((a[i] == a[j] && cnt[a[i]] > 1 && cnt[2*a[i]]) || (a[i]!=a[j] && cnt[a[i]+a[j]])) ans++;
            cout << '\n';
        }
    }
    printf("%lld\n", ans?ans:-1);
}