#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;
typedef pair<int, int> pi;

int N, D;
int gcd(int a, int b) {
    if (a%b==0) return b;
    else return gcd(b, a%b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> D;
    if (N==0) { cout << 0 << endl; return 0; }
    if (N==D) { cout << 1 << endl; return 0; }
    if (N%D==0) { cout << N/D << endl; return 0; }

    if (N>D) {
        int x = N/D; N%=D;
        int GCD = gcd(N, D);
        N/=GCD; D/=GCD;
        printf("%d %d/%d", x, N, D);
    } else {
        int GCD = gcd(N, D);
        N/=GCD; D/=GCD;
        printf("%d/%d", N, D);
    }

    return 0;
}