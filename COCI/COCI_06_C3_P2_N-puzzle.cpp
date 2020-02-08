#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

char grid[4][4];

int main(){
	int cnt = 0;int ans = 0;char n;
	for(int i= 0;i<4;i++){
		for(int j = 0;j<4;j++){
			grid[i][j] = (char)(cnt+'A');cnt++;
		}
	}
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			scanf(" %c",&n);bool c = 0;
			if(n == '.')continue;
			for(int x = 0;x<4;x++){
				for(int y = 0;y<4;y++){
					if(n == grid[x][y]){
						ans += (abs(x-i)+abs(y-j));c = 1;
					}
				}
				if(c)break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
