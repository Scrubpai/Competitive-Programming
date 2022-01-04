#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
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
const int MN = 1000000;

struct Q {
    int score; string str; int idx;
};
bool cmp(Q a, Q b) {
    if (a.score!=b.score) return a.score > b.score;
    else return a.idx < b.idx;
}

vector<Q> arr; string st;

void solve() {

    for (int i=0; i<5; i++) {
        arr.clear();
        for (int j=0, x; j<5; j++) {
            cin >> x; cin.ignore(); getline(cin, st); //cin.ignore();
            arr.pb({x, st, j});
        }
        sort(arr.begin(), arr.end(), cmp);
        for (Q q : arr) {
            cout << q.str << nl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}