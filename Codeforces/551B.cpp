#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
#define nl '\n'
string a, b, c; int freqA[26], freqB[26], freqC[26], tmp[26];
void solve(int tc) {
    cin >> a >> b >> c;
    int A = a.size(), B = b.size(), C = c.size();
    for (int i = 0; i < A; i++) freqA[a[i]-'a']++;
    for (int i = 0; i < B; i++) freqB[b[i]-'a']++;
    for (int i = 0; i < C; i++) freqC[c[i]-'a']++;
    int mx = 0, numB = 0, numC = 0;
    for (int i = 0; i <= A; i++) {
        bool flag = 1; //count B i times
        for (int j = 0; j < 26; j++) {
            tmp[j] = freqA[j];
            tmp[j] -= i * freqB[j];
            if (tmp[j] < 0) { flag = 0; break; }
        }
        if (!flag) break;
        int get = 1e9;
        for (int j = 0; j < 26; j++) {
            if (!freqC[j]) continue;
            get = min(get, tmp[j] / freqC[j]);
        }
        if (i + get > mx) mx = i + get, numB = i, numC = get;
    }
    for (int i = 0; i < numB; i++) cout << b;
    for (int i = 0; i < numC; i++) cout << c;
    for (int i = 0; i < 26; i++) {
        freqA[i] -= (numB * freqB[i] + numC * freqC[i]);
        char c = i + 'a';
        for (int j = 0; j < freqA[i]; j++) cout << c;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}