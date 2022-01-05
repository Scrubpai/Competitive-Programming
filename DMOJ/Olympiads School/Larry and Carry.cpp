#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100001;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'

int N; int a[20]; int cnt = 0;

bool check(int a, int b) {
    while (a!=0 && b!=0) {
        int d1 = a%10; int d2 = b%10; a/=10; b/=10;
        if (d1+d2>=10) return false;
    }
    return true;
}

void rec(int cur, int idx, int n) {
    cnt = max(cnt, n);
    for (int i=idx; i<N; i++) {
        if (check(cur, a[i])) rec(cur+a[i], i+1, n+1);
    }
}

void solve() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    rec(0, 0, 0);
    cout << cnt << endl;

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}