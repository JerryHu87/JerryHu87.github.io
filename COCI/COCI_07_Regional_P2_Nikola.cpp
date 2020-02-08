#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n;int cost[1000];int dist[1000][1000];queue<pair<int,int> > q;int mi = INF;pair<int,int> cur;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&cost[i]);
	}
	memset(dist,INF,sizeof(dist));dist[0][0] = 0;dist[1][1] = cost[1];
	q.push({1,1});
	while(!q.empty()){
		cur = q.front();q.pop();
		if(cur.first == n-1 && dist[cur.first][cur.second] < mi){
			mi = dist[cur.first][cur.second];continue;
		}
		if(cur.first+cur.second+1<n && dist[cur.first+cur.second+1][cur.second+1] > dist[cur.first][cur.second]+cost[cur.first+cur.second+1]){
			 dist[cur.first+cur.second+1][cur.second+1] = dist[cur.first][cur.second]+cost[cur.first+cur.second+1];q.push({cur.first+cur.second+1,cur.second+1});
		}
		if(cur.first-cur.second>=0 && dist[cur.first-cur.second][cur.second] > dist[cur.first][cur.second]+cost[cur.first-cur.second]){
			 dist[cur.first-cur.second][cur.second] = dist[cur.first][cur.second]+cost[cur.first-cur.second];q.push({cur.first-cur.second,cur.second});
		}
	}
	printf("%d\n",mi);
	return 0;
}
