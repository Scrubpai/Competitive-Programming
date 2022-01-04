#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (int)5e5 + 5;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
#define endl '\n'
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mpp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])
#define AUT auto
#define f first
#define s second
#define nl '\n'

int N, M; char grid[101][101]; vector<pi> emp; vector<pi> cam; int dis[101][101]; bool tmp = true;
int dir[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};

void solve() {

    cin >> N >> M; int sr = 0, sc = 0; ms(dis, 0x3f);
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> grid[i][j];
            if (grid[i][j]=='.') emp.pb({i, j});
            if (grid[i][j]=='S') { sr = i; sc = j; }
            if (grid[i][j]=='C') cam.pb({i, j});
        }
    }

    for (pi x : cam) {
        int r = x.f; int c = x.s;
        for (int i=c; i<=M; i++) { if (grid[r][i]=='.' || grid[r][i]=='S' || grid[r][i]=='C') grid[r][i] = 'X'; if (grid[r][i]=='W') break; }
        for (int i=c; i>=1; i--) { if (grid[r][i]=='.' || grid[r][i]=='S' || grid[r][i]=='C') grid[r][i] = 'X'; if (grid[r][i]=='W') break; }
        for (int i=r; i<=N; i++) { if (grid[i][c]=='.' || grid[i][c]=='S' || grid[i][c]=='C') grid[i][c] = 'X'; if (grid[i][c]=='W') break; }
        for (int i=r; i>=1; i--) { if (grid[i][c]=='.' || grid[i][c]=='S' || grid[i][c]=='C') grid[i][c] = 'X'; if (grid[i][c]=='W') break; }
    }

    priority_queue<pii, vector<pii>, greater<pii> > q; q.push({0, {sr, sc}}); 
    while (!q.empty()) {
        pii cur = q.top(); q.pop();
        int d = cur.f; int r = cur.s.f; int c = cur.s.s;

        if (r<=0 || r>N || c<=0 || c>M || grid[r][c]=='W' || grid[r][c]=='X') { continue; }//cout << 1; continue; }
        if (d>=dis[r][c]) { continue; }//cout << 3; continue; }
        dis[r][c] = d;

        if (grid[r][c]=='.' || grid[r][c]=='S') {
            for (int k=0; k<4; k++) {
                q.push({d+1, {r+dir[k][0], c+dir[k][1]}});
            }
        } else if (grid[r][c]=='L') {
            q.push({d, {r, c-1}});
        } else if (grid[r][c]=='R') {
            q.push({d, {r, c+1}});
        } else if (grid[r][c]=='U') {
            q.push({d, {r-1, c}});
        } else if (grid[r][c]=='D') {
            q.push({d, {r+1, c}});
        }
    }

    if (grid[sr][sc]='X') tmp = false;
    for (pi x : emp) {
        if (tmp || dis[x.f][x.s]>=10000) cout << -1 << endl;
        else cout << dis[x.f][x.s] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}