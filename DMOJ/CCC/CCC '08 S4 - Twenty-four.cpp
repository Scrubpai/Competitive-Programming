#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

int card[4], ans;

void fun(int cur, int nxt, int idx) {
    if (idx == 3) {
        if (cur + nxt <= 24) ans = max(ans, cur + nxt);
        if (cur - nxt <= 24) ans = max(ans, cur - nxt);
        if (cur * nxt <= 24) ans = max(ans, cur * nxt);
        if (nxt != 0 && cur % nxt == 0 && cur / nxt <= 24) ans = max(ans, cur / nxt);
        return;
    }
    fun(cur+nxt, card[idx+1], idx+1);
    fun(cur-nxt, card[idx+1], idx+1);
    fun(cur*nxt, card[idx+1], idx+1);
    if (nxt != 0 && cur % nxt == 0) fun(cur / nxt, card[idx+1], idx+1);
    fun(cur, nxt+card[idx+1], idx+1);
    fun(cur, nxt-card[idx+1], idx+1);
    fun(cur, nxt*card[idx+1], idx+1);
    if (card[idx+1] != 0 && nxt % card[idx+1] == 0) fun(cur, nxt/card[idx+1], idx+1);
}

void solve(int tc) {

    ans = 0;
    for (int i = 0; i < 4; i++) cin >> card[i];
    sort(card, card + 4);
    do {
        fun(card[0], card[1], 1);
    } while (next_permutation(card, card + 4));
    cout << ans << nl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}