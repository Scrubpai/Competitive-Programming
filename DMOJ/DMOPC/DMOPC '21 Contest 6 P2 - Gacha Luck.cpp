#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int K, N; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K >> s; vector<int> v;
    int pre = -1;
    for (int i=0; i<N; i++) {
        if (s[i] == '1' && pre != -1) v.push_back(i-pre), pre=-1;
        else if (s[i] == '0' && pre == -1) pre = i;
    }
    if (s[N-1] == '0') v.push_back(N-pre);
    sort(v.begin(), v.end(), greater<>());
    int ans = 0;
    for (int i=0; i<min((int)v.size(), K); i++) ans += v[i];
    cout << ans << '\n';
}