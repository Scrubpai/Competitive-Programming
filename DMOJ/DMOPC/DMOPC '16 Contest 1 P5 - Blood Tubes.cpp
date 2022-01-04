#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pii;
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

int N; ll bit[500001]; ll cnt;

void update(int x) {
    for (int i=x; i<=N; i+=(i&-i)) bit[i]++;
}
ll query(int x) {
    ll sum = 0;
    for (; x>=1; x-=(x&-x)) sum+=bit[x];
    return sum;
}

void solve() {

    cin >> N;
    for (int i=1, x; i<=N; i++) {
        cin >> x;
        ll val = query(x-1);
        cnt += min(val, i-val-1); //or query(n) - query(x) --> how many are greater or equal to n minus how many
                                  // are greater or equal to x = how many are less than x
        update(x);
    }
    cout << cnt << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}