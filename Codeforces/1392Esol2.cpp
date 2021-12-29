#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=30;
ll f[N][N],n,k;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!(i&1)) f[i][j]=1ll<<i+j-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%lld ",f[i][j]);
		printf("\n");
	}
	fflush(stdout);
	int T;scanf("%d",&T);
	while (T--){
		scanf("%lld",&k);
		int x=1,y=1;printf("%d %d\n",x,y);
		while (x!=n || y!=n){
			if (x&1){
				if (!((k>>(x+y))&1))
					y++; else x++;
			} else {
				if ((k>>(x+y))&1)
					y++; else x++;
			}
			printf("%d %d\n",x,y);
		}
		fflush(stdout);
	}
}

 