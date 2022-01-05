#include <bits/stdc++.h>
using namespace std;
const int NM = (int)1e5 + 5;
typedef long long ll;
typedef pair<int, int> pi;
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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'

int N; ll a[51];

void solve() {

    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N);

    ll sum = 0;
    for (int i=0; i<N-1; i++) {
        sum+=a[i];
    }
    if (sum>=a[N-1] && (sum+a[N-1])%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}