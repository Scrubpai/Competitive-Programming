#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MM = 1003;
int N, M, dis[MM], flow[MM], ans; vector<pii> adj[MM];
int dijkstra(int limit){
    priority_queue<pi, vector<pi>, greater<pi> > q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0; q.push({0, 1});
    while(!q.empty()){
        int d = q.top().first, u = q.top().second; q.pop();
        if(d > dis[u]) continue;
        for(pii e: adj[u]){
            int v = e.first, w = e.second.first, f = e.second.second;
            if(f >= limit && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    return dis[N];
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i=1, u, v, c, f; i<=M; i++){
        scanf("%d %d %d %d", &u, &v, &c, &f); flow[i] = f;
        adj[u].push_back({v, {c, f}}); adj[v].push_back({u, {c, f}});
    }
    for(int i=1; i<=M; i++){
        int t = dijkstra(flow[i]);
        ans = max(ans, flow[i]*int(1e6)/t);
    }
    printf("%d\n", ans);
}