#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > nodes[100001];
int dists[100000];
int distd[100000];

int main(){
	int n, m,a,b,c;
	scanf("%d%d", &n, &m);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d", &a, &b, &c);
		nodes[a].push_back(make_pair(c,b));
		nodes[b].push_back(make_pair(c,a));
	}
	memset(dists,INF,sizeof(dists));
	memset(distd,INF,sizeof(distd));
	dists[0] = 0;
	distd[n-1] = 0;
	pq.push(make_pair(0,0));
	while(!pq.empty()){
		pair<int, int> current = pq.top();pq.pop();
		if(current.first > dists[current.second]){continue;}
		for(int i = 0;i<nodes[current.second].size();i++){
			if(dists[nodes[current.second][i].second] > dists[current.second]+nodes[current.second][i].first){
				dists[nodes[current.second][i].second] = dists[current.second]+nodes[current.second][i].first;
				pq.push(make_pair(dists[nodes[current.second][i].second],nodes[current.second][i].second));
			}
		}
	}
	pq.push(make_pair(0,n-1));
	while(!pq.empty()){
		pair<int, int> current = pq.top();pq.pop();
		if(current.first > distd[current.second]){continue;}
		for(int i = 0;i<nodes[current.second].size();i++){
			if(distd[nodes[current.second][i].second] > distd[current.second]+nodes[current.second][i].first){
				distd[nodes[current.second][i].second] = distd[current.second]+nodes[current.second][i].first;
				pq.push(make_pair(distd[nodes[current.second][i].second],nodes[current.second][i].second));
			}
		}
	}
	int max = 0;
	for(int i = 0;i<n;i++){
		if(dists[i] +distd[i] > max){
			max = dists[i] +distd[i];
		}
	}
	cout << max << "\n";
	return 0;
}
