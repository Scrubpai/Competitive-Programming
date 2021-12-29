#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int n, m;
int get(vector<int> &box, vector<int> &sp) {
    int a = box.size(), b = sp.size();
    vector<int> suf(a+1);
    for (int i=a-1, j=b-1; i>=0; i--) {
        suf[i] = suf[i+1];
        while (j>=0 && sp[j] > box[i]) j--;
        if (j>=0 && sp[j] == box[i]) suf[i]++, j--;
    }
    int mx = suf[0];
    for (int i=0, j=0, k=0; i<b; i++) {
        while (j<a && box[j]<=sp[i]+j) j++;
        while (k<b && sp[k]<sp[i]+j) k++;
        mx = max(mx, k-i+suf[j]);
    }
    return mx;
}
void solve(int tc) {
    cin >> n >> m;
    vector<int> nb, pb, ns, ps;
    for (int i=0, a; i<n; i++) {
        cin >> a;
        if (a<0) nb.push_back(-a);
        else pb.push_back(a);
    }
    for (int i=0, b; i<m; i++) {
        cin >> b;
        if (b<0) ns.push_back(-b);
        else ps.push_back(b);
    }
    reverse(nb.begin(), nb.end()); reverse(ns.begin(), ns.end());
    cout << get(nb, ns) + get(pb, ps) << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }