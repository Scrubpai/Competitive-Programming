#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long NM = 2000000;
typedef long long ll;
#define INF 0x3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back

int tickets[4]; int cost; int cnt; int ticket = INF; int arr[4];

void rec(int tot, int cur) {

    if (tot==cost) {
        cout << "# of PINK is " << arr[0] << " # of GREEN is " << arr[1] << " # of RED is " << arr[2] << " # of ORANGE is " << arr[3] << endl;
        cnt++; ticket = min(ticket, arr[0]+arr[1]+arr[2]+arr[3]);
    }

    for (int i=cur; i<4; i++) {
        if (tot+tickets[i] <= cost) {
            arr[i]++; rec(tot+tickets[i], i);
            arr[i]--;
        }
    }

}

void solve() {

    for (int i=0; i<4; i++) cin >> tickets[i];
    cin >> cost;

    rec(0, 0);
    cout << "Total combinations is " << cnt << "." << endl;
    cout << "Minimum number of tickets to print is " << ticket << "." << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}