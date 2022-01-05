#include <bits/stdc++.h>
using namespace std;
int R, C, K, cnt; map<pair<int, int>, int> mp;
int query(int r, int c){
    if(mp.count({r, c})) return mp[{r, c}];
    cout << "? " << r << " " << c << endl;
    int val;  cin >> val;
    cnt++; assert(cnt <= K);
    return  mp[{r, c}] = val;
}
int main(){
    cin >> R >> C >> K;
    int r1 = 1, r2 = R, c1 = 1, c2 = C;
    while(r1 < r2 || c1 < c2){
        int rm = (r1 + r2)/2, cm = (c1 + c2)/2;
        if(r1 < r2){
            int cen = query(rm, cm), below = query(rm+1, cm);
            if(cen < below) r2 = rm;
            else r1 = rm + 1;
        }
        if(c1 < c2) {
            int cen = query(rm, cm), rit = query(rm, cm+1);
            if(cen < rit) c2 = cm;
            else c1 = cm+1;
        }
    }
    int ans = query(r1, c1);
    cout << "! " << ans << endl;
}