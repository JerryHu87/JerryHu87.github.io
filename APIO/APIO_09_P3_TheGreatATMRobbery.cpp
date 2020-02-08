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
#define MAXN 500001

pii adj[MAXN];
vector<pii> compadj;
int dfn[MAXN],low[MAXN],val[MAXN],scc[MAXN],sccval[MAXN];
stack<int> dq;
bool vis[MAXN],pub[MAXN],sccp[MAXN];
int idx = 1,s,p,n,m,sccidx = 1,ans;

void tarjan(int u){
	dfn[u] = low[u] = idx++;
	vis[u] = 1;
	dq.push(u);
	for(pii* it = lower_bound(adj,adj+m,make_pair(u,-INF));it != adj+m && it->first == u;it++){
		if(dfn[it->second] == 0){tarjan(it->second);}
		if(vis[it->second]){low[u] = min(low[u],low[it->second]);}
	}
	if(low[u] == dfn[u]){
		while(1){
			int cur = dq.top();dq.pop();
			vis[cur] = 0;
			scc[cur] = sccidx;
			if(pub[cur]){sccp[sccidx] = 1;}
			sccval[sccidx] += val[cur];
			if(u == cur){break;}
		}
		sccidx++;
	}
}
int dfs(int u){
	if(dfn[u] != -1){return dfn[u];}
	bool c = 0;
	int ret = -INF;
	for(auto it = lower_bound(compadj.begin(),compadj.end(),make_pair(u,-INF));it != compadj.end() && it->first == u;it++){
		c = 1;
		ret = max(ret,dfs(it->second));
	}
	if(sccp[u]){ret = max(ret,0);}
	else if((!c && !sccp[u]) || ret == -INF){return dfn[u] = -INF;}
	return dfn[u] = ret+sccval[u];
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		cin >> adj[i].first >> adj[i].second;
	}
	sort(adj,adj+m);
	for(int i = 1;i<=n;i++){
		cin >> val[i];
	}
	cin >> s >> p;
	for(int i = 0,a;i<p;i++){
		cin >> a;
		pub[a] = 1;
	}
	tarjan(s);
	for(int i = 0;i<m;i++){
		if(scc[adj[i].first] != scc[adj[i].second]){
			compadj.push_back({scc[adj[i].first],scc[adj[i].second]});
		}
	}
	sort(compadj.begin(),compadj.end());
	memset(dfn,-1,sizeof(dfn));
	cout << dfs(scc[s]) << "\n";
	return 0;
}
