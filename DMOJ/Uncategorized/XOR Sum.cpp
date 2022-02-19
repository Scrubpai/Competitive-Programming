#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, xr; ll sum;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0, a; i<n; i++) { cin >> a; xr^=a; sum+=a; }
    cout << sum-xr << '\n';
}