#include <bits/stdc++.h>
using namespace std;
int n, a[100002], b[100002], dp[100002];
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) { scanf("%d", &b[i]); a[i]=max(a[i], b[i]); }
    dp[1] = a[1]; dp[2] = a[1] + a[2];
    for(int i=3; i<=n; i++)
        dp[i] = max(dp[i-1]+b[i], max(dp[i-2]+b[i-1]+a[i], dp[i-3]+b[i-2]+a[i-1]+a[i]));
    printf("%d\n", dp[n]);
}