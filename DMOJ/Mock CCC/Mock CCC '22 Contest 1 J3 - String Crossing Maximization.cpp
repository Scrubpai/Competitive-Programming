#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, fs[26], ft[26]; string S, T; ll ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> S >> T;
    int mx = 0, mn = 1e9;
    for (int i=0; i<N; i++) fs[S[i]-'A']++;
    for (int i=0; i<M; i++) ft[T[i]-'A']++;
    for (int i=0; i<26; i++) {
        ans += 1ll*fs[i]*ft[i];
        mx = max(mx, fs[i]);
        if (ft[i]) mn = min(mn, fs[i]);
    }
    ans -= mn; ans += mx;
    cout << ans << '\n';
}