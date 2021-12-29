#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, a[MM], id[MM], swaps;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i=1; i<=N && swaps<K; i++) {
        if (a[i] == N-i+1) continue;
        int ind = a[i];
        swap(a[i], a[id[N-i+1]]);
        swap(id[ind], id[N-i+1]);
        swaps++;
    }
    for (int i=1; i<=N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}