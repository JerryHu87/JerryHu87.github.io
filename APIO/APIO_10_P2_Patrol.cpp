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

int n,k,l,ma;
vector<int> nodes[100001];
int dp[100001],dis[100001],p[100001];
queue<pii> q;
map<pii,int> m;


void crawl(int u){
	if(p[u] != u){
		m[{p[u],u}] = -1;
		m[{u,p[u]}] = -1;
		crawl(p[u]);
	}
}
void dfs(int u,int p){
	for(int e:nodes[u]){
		if(e != p){
			dfs(e,u);
			int temp = m[{u,e}];
			ma = max(ma,dp[u]+dp[e]+temp);
			dp[u] = max(dp[u],dp[e]+temp);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0,a,b;i<n-1;i++){
		scanf("%d%d",&a,&b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
		m[{a,b}] = 1;
		m[{b,a}] = 1;
	}
	q.push({1,1});
	while(!q.empty()){
		pii cur = q.front();q.pop();
		l = cur.first;
		for(int e:nodes[cur.first]){
			if(e != cur.second){
				q.push({e,cur.first});
			}
		}
	}
	q.push({l,l});
	p[l] = l;
	while(!q.empty()){
		pii cur = q.front();q.pop();
		l = cur.first;
		for(int e:nodes[cur.first]){
			if(e != cur.second){
				dis[e] = dis[cur.first]+1;
				p[e] = cur.first;
				q.push({e,cur.first});
			}
		}
	}
	if(k == 1){
		printf("%d\n",(n-1)*2-dis[l]+1);
	}
	else{
		crawl(l);
		int d = dis[l];
		dis[1] = 0;
		dfs(1,1);
		printf("%d\n",(n-1)*2-d-ma+2);
	}
	return 0;
}
