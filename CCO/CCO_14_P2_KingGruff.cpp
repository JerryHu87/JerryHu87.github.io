#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cin.sync_with_stdio(0);cin.tie(0);
//cout << fixed;cout << setprecision();

int n,m,s,d,a,b,w,c,q,v,ans,lo,hi,mid;vector<pair<int,int> > nodes[100001];vector<pair<int,int> > rev[100001];int cost[100001];int weight[100001];
int d1[100001];int d2[100001];priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;pair<int,int> edges[100001];
int psa[100001];pair<int,int> arr[100001];

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i = 0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&w,&c);
		nodes[a].push_back({i,b});rev[b].push_back({i,a});edges[i] = {a,b};
		cost[i] = c;weight[i] = w;
	}
	memset(d1,INF,sizeof(d1));memset(d2,INF,sizeof(d2));d1[s] = 0;d2[d] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		pair<int,int> cur = pq.top();pq.pop();
		if(cur.first > d1[cur.second]){continue;}
		for(int i =0;i<nodes[cur.second].size();i++){
			if(d1[nodes[cur.second][i].second] > d1[cur.second]+weight[nodes[cur.second][i].first]){
				d1[nodes[cur.second][i].second] = d1[cur.second]+weight[nodes[cur.second][i].first];
				pq.push({d1[nodes[cur.second][i].second],nodes[cur.second][i].second});
			}
		}
	}
	pq.push({0,d});
	while(!pq.empty()){
		pair<int,int> cur = pq.top();pq.pop();
		if(cur.first > d2[cur.second]){continue;}
		for(int i =0;i<rev[cur.second].size();i++){
			if(d2[rev[cur.second][i].second] > d2[cur.second]+weight[rev[cur.second][i].first]){
				d2[rev[cur.second][i].second] = d2[cur.second]+weight[rev[cur.second][i].first];
				pq.push({d2[rev[cur.second][i].second],rev[cur.second][i].second});
			}
		}
	}
	for(int i = 0;i<m;i++){
		arr[i] = {d1[edges[i].first]+d2[edges[i].second]+weight[i],cost[i]};
	}
	sort(arr,arr+m);psa[0] = arr[0].second;
	for(int i = 1;i<m;i++){
		psa[i] = psa[i-1]+arr[i].second;
	}
	scanf("%d",&q);
	for(int z = 0;z<q;z++){
		scanf("%d",&v);ans = -1;lo = 0;hi = m-1;
		while(lo<=hi){
			mid = (lo+hi)/2;
			if(arr[mid].first<=v){
				lo = mid+1;
				if(mid > ans){ans = mid;}
			}
			else{
				hi = mid-1;
			}
		}
		ans ==  -1 ? printf("0\n"):printf("%d\n",psa[ans]);
	}
	return 0;
}
