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

vector<string> arr; unordered_map<string, int> mp; int N; string s;

void solve() {

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> s; arr.pb(s);
        mp[s]++;
    }
    for (int i=1; i<N; i++) {
        cin >> s;
        mp[s]--;
    }
    for (string str : arr) {
        if (mp[str]!=0) { cout << str << endl; return; }
    }

}

int32_t main() {
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}