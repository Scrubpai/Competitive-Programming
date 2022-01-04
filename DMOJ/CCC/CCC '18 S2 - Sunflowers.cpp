#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000;
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
//#define sz(a) sizeof(a)/sizeof(a[0])
//#define AUT auto
#define f first
#define s second
#define nl '\n'

int N; int a[100][100];

void RotateArr(int X) {
    for (int n=0; n<X; n++) {
        for (int i=0; i<N/2; i++) {
            for (int j=0; j<N; j++) {
                swap(a[i][j], a[N-i-1][j]);
            }
        }
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

void solve() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    int Min = min(min(a[0][0], a[N-1][0]), min(a[0][N-1], a[N-1][N-1]));
    if (Min==a[N-1][0]) RotateArr(1);
    else if (Min==a[N-1][N-1]) RotateArr(2);
    else if (Min==a[0][N-1]) RotateArr(3);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int32_t main() {
  //  ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}