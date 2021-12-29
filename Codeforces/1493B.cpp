#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
int h, m, tmph, tmpm;
int valid(int num) {
   if (num == 0) return 0;
   else if (num == 1) return 1;
   else if (num == 2) return 5;
   else if (num == 5) return 2;
   else if (num == 8) return 8;
   else return -1;
}
void increment(int &hr, int &mins) {
    mins++;
    if (mins == m) {
        mins = 0;
        hr++;
        if (hr == h) hr = 0;
    }
}
void solve(int tc) {
    cin >> h >> m;
    scanf("%d:%d", &tmph, &tmpm);
    while (true) {
        int hrones = tmpm/10, hrtens = tmpm%10, minones = tmph/10, mintens = tmph%10;
        if (valid(hrones) == -1) { increment(tmph, tmpm); continue; }
        else hrones = valid(hrones);
        if (valid(hrtens) == -1) { increment(tmph, tmpm); continue; }
        else hrtens = valid(hrtens);
        if (valid(minones) == -1) { increment(tmph, tmpm); continue; }
        else minones = valid(minones);
        if (valid(mintens) == -1) { increment(tmph, tmpm); continue; }
        else mintens = valid(mintens);
        if (10*hrtens + hrones < h && 10*mintens + minones < m) {
            printf("%02d:%02d\n", tmph, tmpm);
            return;
        } else increment(tmph, tmpm);
    }
}
int32_t main() { /*ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);*/ int tc = 1; cin >> tc; for (int t = 1; t <= tc; t++) solve(t); return 0; }