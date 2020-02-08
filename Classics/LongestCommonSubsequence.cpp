#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int a[1001];int b[1001];int dp[1001][1001];int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	for(int i =  1;i<=m;i++)scanf("%d",&b[i]);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
