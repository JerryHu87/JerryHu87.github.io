#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[31];bool dp[31][30001];

int main(){
	for(int z = 0;z<5;z++){
		int n;int sum = 0;memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i = 0;i<=n;i++){dp[i][0] = 1;}
		for(int i = 1;i<=n;i++){
			scanf("%d",&arr[i]);sum += arr[i];
		}
		int ma = sum;
		for(int i = 1;i<=n;i++){
			for(int j = arr[i];j<=30000;j++){
				if(dp[i-1][j-arr[i]] || dp[i-1][j]){
					dp[i][j] = 1;ma = min(ma,abs(sum-j-j));
				}
			}
		}
		printf("%d\n",ma);
	}
	return 0;
}
