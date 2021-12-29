#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, a[MM];
bool cmp(int x, int y) { if (x%10!=y%10) return x%10<y%10; else return x>y; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a, a+N, cmp);
    for (int i=0; i<N; i++) cout << a[i] << ' ';
}