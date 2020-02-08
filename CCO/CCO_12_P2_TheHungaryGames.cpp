#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector<pair<int, int> > nodes[20001];vector<pair<int, int> > rev[20001];long long d1[20001];long long d2[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
pair<int, pair<int, int> > edges[100000];

int main(){
	int n, m,a,b,c;
	scanf("%d%d",&n, &m);
	memset(d1, INF, sizeof(d1));memset(d2, INF, sizeof(d2));
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		nodes[a].push_back(make_pair(c,b));
		rev[b].push_back(make_pair(c,a));
		edges[i] = make_pair(c,make_pair(a,b));
	}
	pq.push(make_pair(0,1));d1[1] = 0;
	while(!pq.empty()){
		pair<int, int> current = pq.top();pq.pop();
		if(current.first > d1[current.second])continue;
		for(int i = 0;i<nodes[current.second].size();i++){
			if(d1[nodes[current.second][i].second] > d1[current.second]+nodes[current.second][i].first){
				d1[nodes[current.second][i].second] = d1[current.second]+nodes[current.second][i].first;
				pq.push(make_pair(d1[nodes[current.second][i].second],nodes[current.second][i].second));
			}
		}
	}
	pq.push(make_pair(0,n));d2[n] = 0;
	while(!pq.empty()){
		pair<int, int> current = pq.top();pq.pop();
		if(current.first > d2[current.second])continue;
		for(int i = 0;i<rev[current.second].size();i++){
			if(d2[rev[current.second][i].second] > d2[current.second]+rev[current.second][i].first){
				d2[rev[current.second][i].second] = d2[current.second]+rev[current.second][i].first;
				pq.push(make_pair(d2[rev[current.second][i].second],rev[current.second][i].second));
			}
		}
	}
	int min = d1[n];int min2 = INF;
	for(int i = 0;i<m;i++){
		if(d1[edges[i].second.first]+d2[edges[i].second.second]+ edges[i].first< min2 && d1[edges[i].second.first]+d2[edges[i].second.second]+ edges[i].first != min)min2 = d1[edges[i].second.first]+d2[edges[i].second.second]+ edges[i].first;
	}
	if(min2 == INF){
		printf("-1\n");
	}
	else{
		printf("%d\n",min2);
	}
	return 0;
}
