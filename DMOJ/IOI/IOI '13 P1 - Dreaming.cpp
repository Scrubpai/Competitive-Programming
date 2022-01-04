#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pair<ll, ll> > pii;
#define endl '\n'
#define INF 0x3f3f3f3f // for int
#define LL_INF 0x3f3f3f3f3f3f3f3f // for ll
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'
const int MN = 100005;
const int MV = 1000005;

int N, M, L, A[100001], B[100001], T[100001];

vector<pi> adj[100001]; bool vis[100001]; int dis[100001]; int pre[100001]; vector<int> rad; int maxd; int far; int ans; int diameter;

void dfs(int cur, int par, int d) {
    dis[cur] = d; vis[cur] = true;
    if (dis[cur] > maxd) { maxd = dis[cur]; far = cur; }

    for (pi p : adj[cur]) {
        if (p.f!=par) {
            pre[p.f] = cur;
            dfs(p.f, cur, d+p.s);
        }
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for (int i=0; i<M; i++) {
        adj[A[i]].pb({B[i], T[i]}); adj[B[i]].pb({A[i], T[i]});
    }
    for (int i=0; i<N; i++) {
        if (!vis[i]) {
            far = -1; int start = -1; maxd = 0;
            dfs(i, -1, 0);
            start = far; maxd = 0;
            dfs(far, -1, 0);
            diameter = max(diameter, maxd);

            int radius = INF;
            for (int j=far; j!=start; j=pre[j]) {
                radius = min(radius, max(dis[j], maxd-dis[j]));
            }

            if (radius==INF) rad.pb(0);
            else rad.pb(radius);
        }
    }

    sort(rad.begin(), rad.end(), greater<int>());
    if (rad.size()==1) return diameter;
    if (rad.size()==2) return max(diameter, rad[0]+rad[1]+L);
    if (rad.size()>=3) return max(diameter, max(rad[0]+rad[1] +L, rad[1]+rad[2]+L+L));
}