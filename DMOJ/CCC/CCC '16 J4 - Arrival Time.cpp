#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;
typedef pair<int, int> pi;
const int NM = 100001;

string s;

void solve() {

    cin >> s;
    int h = stoi(s.substr(0, 2)); int m = stoi(s.substr(3, 5));
    for (int i=0; i<12; i++) {
        if ((h>=7 && h<10) || (h>=15 && h<19)) m+=20;
        else m+=10;

        if (m>=60) {h++; m-=60; }
        if (h>=24) h-=24;
    }

    printf("%02d:%02d", h, m);
  // cout << h << m;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}