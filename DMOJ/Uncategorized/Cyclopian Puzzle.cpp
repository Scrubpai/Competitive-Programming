#include <bits/stdc++.h>
using namespace std;
int N;
//start     //extra     //dest
void rec(int n, char a, char b, char c) {
    if (n == 1) { cout << a << c << '\n'; return; }
    rec(n - 1, a, c, b); //move n-1 pegs from start to extra
    cout << a << c << '\n';
    rec(n - 1, b, a, c); //move n-1 pegs from extra to dest
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    rec(N, 'A', 'B', 'C');
}