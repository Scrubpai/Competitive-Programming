#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
typedef long long ll;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937_64 gen(seed1); uniform_int_distribution<ll> dis(1, 1e12);
ll n, m, a[MM], mp[MM], sum, psa, ans; unordered_map<ll, int> freq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m; freq[0] = 1;
    for (int i=1; i<=m; i++) { mp[i] = dis(gen); sum += mp[i]; }
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        psa = (psa + mp[a[i]]) % sum;
        ans += freq[psa];
        freq[psa]++;
    }
    printf("%lld\n", ans);
}