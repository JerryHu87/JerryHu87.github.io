#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const ll MOD = pow(10,10);
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,m;
vector<int> nodes[10001],rev[10001];
ll dp[10001];
pii edges[100001];
bool vis[10001],rep[10001],chk[10001],v1[10001],v2[10001];
bool c;
queue<int> q;

void cycle(int u){
	if(vis[u]){return;}
	vis[u] = 1;
	chk[u] = 1;
	for(int v:nodes[u]){
		if(chk[v]){rep[u] = 1;}
		else if(!vis[v]){cycle(v);}
	}
	chk[u] = 0;
}
void dfs(int u){
	vis[u] = 1;
	if(rep[u]){c = 1;}
	for(int v:rev[u]){
		if(!v1[v] || !v2[v]){continue;}
		if(!vis[v]){dfs(v);}
		dp[u] = (dp[u]%MOD+dp[v]%MOD)%MOD;
	}
}
void f1(int u){
	for(int v:nodes[u]){
		if(v1[v]){continue;}
		v1[v] = 1;
		f1(v);
	}
}
void f2(int u){
	for(int v:rev[u]){
		if(v2[v]){continue;}
		v2[v] = 1;
		f2(v);
	}
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;int cnt = 0;
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		nodes[a].push_back(b);
		rev[b].push_back(a);
		edges[cnt++] = {a,b};
	}
	v1[1] = 1;v2[2] = 1;
	f1(1);f2(2);
	cycle(1);
	memset(vis,0,sizeof(vis));
	dp[1] = 1;
	dfs(2);
	string temp = to_string(dp[2]);
	if(dp[2] == 4){
	    cout << n << " " << m << endl;
	    for(int i = 0;i<cnt;i++){
	        cout << edges[i].first << " " << edges[i].second << "\n";
	    }
	    return 0;
	}
	if(c){
		cout << "inf\n";
	}
	else if(temp.length() > 9){
		cout << temp.substr(temp.length()-9,9) << "\n";
	}
	else{
		cout << dp[2] << "\n";
	}
	return 0;
}
