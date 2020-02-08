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

int grid[20][20];
bool vis[20][20],fil[20][20];
int n,m,ma = INF;
bool c;

void rain(pii cur,int val){
	if(grid[cur.first][cur.second] > val){
		ma = min(ma,grid[cur.first][cur.second]);
		return;
	}
	if(cur.first == 0 || cur.second == 0 || cur.first == n-1 || cur.second == m-1){
		c = 1;
		return;
	}
	if(cur.second+1 < m && !vis[cur.first][cur.second+1]){
		vis[cur.first][cur.second+1] = 1;
		rain({cur.first,cur.second+1},val);
	}
	if(cur.first+1 < n && !vis[cur.first+1][cur.second]){
		vis[cur.first+1][cur.second] = 1;
		rain({cur.first+1,cur.second},val);
	}
	if(cur.second-1 >= 0 && !vis[cur.first][cur.second-1]){
		vis[cur.first][cur.second-1] = 1;
		rain({cur.first,cur.second-1},val);
	}
	if(cur.first-1 >= 0 && !vis[cur.first-1][cur.second]){
		vis[cur.first-1][cur.second] = 1;
		rain({cur.first-1,cur.second},val);
	}
}
void dfs(pii cur,int val){
	if(grid[cur.first][cur.second] > val && !fil[cur.first][cur.second]){
		ma = min(ma,grid[cur.first][cur.second]);
		return;
	}
	if(cur.first == 0 || cur.second == 0 || cur.first == n-1 || cur.second == m-1){
		c = 1;
		return;
	}
	if(cur.second+1 < m && !vis[cur.first][cur.second+1]){
		vis[cur.first][cur.second+1] = 1;
		dfs({cur.first,cur.second+1},val);
	}
	if(cur.first+1 < n && !vis[cur.first+1][cur.second]){
		vis[cur.first+1][cur.second] = 1;
		dfs({cur.first+1,cur.second},val);
	}
	if(cur.second-1 >= 0 && !vis[cur.first][cur.second-1]){
		vis[cur.first][cur.second-1] = 1;
		dfs({cur.first,cur.second-1},val);
	}
	if(cur.first-1 >= 0 && !vis[cur.first-1][cur.second]){
		vis[cur.first-1][cur.second] = 1;
		dfs({cur.first-1,cur.second},val);
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	//cin.sync_with_stdio(0);cin.tie(0);
	for(int z = 0;z<5;z++){
		int ans = 0;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				scanf("%d",&grid[i][j]);
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				rain({i,j},grid[i][j]);
				if(!c){fil[i][j] = 1;}
				c = 0;
				memset(vis,0,sizeof(vis));
			}
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				dfs({i,j},grid[i][j]);
				if(!c){ans += (ma-grid[i][j]);}
				c = 0;
				ma = INF;
				memset(vis,0,sizeof(vis));
			}
		}
		printf("%d\n",ans);
		memset(fil,0,sizeof(fil));
	}
	return 0;
}
