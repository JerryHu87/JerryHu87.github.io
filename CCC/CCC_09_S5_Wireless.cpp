#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<long,long>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int grid[30001][1001],sweep[30001];
int ma,cnt;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i = 0;i<k;i++){
		int x,y,r,b;
		scanf("%d%d%d%d",&x,&y,&r,&b);
		int p1 = y,p2 = y;
		grid[y][max(1,x-r)] += b;
		p1++;p2--;
		for(int j = x-r+1;j<=x;j++){
			while((j-x)*(j-x)+(p1-y)*(p1-y)-r*r <= 0){
				if(p1<=m){grid[p1][max(1,j)] += b;}
				p1++;
			}
			while((j-x)*(j-x)+(p2-y)*(p2-y)-r*r <= 0){
				if(p2>=1){grid[p2][max(1,j)] += b;}
				p2--;
			}
		}
		p1--;p2++;
		for(int j = x+1;j<=x+r;j++){
			while((j-x)*(j-x)+(p1-y)*(p1-y)-r*r > 0){
				if(p1>=1 && p1<=m && j<=n){grid[p1][j] -= b;}
				p1--;
			}
			while((j-x)*(j-x)+(p2-y)*(p2-y)-r*r > 0){
				if(p2<=m && p2>=1 && j<=n){grid[p2][j] -= b;}
				p2++;
			}
		}
		if(x+r+1 <= n){grid[y][x+r+1] -= b;}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			sweep[j] += grid[j][i];
		}
		for(int j = 1;j<=m;j++){
			if(sweep[j] > ma){
				ma = sweep[j];
				cnt = 1;
			}
			else if(sweep[j] == ma){
				cnt++;
			}
		}
	}
	printf("%d\n%d\n",ma,cnt);
	return 0;
}
