#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int a,b,c,d,n;bool dp[31][31][31][31];

int main(){
	scanf("%d",&n);
	for(int p = 0;p<=30;p++){
		for(int q = 0;q<=30;q++){
			for(int x = 0;x<=30;x++){
				for(int y = 0;y<=30;y++){
					if(!(p-2<0 || q-1<0 || y-2<0) && !dp[p-2][q-1][x][y-2]){
						dp[p][q][x][y] = 1;
					}
					if(!(p-1<0 || q-1<0 || x-1<0 || y-1<0) && !dp[p-1][q-1][x-1][y-1]){
						dp[p][q][x][y] = 1;
					}
					if(!(x-2<0 || y-1<0) && !dp[p][q][x-2][y-1]){
						dp[p][q][x][y] = 1;
					}
					if(!(q-3<0) && !dp[p][q-3][x][y]){
						dp[p][q][x][y] = 1;
					}
					if(!(p-1<0 || y-1<0) && !dp[p-1][q][x][y-1]){
						dp[p][q][x][y] = 1;
					}
				}
			}
		}
	}
	for(int i = 0;i<n;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(dp[a][b][c][d]){
			printf("Patrick\n");
		}
		else{
			printf("Roland\n");
		}
	}
	return 0;
}
