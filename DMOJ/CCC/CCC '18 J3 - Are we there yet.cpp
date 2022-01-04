#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
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
const int MN = 1000000;

int a[5], ans[5][5];
int main(){
    for(int i=0; i<4; i++)
        cin >> a[i];
    for(int i=0; i<5; i++){
        ans[i][i] = 0;
        for(int j=i-1; j>=0; j--)
            ans[i][j] = ans[i][j+1] + a[j];
        for(int j=i; j<4; j++)
            ans[i][j+1] = ans[i][j] + a[j];
        for(int j=0; j<=4; j++)
            cout << ans[i][j] << " ";
        cout << nl;
    }
}