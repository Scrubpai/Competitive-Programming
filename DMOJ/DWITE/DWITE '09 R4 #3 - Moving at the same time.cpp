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
#define f first
#define s second
#define nl '\n'
const int MN = 1000000;

string str; vector<pi> arr;

void solve() {

    for (int t=0; t<5; t++) {
        cin >> str; int sz = str.size(); arr.clear();
        for (int j=0; j<sz; j++) {
            if (str[j]!='.') { int x = str[j]-'0'; arr.pb({j, x});  }
        }
        cout << str << nl;
        for (int j=1; j<5; j++) {
            for (int i=0; i<arr.size(); i++) {
                arr[i].f+=arr[i].s;
            }
            sort(arr.begin(), arr.end()); int idx = 0;
            for (int i=0; i<sz; i++) {
                bool flag = false; int val = 0;
                while (arr[idx].f==i) {
                    val+=arr[idx].s; idx++; flag = true;
                }
                if (flag) cout << val;
                else cout << ".";
            }
            cout << nl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}