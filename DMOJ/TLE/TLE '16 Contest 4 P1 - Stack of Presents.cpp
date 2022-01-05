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

int N, a[100000];

void solve() {

    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    sort(a, a+N+1); int sum = 0; int cnt = 0;

    for (int i=1; i<=N; i++) {
        if (a[i]>=sum) {
            sum+=a[i]; cnt++;
        }
    }

    cout << cnt << endl;

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}