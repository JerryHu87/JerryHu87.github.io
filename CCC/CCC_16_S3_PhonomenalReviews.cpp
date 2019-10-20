#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,m,a,b,l,root,e;
vector<int> initial[100000];vector<int> after[100000];
int dist[100000];bool pho[100000];

void prune(int current, int prev){
	if(dist[current] > l && pho[current]){
		l = dist[current];
		root = current;
	}
	for(int i = 0;i<initial[current].size();i++){
		if(initial[current][i] != prev){
			dist[initial[current][i]] = dist[current]+1;
			prune(initial[current][i],current);
			if(pho[initial[current][i]] || !after[initial[current][i]].empty()){
				after[initial[current][i]].push_back(current);
				after[current].push_back(initial[current][i]);
				e++;
			}
		}
	}
}
void dfs(int current, int prev){
	if(dist[current] > l && pho[current]){
		l= dist[current];
		root = current;
	}
	for(int i = 0;i<after[current].size();i++){
		if(after[current][i] != prev){
			dist[after[current][i]] = dist[current]+1;
			dfs(after[current][i],current);
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i<m;i++){
		scanf("%d", &root);
		pho[root] = 1;
	}
	for(int i = 0;i<n-1;i++){
		scanf("%d%d", &a, &b);
		initial[a].push_back(b);
		initial[b].push_back(a);
	}
	prune(root,-1);
	memset(dist,0,sizeof(dist));
	l = 0;
	dfs(root, -1);
	printf("%d\n",e*2-l);
	return 0;
}
