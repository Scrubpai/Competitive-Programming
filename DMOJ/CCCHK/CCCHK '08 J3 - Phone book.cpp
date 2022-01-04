#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int NM = (int)1e5 + 1;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 0x3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

int N, D; string name[10001]; string phone[10001]; unordered_map<string, int> mp; string num;

void solve() {

    cin >> N;
    for (int i=0; i<N; i++) { cin >> name[i] >> phone[i]; }

    cin >> D;
    for (int i=0; i<D; i++) {
        cin >> num; mp[num]+=1;
    }
    int mx = 0; string mxName = ""; string mxPhone = "";
    for (int i=0; i<N; i++) {
        int freq = mp[phone[i]];
        if (freq>mx || (freq==mx && phone[i]<mxPhone)) { mx = freq; mxPhone = phone[i]; mxName = name[i]; }
    }

    cout << mxName << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}