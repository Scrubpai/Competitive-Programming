#include <bits/stdc++.h>
using namespace std;
int N, cnt;
void rec(int tot, string s, int cur) {
    if (tot == N) {
        if (count(s.begin(), s.end(), '+') == 1) return;
        cout << s.substr(0, (int)s.size()-1) << '\n';
        cnt++;
        return;
    }
    for (int i=cur; tot+i<=N; i++) rec(tot+i, s+to_string(i)+"+", i);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    string s = to_string(N)+"=";
    rec(0, s, 1);
    cout << "total=" << cnt;
}