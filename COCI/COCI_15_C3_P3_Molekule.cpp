#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

bool c[100001];vector<int> nodes[100001];pair<int,int> edges[100001];bool vis[100001];

void dfs(int cur){
	for(int i = 0;i<nodes[cur].size();i++){
		if(vis[nodes[cur][i]])continue;
		c[nodes[cur][i]] = !c[cur];vis[nodes[cur][i]] = 1;dfs(nodes[cur][i]);
	}
}

int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++){
		scanf("%d%d",&a,&b);nodes[a].push_back(b);nodes[b].push_back(a);edges[i] = {a,b};
	}
	vis[1] = 1;dfs(1);
	for(int i = 0;i<n-1;i++){
		(!c[edges[i].first] && c[edges[i].second]) ? printf("1\n"):printf("0\n");
	}
	return 0;
}
