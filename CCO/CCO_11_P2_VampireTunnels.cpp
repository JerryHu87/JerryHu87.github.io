#include<bits/stdc++.h>
using namespace std;


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
vector<pair<bool,pair<int, int> > > nodes[1600]; long long d1[1600];long long sd1[1600]; long long d2[1600];long long sd2[1600];
pair<int, pair<int, int> > edges[10000];bool sun[10000];
int s, n, m,a,b,c,d;

int main(){
	scanf("%d",&s);
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		nodes[a].push_back({d,{c,b}});
		nodes[b].push_back({d,{c,a}});
		if(d == 1){sun[i] = 1;}
		edges[i] = {c,{a,b}};
	}
	memset(d1,INF,sizeof(d1));memset(sd1,INF,sizeof(sd1));
	d1[0] = 0;sd1[0] = 0;
	pq.push({0,0});
	while(!pq.empty()){
		pair<long long, int> current = pq.top();pq.pop();
		if(current.first > d1[current.second]){continue;}
		for(int i = 0;i<nodes[current.second].size();i++){
			if(d1[nodes[current.second][i].second.second] > d1[current.second] +  nodes[current.second][i].second.first){
				d1[nodes[current.second][i].second.second] = d1[current.second] + nodes[current.second][i].second.first;
				if(nodes[current.second][i].first){sd1[nodes[current.second][i].second.second] = sd1[current.second]+nodes[current.second][i].second.first;}
				else {sd1[nodes[current.second][i].second.second] = sd1[current.second];}
				pq.push({d1[nodes[current.second][i].second.second],nodes[current.second][i].second.second});
			}
		}
	}
	memset(d2,INF,sizeof(d2));memset(sd2,INF,sizeof(sd2));
	d2[n-1] = 0;sd2[n-1] = 0;
	pq.push({0,n-1});
	while(!pq.empty()){
		pair<long long, int> current = pq.top();pq.pop();
		if(current.first > d2[current.second]){continue;}
		for(int i = 0;i<nodes[current.second].size();i++){
			if(d2[nodes[current.second][i].second.second] > d2[current.second] +  nodes[current.second][i].second.first){
				d2[nodes[current.second][i].second.second] = d2[current.second] + nodes[current.second][i].second.first;
				if (nodes[current.second][i].first){sd2[nodes[current.second][i].second.second] = sd2[current.second]+nodes[current.second][i].second.first;}
				else {sd2[nodes[current.second][i].second.second] = sd2[current.second];}
				pq.push({d2[nodes[current.second][i].second.second],nodes[current.second][i].second.second});
			}
		}
	}
	int mi = INF;
	for(int i = 0;i<m;i++){
		if(d1[edges[i].second.first]+d2[edges[i].second.second]+edges[i].first <= mi){
			if(sun[i] && sd1[edges[i].second.first]+sd2[edges[i].second.second]+edges[i].first>s){}
			else if(sd1[edges[i].second.first]+sd2[edges[i].second.second]>s){}
			else{mi = d1[edges[i].second.first]+d2[edges[i].second.second]+edges[i].first;}
		}
		if(d1[edges[i].second.second]+d2[edges[i].second.first]+edges[i].first <= mi){
			if(sun[i] && sd1[edges[i].second.second]+sd2[edges[i].second.first]+edges[i].first>s){}
			else if(sd1[edges[i].second.second]+sd2[edges[i].second.first]>s){}
			else{mi = d1[edges[i].second.second]+d2[edges[i].second.first]+edges[i].first;}
		}
	}
	mi == INF ? printf("-1\n"):printf("%d\n",mi);
	return 0;
}
