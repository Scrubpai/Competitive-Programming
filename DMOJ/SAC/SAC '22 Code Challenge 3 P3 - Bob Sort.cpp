#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, mx=0, b=1; cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; i++) { cin >> a[i]; mx = max(mx, a[i]); }
    for (int i=0; i<(int)(log10(mx)+1); i++) {
        b*=10;
        sort(a.begin(), a.end(), [&b](int &x, int &y) { return x%b<y%b; });
        cout << a[0];
        for (int j=1; j<N; j++) cout << " " << a[j];
        cout << '\n';
    }
}