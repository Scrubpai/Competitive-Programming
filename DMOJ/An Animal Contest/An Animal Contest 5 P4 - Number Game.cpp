#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, X;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> X; vector<int> pos, neg;
    if (N == 1) { cout << 0 << '\n'; return 0; }
    ll sum = 1ll*(N/2)*(N/2+1)/2; int ans = -1, to = -1, mid = (N+1)/2;
    if (N % 2 == 0) {
        ans = N/2;
        int dif = abs(X-mid);
        if (dif % 2 == sum % 2) to = mid;
        else to = mid+1;
    } else {
        int dif = abs(X-mid);
        if (dif % 2 == sum % 2) {
            ans = N/2;
            to = mid;
        } else {
            ans = N/2+1;
            sum = 1ll*ans*(ans+1)/2;
            if (dif % 2 == sum % 2) {
                to = mid;
            } else {
                to = mid+1;
            }
        }
    }
    ll k = (sum - abs(X-to)) / 2;
    for (int i=ans; i>=1; i--) {
        if (k-i >= 0) {
            k -= i;
            neg.push_back(i);
        } else {
            pos.push_back(i);
        }
    }
    if (X > to) swap(pos, neg);
    int n = (int)pos.size(), m = (int)neg.size();
    cout << ans << '\n';
    for (int i=n-1, j=m-1; i>=0 || j>=0;) {
        if (i>=0 && X+pos[i] <= N) {
            cout << pos[i] << '\n';
            X += pos[i]; i--;
        } else {
            cout << -neg[j] << '\n';
            X -= neg[j]; j--;
        }
    }
}