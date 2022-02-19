/* Idea:

If candy 1 repeats r_1 times, candy 2 repeates r_2 times, ... candy n repeats r_n times, then the total number of combinations is (r_1+1)*(r_2+1)*...*(r_n+1) - 1 = K

Then we just have to prime factorize K+1.
Let's say K+1 = p1 * p2 * p3 * p4... where p1<=p2<=p3<=p4... and they are primes

Then let candy 1 repeat p1-1 times, candy 2 repeat p2-1 times, ...
If sum of (p1-1)+(p2-1)+...+(pn-1) > 1e5, then "Sad Chris"
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll K, N; int cnt; vector<pii> ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> K; K++;
    for (int i=2; 1ll*i*i<=K; i++) {
        while (K%i==0) {
            K/=i;
            ans.push_back({++cnt, i-1});
            N += i-1;
        }
    }
    if (K) ans.push_back({++cnt, K-1}), N+=K-1;
    if (N > (ll)1e5) { cout << "Sad Chris\n"; return 0; }
    cout << N << '\n';
    for (pii p: ans) {
        for (int i=1; i<=p.second; i++) cout << p.first << " ";
    }
}