#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
#define MAXN 100001

int pr[MAXN],pc[MAXN];

int rFind(int x){
	if(pr[x] != x){
		return pr[x] = rFind(pr[x]);
	}
	return pr[x];
}
void rUnion(int x,int y){
	pr[rFind(x)] = rFind(y);
}
int cFind(int x){
	if(pc[x] != x){
		return pc[x] = cFind(pc[x]);
	}
	return pc[x];
}
void cUnion(int x,int y){
	pc[cFind(x)] = cFind(y);
}
struct edge{
	int x,y,c,t;
};
bool cmp(const edge a,const edge b){
	return a.c < b.c;
}

ll n,m,p,q;
ull ans;
vector<edge> edges;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> p >> q;
	for(int i = 1;i<=n;i++){pr[i] = i;}
	for(int i = 1;i<=m;i++){pc[i] = i;}
	for(int i = 0,a,b,c;i<p;i++){
		cin >> a >> b >> c;
		ans += c*n;
		edges.push_back({a,b,c,0});
	}
	for(int i = 0,a,b,c;i<q;i++){
		cin >> a >> b >> c;
		ans += c*m;
		edges.push_back({a,b,c,1});
	}
	sort(edges.begin(),edges.end(),cmp);
	int i = 0;
	while(n > 1 || m > 1){
		//cout << n << " " << m << " " << edges[i].t << " " << edges[i].c << "\n";
		//if(edges[i].t == 0 && m == 0){i++;continue;}
		//if(edges[i].t == 1 && n == 0){i++;continue;}
		if(edges[i].t == 1 && rFind(edges[i].x) != rFind(edges[i].y)){
			rUnion(edges[i].x,edges[i].y);
			ans -= m*edges[i].c;
			n--;
		}
		else if(edges[i].t == 0 && cFind(edges[i].x) != cFind(edges[i].y)){
			cUnion(edges[i].x,edges[i].y);
			ans -= n*edges[i].c;
			m--;
		}
		i++;
	}
	cout << ans << "\n";
	return 0;
}
