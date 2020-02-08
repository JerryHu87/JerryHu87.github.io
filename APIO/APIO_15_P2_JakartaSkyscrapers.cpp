#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pdd pair<long double, long double>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for(;(c>47&&c<58);c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long double PI = 3.14159265359;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
#define MAXN 30001

int n,m,st,ed;
unordered_set<int> adj[MAXN];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int dis[MAXN];

int main(){
	memset(dis,INF,sizeof(dis));
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m;
	for(int i = 0,a,b;i<m;i++){
		cin >> a >> b;
		if(i == 0){st = a;}
		else if(i == 1){ed = a;}
		adj[a].insert(b);
	}
	pq.push({0,st});
	dis[st] = 0;
	while(!pq.empty()){
		pii u = pq.top();pq.pop();
		if(u.second == ed){break;}
		if(u.first > dis[u.second]){continue;}
		for(int d:adj[u.second]){
			for(int j = u.second-d;j>=0;j-=d){
				if(dis[j] > dis[u.second]+(u.second-j)/d){
					dis[j] = dis[u.second]+(u.second-j)/d;
					pq.push({dis[j],j});
				}
				if(adj[j].count(d)){break;}
			}
			for(int j = u.second+d;j<n;j+=d){
				if(dis[j] > dis[u.second]+(j-u.second)/d){
					dis[j] = dis[u.second]+(j-u.second)/d;
					pq.push({dis[j],j});
				}
				if(adj[j].count(d)){break;}
			}
		}
	}
	dis[ed] == INF ? cout << "-1\n":cout << dis[ed] << "\n";
	return 0;
}
