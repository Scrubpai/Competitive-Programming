#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;
const int NM = 1000001;

int N;

void solve() {

    cin >> N;
    int x = N*(N-1)*(N-2)*(N-3); x/=24;
    cout << x << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}