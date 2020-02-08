#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pdd pair<long double, long double>
#define pb push_back
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
#define MAXN 100001

set<int> f;
set<pii> vis;
int n,x;
vector<int> adj[MAXN];
map<int,int> id[MAXN];
int ans[MAXN],dis[MAXN],sz[MAXN];

void comp(pii u){
	//debug(u.first,u.second);
	memset(dis,0,sizeof(dis));
	memset(sz,0,sizeof(sz));
	f.clear();
	int v = 1;
	f.insert(u.first);
	dis[u.first] = 1;
	while(!vis.count(u)){
		//debug(u.first,u.second);
		v++;
		vis.insert(u);
		f.insert(u.second);
		if(dis[u.second] != 0){
			ans[u.second] = max(ans[u.second],v-dis[u.second]);
			sz[u.second] += (v-dis[u.second]);
		}
		dis[u.second] = v;
		u = {u.second,adj[u.second][(id[u.second][u.first]-1+adj[u.second].size())%adj[u.second].size()]};
	}
	for(int e:f){
		if(sz[e] != 0){ans[e] = max(ans[e],v-sz[e]-1);}
		else{ans[e] = max(ans[e],v-1);}
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	for(int i = 1,k;i<=n;i++){
		cin >> k;
		for(int j = 0,a;j<k;j++){
			cin >> a;
			adj[i].push_back(a);
			id[i][a] = j;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int v:adj[i]){
			if(!vis.count({i,v})){
				comp({i,v});
			}
		}
	}
	cin >> x;
	for(int i = 1,a;i<=x;i++){
		cin >> a;
		cout << ans[a] << "\n";
	}
	return 0;
}

/*
5
3 4 3 2
2 1 3
4 5 2 1 4
2 3 1
1 3
5
1
2
3
4
5
 */
