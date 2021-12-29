#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int S, F;
int get(int x) {
    if (x % 4 == 1) return 1;
    else if (x % 4 == 2) return x+1;
    else if (x % 4 == 3) return 0;
    else return x;
}
void solve(int tc) {
    scanf("%d%d", &S, &F);
    printf("%d\n", get(F)^get(S-1));
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; scanf("%d", &tc); for (int t = 1; t <= tc; t++) solve(t); return 0; }