#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
int T, N, dp[MM+1], sieve[MM+1]; vector<int> primes;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i=2; i<=MM; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (long long j=1ll*i*i; j<=MM; j+=i) sieve[j] = 1;
    }
    for (int i=3; i<=MM; i++) {
        for (int p : primes) {
            if (i-p<1) break;
            if (!dp[i-p]) { dp[i]=1; break; }
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 2) cout << -1 << '\n';
        else {
            for (int i=1; i<=N-3; i++) cout << i << " ";
            if (dp[N]) cout << N-2 << " " << N-1 << " " << N << '\n';
            else if (dp[N-1]) cout << N-2 << " " << N << " " << N-1 << '\n';
            else cout << N << " " << N-2 << " " << N-1 << '\n';
        }
    }
}