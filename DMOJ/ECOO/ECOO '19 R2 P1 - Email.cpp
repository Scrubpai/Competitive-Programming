#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve(int tc) {
    for (int t=1, n; t<=10; t++) {
        cin >> n;
        unordered_set<string> st;
        while (n--) {
            string str; cin >> str;
            for (int i=0; i<(int)str.size(); i++) str[i] = tolower(str[i]);
            int pos = str.find('@');
            string pre = str.substr(0, pos), suf = str.substr(pos+1);
            pre.erase(remove(pre.begin(), pre.end(), '.'), pre.end());
            if (pre.find('+') != -1) pre = pre.substr(0, pre.find('+'));
            st.insert(pre+"@"+suf);
        }
        cout << st.size() << nl;
    }
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(tc); return 0; }