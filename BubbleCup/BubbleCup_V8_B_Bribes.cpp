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

int down[20][100001],up[20][100001],subt[20][100001],sz[100001];
bool done[100001];
ll psa[500001];
vector<pii> adj[100001];
int n,idx = 1,k;
ll ans;
map<pii,int> m;

void size(int u,int p){
	sz[u] = 1;
	for(pii e:adj[u]){
		if(e.second != p && !done[e.second]){
			size(e.second,u);
			sz[u] += sz[e.second];
		}
	}
}
int centroid(int u,int p,int tot){
	for(pii e:adj[u]){
		if(!done[e.second] && e.second != p && sz[e.second]*2>tot){return centroid(e.second,u,tot);}
	}
	return u;
}
void dfs(int u,int p,int dep){
	subt[dep][u] = idx;
	//debug(subt[dep][u],u);
	for(pii e:adj[u]){
		if(!done[e.second] && e.second != p){dfs(e.second,u,dep);}
	}
}
void decomp(int u,int dep){
	size(u,u);
	if(sz[u] == 1){return;}
	int st = centroid(u,u,sz[u]);
	//debug(st,dep);
	done[st] = 1;
	subt[dep][st] = idx++;
	for(pii e:adj[st]){
		if(!done[e.second]){
			dfs(e.second,st,dep);
			idx++;
		}
	}
	for(pii e:adj[st]){
		if(!done[e.second]){decomp(e.second,dep+1);}
	}
}
void calc2(int u,int p,int dep){
	int temp = 0;
	for(pii e:adj[u]){
		if(e.second == p){temp = e.first;}
		if(e.second != p && !done[e.second]){
			calc2(e.second,u,dep);
			//debug(e.first,e.second,down[dep][e.second]);
			m[{min(u,e.second),max(u,e.second)}] += e.first*down[dep][e.second];
			down[dep][u] += down[dep][e.second];
			up[dep][u] += up[dep][e.second];
		}
	}
	//debug(u,temp,up[dep][u]);
	m[{min(u,p),max(u,p)}] += temp*up[dep][u];
}
void calc(int u,int dep){
	size(u,u);
	if(sz[u] == 1){return;}
	int st = centroid(u,u,sz[u]);
	done[st] = 1;
	calc2(st,st,dep);
	for(pii e:adj[st]){
		if(!done[e.second]){calc(e.second,dep+1);}
	}
}
void init(){
	for(int i = 1;i<=500000;i++){
		psa[i] = (psa[i-1]+fpow(2,i-1,MOD))%MOD;
		//debug(psa[i]);
	}
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	init();
	cin >> n;
	for(int i = 0,a,b,c;i<n-1;i++){
		cin >> a >> b >> c;
		if(c == 1){
			adj[a].push_back({0,b});
			adj[b].push_back({1,a});
			m[{min(a,b),max(a,b)}] = 0;
		}
		else{
			adj[a].push_back({0,b});
			adj[b].push_back({0,a});
		}
	}
	decomp(1,0);
	cin >> k;
	int l = 1;
	for(int i = 0,a;i<k;i++){
		cin >> a;
		if(l == a){continue;}
		int lo = 0;
		while(subt[lo][l] == subt[lo][a]){lo++;}
		up[lo][l]++;down[lo][a]++;
		l = a;
	}
	memset(done,0,sizeof(done));
	calc(1,0);
	for(pair<pii,int> e:m){ans = (ans+psa[e.second])%MOD;}
	cout << ans << "\n";
	return 0;
}
/*
5
1 2 0
2 3 0
5 1 1
3 4 1
6
5 4 5 2 2 5
ans: 8
 */
