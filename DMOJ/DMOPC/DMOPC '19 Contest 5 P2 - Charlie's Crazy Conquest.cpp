#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = numeric_limits<long long>::max();
typedef long long ll;
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end();
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define sz(a) sizeof(a)/sizeof(a[0])

int N, H; int charlie[1000]; string C[1000]; int bot[1000]; string B[1000];

void solve() {

    cin >> N >> H;

    for (int i=0; i<N; i++) {
        cin >> C[i] >> charlie[i];
    }
    for (int i=0; i<N; i++) {
        cin >> B[i] >> bot[i];
    }

    int CHP = H; int BHP = H;
    for (int i=0; i<N; i++) {
        if (i==0) {
            if (C[i]=="A") {
                BHP -= charlie[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
            else if (C[i]=="D" && B[i]=="D") {
                CHP-=charlie[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            }

            if (B[i]=="A" && C[i]!="D") {
                CHP-=bot[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            } else if (B[i]=="D" && C[i+1]=="D") {
                BHP-=bot[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
        } else if (i==N-1) {
            if (C[i]=="A" && B[i-1]!="D") {
                BHP -= charlie[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
            else if (C[i]=="D" && B[i]=="D") {
                CHP-=charlie[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            }

            if (B[i]=="A" && C[i]!="D") {
                CHP-=bot[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            } else if (B[i]=="D") {
                BHP-=bot[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
        } else {
            if (C[i]=="A" && B[i-1]!="D") {
                BHP -= charlie[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
            else if (C[i]=="D" && B[i]=="D") {
                CHP-=charlie[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            }

            if (B[i]=="A" && C[i]!="D") {
                CHP-=bot[i];
                if (CHP<=0) { cout << "DEFEAT" << endl; return; }
            } else if (B[i]=="D" && C[i+1]=="D") {
                BHP-=bot[i];
                if (BHP<=0) { cout << "VICTORY" << endl; return; }
            }
        }
    }

    cout << "TIE" << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}