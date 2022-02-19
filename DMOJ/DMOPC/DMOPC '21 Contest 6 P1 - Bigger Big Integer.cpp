#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int D; cin >> D;
    string X; cin >> X;
    for (int i=0; i<D-1; i++) {
        if (X[i] < X[i+1]) {
            swap(X[i], X[i+1]);
            cout << X << '\n';
            return 0;
        }
    }
    cout << X << '\n';
}