#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
ll n, m; int bit[3005][3005], g[3005][3005];
void update(int x, int y, int v){
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= m; j += j & -j)
			bit[i][j] += v;
}
ll get(int x, int y){
	ll ret = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			ret += bit[i][j];
	return ret;
}
int main(){
	n = re, m = re;
	while(1){
		int t = re; 
		if (!t) break;
		if (t == 1){
			int r = re, c = re, x = re;
			if ((r + c) & 1) x = -x;
			int nv = x - g[r][c];
			update(r, c, nv); g[r][c] = x;
		} else {
			int a = re - 1, b = re - 1, c = re, d = re; ll ans = get(c, d) - get(c, b) - get(a, d) + get(a, b);
			if ((a + b + 2) & 1) ans = -ans;
			printf("%lld\n", ans);
		}
		
	}
}