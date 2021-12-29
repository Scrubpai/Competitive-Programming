#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e5+5;
int N, h, mx; ll dp[MM], sum;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N; dp[0] = sum = 1;
    for(int i=1; i<=N; i++){
        cin >> h;
        if(h >= mx) { dp[i] = sum; mx = h; }
        else dp[i] = dp[i-1];
        sum = (sum + dp[i])%mod;
    }
    cout << dp[N] << endl;
}