#include <bits/stdc++.h>
using namespace std;
#define nl '\n'

pair<int,int> arr1[1000000];
int arr2[1000000];
int tl[1000000], tr[1000000];
int ansarr[1000000];

void solve(int tc) {

    int n;
    cin >> n;
    for(int i = 1; i <= n+1; i++){
        int x;
        cin >> x;
        arr1[i] = {x, i};
    }
    sort(arr1 + 1, arr1 + n + 2);
    for(int i = 1; i <= n; i++){
        cin >> arr2[i];
    }
    sort(arr2 + 1, arr2 + n + 1);
    for(int i = 1; i <= n; i++){
        tl[i] = max(arr1[i].first - arr2[i], 0);
        tr[i] = max(arr1[i+1].first - arr2[i], 0);
    }
    for(int i = 1; i <= n; i++){
        tl[i] = max(tl[i], tl[i-1]);
    }
    for(int i = n; i > 0; i--){
        tr[i] = max(tr[i], tr[i+1]);
    }
    for(int i = 1; i <= n+1; i++){
        ansarr[arr1[i].second] = max(tl[i-1], tr[i]);
    }
    for(int i = 1; i <= n+1; i++){
        cout << ansarr[i] << ' ';
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc = 1; //cin >> tc;
    for (int t = 1; t <= tc; t++) solve(t);
    return 0;
}