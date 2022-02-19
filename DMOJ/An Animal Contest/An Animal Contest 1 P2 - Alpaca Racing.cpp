#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+5;
int N, K; ll D, P, X, a[MM];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> D >> K >> X;
    for (int i=1; i<=N; i++) cin >> a[i];
    cin >> P;
    for (int i=1; i<=N; i++) {
        while (a[i] >= P && K>=0) a[i] = (ll)(a[i] * (100-X)/100), K--;
    }
    if (K<0) cout << "NO\n";
    else cout << "YES\n";
}