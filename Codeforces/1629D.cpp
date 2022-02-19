#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
void solve(int n) {
    vector<string> list(n); set<string> st;
    for (int i=0; i<n; i++) cin >> list[i];
    for (int i=0; i<n; i++) {
        if ((int)list[i].size()==1) { cout << "YES\n"; return; }
        if ((int)list[i].size()==2) {
            if (list[i][0] == list[i][1]) { cout << "YES\n"; return; }
            string x = list[i]; reverse(x.begin(), x.end());
            if (st.count(x)) { cout << "YES\n"; return; }
            for (char ch='a'; ch<='z'; ch++) {
                x=""; x+=list[i][1]; x+=list[i][0]; x+=ch;
                if (st.count(x)) { cout << "YES\n"; return; }
            }
        } else {
            if (list[i][0] == list[i][2]) { cout << "YES\n"; return; }
            string x = list[i]; reverse(x.begin(), x.end());
            if (st.count(x)) { cout << "YES\n"; return; }
            x=""; x+=list[i][2]; x+=list[i][1];
            if (st.count(x)) { cout << "YES\n"; return; }
        }
        st.insert(list[i]);
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; solve(n);
    }
}