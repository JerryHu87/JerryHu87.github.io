#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector<int> nodes[400001];pair<long long,long long> dp[400001];bool vis[400001];long long d,numd;int a,b,n;

void dfs(int cur){
	vis[cur] = 1;
	for(unsigned int i = 0;i<nodes[cur].size();i++){
		if(vis[nodes[cur][i]]){continue;}
		dfs(nodes[cur][i]);
		if(dp[cur].first + dp[nodes[cur][i]].first+1 > d){
			d = dp[cur].first+dp[nodes[cur][i]].first+1;
			numd = dp[cur].second*dp[nodes[cur][i]].second;
		}
		else if(dp[cur].first+dp[nodes[cur][i]].first+1 == d){
			numd += dp[cur].second*dp[nodes[cur][i]].second;
		}
		if(dp[nodes[cur][i]].first+1 > dp[cur].first){
			dp[cur].first = dp[nodes[cur][i]].first+1;
			dp[cur].second = dp[nodes[cur][i]].second;
		}
		else if(dp[nodes[cur][i]].first+1 == dp[cur].first){
			dp[cur].second += dp[nodes[cur][i]].second;
		}
	}
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n-1;i++){
		cin >> a >> b;
		dp[i] = {0,1};
		nodes[a].push_back(b);nodes[b].push_back(a);
	}
	dp[n] = {0,1};
	vis[1] = 1;
	dfs(1);
	cout << d+1 << " " << numd << "\n";
	return 0;
}
