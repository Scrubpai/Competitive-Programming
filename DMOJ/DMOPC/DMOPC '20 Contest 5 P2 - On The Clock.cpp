#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
ll N, M;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    cout << N+M-__gcd(N,M) << '\n';
    for (int x=1; x<=M; x++)
        for (int y=(int)(N*(x-1)/M)+1; y<=(int)((N*x+M-1)/M); y++)
            cout << y << " " << x << '\n';
}