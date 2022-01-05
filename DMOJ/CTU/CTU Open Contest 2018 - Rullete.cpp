#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;
#define nl '\n'

vector<string> cards(5);
vector<int> score(5);
vector<int> idk;
unordered_map<char, int> mp;
unordered_map<char, int> mp2;
int tot = 1, mn = 20, cnt = 1, pre = 1;

void init() {
    for (char c='2'; c<='9'; c++) {
        mp2[c] = c-'0';
    }
    mp2['T'] = 10;
    mp2['J'] = 11;
    mp2['Q'] = 12;
    mp2['K'] = 13;
    mp2['A'] = 14;
    for (int i=0; i<5; i++) {
        cin >> cards[i];
        if (cards[i][0] >= '2' && cards[i][0] <= '9') tot += cards[i][0]-'0', score[i] = cards[i][0]-'0';
        else tot += 10, score[i] = 10;
        if (cards[i].substr(0, 2) == "10") {
            mp['T']++;
            idk.push_back(mp2['T']);
            mp[cards[i][2]]++;
        } else {
            idk.push_back(mp2[cards[i][0]]);
            mp[cards[i][1]]++;
            mp[cards[i][0]]++;
        }
        mn = min(mn, score[i]);
    }
}

void rule1() {
    tot += mp['J'] * score[0];
}

void rule2() {
    if (mp['D'] >= 2 || mp['H'] >= 2 || mp['C'] >= 2 || mp['S'] >= 2) {
        tot *= 2; cnt++; pre = 2;
    }
}

void rule3() {
    if (mp['D'] >= 1 && mp['H'] >= 1 && mp['C'] >= 1 && mp['S'] >= 1) {
        tot *= 2; cnt++; pre = 3;
    }
}

void rule4() {
    tot += abs(mp['C'] + mp['S'] - mp['H'] - mp['D']); cnt++; pre = 4;
}

void rule5() {
    if (tot % 2 == 0) {
        int sum = 0;
        for (int i=1; i<=tot; i++) {
            if (tot % i == 0) sum += i;
        }
        tot += sum;
        cnt++; pre = 5;
    }
}

void rule6() {
    if (mp['7'] == 4) tot -= 121, cnt++, pre = 6;
}

void rule7() {
    if (tot >= 0) tot += mn, cnt++, pre = 7;
}

void rule8() {
    if (tot < 0) tot *= -1, cnt++, pre = 8;
}

void rule9() {
    if (mp['D'] >= 3) {
        tot++; cnt++; pre = 9; mp.clear(); idk.clear(); mn = 20;
        for (int i=0; i<5; i++) {

            if (cards[i][0]=='6') cards[i][0] = '9';
            else if (cards[i][0] == '9') cards[i][0] = '6';
            else if (cards[i][0] == '2') cards[i][0] = '5';
            else if (cards[i][0] == '5') cards[i][0] = '2';

            if (cards[i][0] >= '2' && cards[i][0] <= '9') score[i] = cards[i][0]-'0';
            else score[i] = 10;

            if (cards[i].substr(0, 2) == "10") {
                mp['T']++;
                idk.push_back(mp2['T']);
                mp[cards[i][2]]++;
            } else {
                idk.push_back(mp2[cards[i][0]]);
                mp[cards[i][1]]++;
                mp[cards[i][0]]++;
            }
            mn = min(mn, score[i]);
        }
    }
}

void rule10() {
    sort(idk.begin(), idk.end());
    bool flag = 1;
    for (int i=1; i<5; i++) {
        if (idk[i-1] + 1 != idk[i]) flag = 0;
    }
    if (flag) {
        if (5*mp['A']) pre = 10;
        tot += 5 * mp['A'];
        cnt++;
    }
}

void rule11() {
    if (cnt > 8) {
        if (__builtin_popcount(tot)) pre = 11;
        tot += __builtin_popcount(tot);
    }
}

void rule12() {
    if (mp['2'] >= 1) {
        if (pre == 1) rule1();
        else if (pre == 2) rule2();
        else if (pre == 3) rule3();
        else if (pre == 4) rule4();
        else if (pre == 5) rule5();
        else if (pre == 6) rule6();
        else if (pre == 7) rule7();
        else if (pre == 8) rule8();
        else if (pre == 9) rule9();
        else if (pre == 10) rule10();
        else rule11();
    }
}

void rule13() {
    if (mp['2'] < 1) return;
    tot *= 2;
}

void solve(int tc) {
    init();
    rule1();
    rule2();
    rule3();
    rule4();
    rule5();
    rule6();
    rule7();
    rule8();
    rule9();
    rule10();
    rule11();
    rule12();
    rule13();
    cout << tot << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }