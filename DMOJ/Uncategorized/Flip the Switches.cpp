#include <bits/stdc++.h>
using namespace std;
int N, ans; string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> s;
    for (int i=1; i<N; i++)
        if (s[i] != s[i-1]) ans++;
    printf("%d\n", (s[N-1]=='1')?ans+1:ans);
}