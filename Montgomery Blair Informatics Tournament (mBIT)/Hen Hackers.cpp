#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

//maximum length of 62, 750 guesses, all characters are distinct
struct letter {
    char x;
};
vector<letter> a; char in;

int query(char a, char b) {
    string s = ""; s.push_back(a); s.push_back(b);
    cout << s << endl;
    cin >> in;
    if (in == 'Y') return 1;
    else return 2;
}

bool cmp(letter a, letter b) {
    int qry = query(a.x, b.x);
    return qry < 2;
}

void solve(int tc) {

    for (char c = 'a'; c <= 'z'; c++) {
        cout << c << endl;
        cin >> in;
        if (in == 'C') { return; }
        if (in == 'Y') a.push_back({c});
    }
    for (char c = '0'; c <= '9'; c++) {
        cout << c << endl;
        cin >> in;
        if (in == 'C') { return; }
        if (in == 'Y') a.push_back({c});
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        cout << c << endl;
        cin >> in;
        if (in == 'C') { return; }
        if (in == 'Y') a.push_back({c});
    }
    if (a.size() == 2) {
        cout << a[0].x << a[1].x << endl;
        cin >> in;
        if (in == 'C') return;
        cout << a[1].x << a[0].x << endl;
        cin >> in;
        return;
    }
    sort(a.begin(), a.end(), cmp);
    for (letter l : a) cout << l.x;
    cout << endl;
    cin >> in;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}