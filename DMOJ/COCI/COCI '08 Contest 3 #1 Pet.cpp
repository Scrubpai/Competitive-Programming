#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
typedef long long ll;
typedef pair<ll, ll> pi;

#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

void solve() {

    int num=-1; int score=-1;
    for (int i=1, a, b, c, d; i<=5; i++) {
        cin >> a >> b >> c >> d;
        int total = a+b+c+d;
        if (total>score) { num = i; score = total;}
    }

    cout << num << " " << score << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}