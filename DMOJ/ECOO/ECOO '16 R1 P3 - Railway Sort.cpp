#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long NM = 2000000;
typedef long long ll;
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back

int N; vector<int> arr;

void solve() {

    for (int t=0; t<10; t++) {
        cin >> N;
        for (int i=0, x; i<N; i++) { cin >> x; arr.pb(x); }
        int cnt = 0, idx1 = 0, idx2 = 0;

        for (int cur=N-1; cur>=1; cur--) {
            for (int j=0; j<N; j++) {
                if (arr[j]==cur) idx1 = j;
                else if (arr[j]==cur+1) idx2 = j;
            }
            if (idx1>idx2) {
                cnt += idx1;
                arr.erase(arr.begin() + idx1);
                arr.insert(arr.begin(), cur);
            }
        }
        arr.clear();

        cout << cnt << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}