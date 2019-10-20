#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int dist[201][2001];vector<pair<int,pair<int, int> > > nodes[2001];bool inq[2001];queue<pair<int,int> > q;int k,n,m,a,b,c,d;int mi = INF;

int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		nodes[a].push_back({d,{c,b}});
		nodes[b].push_back({d,{c,a}});
	}
	scanf("%d%d",&a,&b);memset(dist,INF,sizeof(dist));dist[0][a] = 0;q.push({0,a});
	while(!q.empty()){
		pair<int,int> cur = q.front();q.pop();
		if(cur.second == b && cur.first<k)mi = min(mi,dist[cur.first][cur.second]);
		for(int i = 0;i<nodes[cur.second].size();i++){
			if(nodes[cur.second][i].first+cur.first<k && dist[nodes[cur.second][i].first+cur.first][nodes[cur.second][i].second.second] > dist[cur.first][cur.second] + nodes[cur.second][i].second.first){
				dist[nodes[cur.second][i].first+cur.first][nodes[cur.second][i].second.second] = dist[cur.first][cur.second] + nodes[cur.second][i].second.first;
				q.push({cur.first+nodes[cur.second][i].first,nodes[cur.second][i].second.second});
			}
		}
	}
	mi == INF ? printf("-1\n"):printf("%d\n",mi);
	return 0;
}
