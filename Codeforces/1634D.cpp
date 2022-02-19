/* Idea:
 *
 * Key idea 1: solve the problem by determining which numbers cannot be 0. Discard n-2 numbers, and the answer will be one of the 2 remaining numbers.
 * Key idea 2: For any 4 numbers (a, b, c, d), we can discard 2 numbers using 4 queries. So solve the problem by continuously using groups of 4 indices.
 *
 * Define aa as the complement of a, bb as the complement of b, cc as the complement of c, and dd as the complement of d.
 * The complement is the difference between the maximum and the minimum of the other three numbers: aa = max(b,c,d) − min(b,c,d)
 *
 * Let's say if a = 0, and b <= c <= d. Also, a <= b <= c <= d
 * Then aa = d-b, bb = d, cc = d, dd = c
 * d > d-b = aa and d >= c = dd. and bb = cc = d.
 *
 * So for any 4 numbers (a, b, c, d), discard the 2 numbers whose complement is the largest. Those 2 numbers are guaranteed to be nonzero
 *
 * For even N, there will be 4 * (N-2)/2 = 2N-4 queries
 * For odd N, we can take back a discarded number to form a group of 4 and perform the queries again. There will be 4*(N-3)/2 + 4 = 2N-2 queries
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int ask(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    int ret; cin >> ret; return ret;
}
pii solve(int a, int b, int c, int d) {
    vector<pii> arr(4);
    arr[0] = {ask(b, c, d), a}; arr[1] = {ask(a, c, d), b}; arr[2] = {ask(a, b, d), c}; arr[3] = {ask(a, b, c), d};
    sort(arr.begin(), arr.end());
    return make_pair(arr[0].second, arr[1].second);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; pii ans={1, 2};
        for (int i=4; i<=n; i+=2) {
            ans = solve(ans.first, ans.second, i-1, i);
        }
        if (n&1) {
            for (int i=1; i<=n; i++) {
                if (i != ans.first && i != ans.second) {
                    ans = solve(ans.first, ans.second, i, n);
                    break;
                }
            }
        }
        cout << "! " << ans.first << " " << ans.second << endl;
    }
}