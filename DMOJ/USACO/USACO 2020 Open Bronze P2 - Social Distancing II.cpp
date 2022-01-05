#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    int i1, i2;
    for(int i = 0; i < n; i++){
        cin >> i1 >> i2;
        a.push_back({i1, i2});
    }
    sort(a.begin(), a.end());
    int r = n+1;
    for(int i = 1; i < n; i++){
        if(a[i-1].second != a[i].second){
            r = min(r, a[i].first - a[i-1].first);
        }
    }
    int ans = 0;
    int last = -1;
    for(int i = 0; i < n; i++){
        if(a[i].second==1){
            if(last==-1 or a[i].first - last >= r) ans++;
            last = a[i].first;
        }
    }
    cout << ans << endl;
}