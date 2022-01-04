#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, diset[200001];
int Find(int x){
    return diset[x] == x ? x : diset[x] = Find(diset[x]);
}
void unite (int x, int y){
    diset[Find(x)] = Find(y);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) diset[i] = i;
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        if (Find(u) != Find(v)) unite(u, v);
        else cnt++;
        if (cnt > 1) break;
    }
    if (cnt <= 1) cout << "YES";
    else cout << "NO";
    return 0;
}