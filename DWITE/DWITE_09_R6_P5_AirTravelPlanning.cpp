#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

queue<int> q;
int dist[40];
vector<pair<int, int> > nodes[40];
unordered_map<string, int> um;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	int n,c;
	string a, b;
	int index = 0;
	for(int z = 0;z<5;z++){
		cin >> n;
		index = 0;
		memset(dist, 0x3f3f3f3f, sizeof(dist));
		for(int i = 0;i<n;i++){
			cin >> a >> b >> c;
			if(!um.count(a)){
				um[a] = index;
				index++;
			}
			if(!um.count(b)){
				um[b] = index;
				index++;
			}
			nodes[um[a]].push_back(make_pair(c,um[b]));
		}
		q.push(um["YYZ"]);
		dist[um["YYZ"]] = 0;
		while(!q.empty()){
			int current = q.front();q.pop();
			for(int i = 0;i<nodes[current].size();i++){
				if(dist[nodes[current][i].second] > dist[current] +nodes[current][i].first){
					dist[nodes[current][i].second] = dist[current]+nodes[current][i].first;
					q.push(nodes[current][i].second);
				}
			}
		}
		cout << dist[um["SEA"]] << "\n";
		for(int i = 0;i<40;i++){nodes[i].clear();}
		um.clear();
	}
	return 0;
}
