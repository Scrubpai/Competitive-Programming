#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long NM = 2000000;
typedef long long ll;
#define INF 0x3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back

int N; int arr[20];

void solve() {

    cin >> N;
    for (int i=0; i<N; i++)  { cin >> arr[i]; }
    for (int i=0; i<N-1; i++) cout << arr[i] << " ";
    cout << arr[N-1] << endl;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N-1; j++) {
            if (arr[j]>arr[j+1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
                for (int k=0; k<N-1; k++) cout << arr[k] << " ";
                cout << arr[N-1] << endl;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}