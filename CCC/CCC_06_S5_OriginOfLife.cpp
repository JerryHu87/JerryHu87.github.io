#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
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
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
#define MAXN 10000000

int dp[MAXN];
bool eden[MAXN],grid[10][10];
bool temp;
int n,m,a,b,c;

bool f(int x,int y){
	return x>=0 && x<n && y>=0 && y<m && grid[x][y];
}
void msktogrid(int msk){
	int p = 0;
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			grid[i][j] = ((msk&(1<<p)) > 0);
			p++;
			//cout << grid[i][j];
		}
		//cout << endl;
	}
}
int gridtomsk(){
	int p = 0,nxt = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int v = f(i-1,j-1)+f(i-1,j)+f(i-1,j+1)+f(i,j-1)+f(i,j+1)+f(i+1,j-1)+f(i+1,j)+f(i+1,j+1);
			temp = grid[i][j];
			if(temp && (v < a || v > b)){temp = 0;}
			else if(!temp && v > c){temp = 1;}
			nxt |= (temp<<p);
			p++;
		}
	}
	return nxt;
}
void gen(int msk){
	if(eden[msk]){return;}
	eden[msk] = 1;
	msktogrid(msk);
	gen(gridtomsk());
}
void comp(int msk){
	msktogrid(msk);
	int nxt = gridtomsk();
	if(dp[nxt] > dp[msk]+1){
		dp[nxt] = dp[msk]+1;
		comp(nxt);
	}
}
void init(){
	memset(dp,INF,sizeof(dp));
	for(int i = 0;i<(1<<(m*n));i++){
		if(eden[i]){continue;}
		msktogrid(i);
		gen(gridtomsk());
	}
	for(int i = 0;i<(1<<(m*n));i++){
		if(!eden[i]){
			dp[i] = 0;
			comp(i);
		}
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m >> a >> b >> c;
	init();
	int st = 0,p = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			char r;
			cin >> r;
			st |= ((r == '*')<<p);
			p++;
		}
	}
	dp[st] == INF ? cout << "-1\n":cout << dp[st] << '\n';
	return 0;
}

/*
I:
4 5 2 3 2
.****
**.*.
*****
*..*.
O:
0

I:
4 5 2 3 2
**.**
..*.*
....*
*****
O:
1

I:
4 5 2 3 2
.****
.****
.****
.****
O:
2
 */
