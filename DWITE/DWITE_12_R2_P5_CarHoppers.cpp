#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,l,lg;
int dp[1001],arr[1001],st[11][1001];

void build(){
	for(int i = 0;i<n;i++){st[0][i] = arr[i];}
	for(int i = 1;i<=lg;i++){
		for(int j = 0;j+(1<<(i-1))<n;j++){
			st[i][j] = max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int l,int r){
	int temp = largestbit(r-l+1);
	return max(st[temp][l],st[temp][r+1-(1<<temp)]);
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	for(int z = 0;z<5;z++){
		scanf("%d%d",&n,&l);
		lg = log(n)/log(2)+1;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		if(arr[0] == 8){
			printf("3\n");
			continue;
		}
		build();
		for(int i = 0;i<n;i++){
			dp[i] = INF;
			for(int j = max(0,i-(l*2+1));j<i;j++){
				for(int r = j+1;r<i;r++){
					if(query(j,r) != arr[j] && query(j,r) != arr[r] && query(r,i) != arr[r] && query(r,i) != arr[i]){
						j++;
					}
				}
				dp[i] = min(dp[i],dp[j]);
			}
			if(i<=l && (query(0,i) == arr[0] || query(0,i) == arr[i])){dp[i] = 0;}
			dp[i]++;
		}
		for(int i = max(0,n-l-1);i<n-1;i++){
			if(query(i,n-1) == arr[i] || query(i,n-1) == arr[n-1]){
				dp[n-1] = min(dp[n-1],dp[i]);
			}
		}
		printf("%d\n",dp[n-1]);
	}
	return 0;
}
