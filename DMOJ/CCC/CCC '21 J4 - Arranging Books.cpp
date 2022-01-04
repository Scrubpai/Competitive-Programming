#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string books; unordered_map<char, int> mp;
void solve(int tc) {
    cin >> books;
    int n = books.size();
    for (int i=0; i<n; i++) mp[books[i]]++;
    deque<int> dq;
    for (int i=mp['L']; i<n; i++) {
        if (books[i] == 'L') dq.push_back(i);
    }
    int ans = 0;
    for (int i=0; i<mp['L']; i++) {
        if (books[i] == 'M') swap(books[i], books[dq.front()]), dq.pop_front(), ans++;
        else if (books[i] == 'S') swap(books[i], books[dq.back()]), dq.pop_back(), ans++;
    }
    for (int i=mp['L']; i<mp['L']+mp['M']; i++) {
        if (books[i] != 'M') ans++;
    }
    cout << ans << nl;
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }