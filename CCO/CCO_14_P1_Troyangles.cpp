#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

bool grid[2000][2000];int n,s;char c;int dp[2001][2001];

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			scanf(" %c",&c);
			if(c == '#'){
				grid[i][j] = 1;dp[i][j] = 1;
			}
			else{
				grid[i][j] = 0;dp[i][j] = 0;
			}
		}
	}
	for(int i = n-2;i>=0;i--){
		for(int j = 0;j<n;j++){
			if(j+1<n && j-1>=0 && dp[i+1][j-1]>0 && dp[i+1][j]>0 && dp[i+1][j+1]>0 && grid[i][j]){
				dp[i][j] = (min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1])))+1;
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			s += dp[i][j];
		}
	}
	printf("%d\n",s);
	return 0;
}
