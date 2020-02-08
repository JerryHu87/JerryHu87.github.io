#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pdd pair<long double, long double>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for(;(c>47&&c<58);c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long double PI = 3.14159265359;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

int dfn[1001],low[1001],cc[1001];
bool vis[1001];
int n,m,ans,idx = 1;
vector<int> adj[1001],compadj[1001];
set<pii> brg;

void tarjan(int u,int p){
	dfn[u] = low[u] = idx++;
	for(int e:adj[u]){
		if(dfn[e] == 0){
			tarjan(e,u);
			if(low[e] > dfn[u]){
				brg.insert({e,u});
				brg.insert({u,e});
			}
			low[u] = min(low[u],low[e]);
		}
		else if(e != p){
			low[u] = min(low[u],dfn[e]);
		}
	}
}
void dfs(int u){
	cc[u] = idx;
	for(int e:adj[u]){
		if(vis[e] || brg.count({e,u})){continue;}
		vis[e] = 1;
		dfs(e);
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m;
	for(int i = 0,a,b;i<m;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	tarjan(1,1);
	idx = 1;
	for(int i = 1;i<=n;i++){
		if(vis[i]){continue;}
		vis[i] = 1;
		dfs(i);
		idx++;
	}
	for(pii e:brg){
		compadj[cc[e.first]].push_back(cc[e.second]);
		compadj[cc[e.second]].push_back(cc[e.first]);
	}
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		bool c = 0;
		for(int e:compadj[u]){
			if(!vis[e]){
				q.push(e);
				vis[e] = 1;
				c = 1;
			}
		}
		if(!c){ans++;}
	}

	idx == 2 ? cout << "0\n":cout << (ans+1)/2 << "\n";
	return 0;
}
