#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    printf("%d\n", s.find("java")!=-1?s.find("java"):s.size());
    return 0;
}