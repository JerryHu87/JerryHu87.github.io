#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
#define MAXN 1<< 18

ll nodes[18][18],dp[18][MAXN];
int n,m,a,b,c;

int dfs(int msk,int cur){
	if(dp[cur][msk] != -1){
		return dp[cur][msk];
	}
	if(cur == n-1){
		return dp[cur][msk] = 0;
	}
	bool x = 0,y = 0;
	for(int i = 0;i<n;i++){
		if((msk&(1<<i)) == 0 && nodes[cur][i] > 0){
			int temp = dfs(msk|(1<<i),i);
			if(temp != -INF){y = 1;}
			dp[cur][msk] = max(dp[cur][msk],temp+nodes[cur][i]);
			x = 1;
		}
	}
	if(!y){return dp[cur][msk] = -INF;}
	if(!x){return dp[cur][msk] = -INF;}
	return dp[cur][msk];
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	memset(dp,-1,sizeof(dp));
	for(int i = 0;i<m;i++){
		cin >> a >> b >> c;
		nodes[a][b] = c;
	}
	cout << dfs(1,0) << "\n";
	return 0;
}
/*
5 6
3 1 6486
0 3 3275
0 4 2376
3 2 4209
4 2 7497
2 1 9990

ans:2376
 */
