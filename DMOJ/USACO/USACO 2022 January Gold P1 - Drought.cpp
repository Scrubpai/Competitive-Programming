/* Idea:
 *
 * basically, at every iteration in do{ }, dp[i] holds how many possible N-tuples such that the current cow ends at hunger level i and alll the other cows end at hunger level 0
 * so if n is odd, then by subtracting 1 from every h[i] in every iteration, then you are also counting the number of N-tuples such that all cows end at 1, 2, ..., M, where M = min(h[i])
 *
 * base case: dp[0] = 1, dp[1] = 1, ... dp[h[1]] = 1
 * transition: dp[i] = dp[0] + dp[1] + ... + dp[h[i]-i] because
 *      so dp[i] means current cow ends at hunger i
 *      current cow can start with hunger i, i+1, ..., h[i]
 *          if current cow starts with hunger i, subtract 0
 *          if current cow starts with hunger i+1, subtract 1
 *          ...
 *          if current cow starts with hunger h[i], subtract h[i]-i
 *      that means i can subtract at most h[i] - i
 *      and since every other cow must end at hunger level 0, then the previous cow must currently have at most hunger level h[i] - i
 * pref[i] = dp[0] + dp[1] + ... + dp[i]
 */

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
int N, H[105], mn=1e9; ll dp[1005], pref[1005], ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=1; i<=N; i++) { cin >> H[i]; mn = min(mn, H[i]); }
    do {
        for (int i=0; i<=1000; i++) pref[i] = min(i, H[1]) + 1;
        for (int i=2; i<=N; i++) {
            memset(dp, 0, sizeof(dp));
            for (int j=0; j<=H[i]; j++) {
                dp[j] = pref[H[i]-j];
            }
            for (int j=0; j<=1000; j++) {
                pref[j] = dp[j];
                if (j) pref[j] = (pref[j] + pref[j-1]) % mod;
            }
        }
        ans = (ans + pref[0]) % mod;
        for (int i=1; i<=N; i++) H[i]--;
    } while (N%2 && mn--);
    cout << ans << '\n';
}