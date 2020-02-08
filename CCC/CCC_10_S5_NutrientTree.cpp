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

pii adj[201];
deque<int> dq;
int cnt,x;
string s;
int val[201],dp[201][2501],dpl[201][2501],dpr[201][2501],pw[2501];

void init(){
	for(int i = 0;i<=2500;i++){
		pw[i] = i*i;
	}
}
void parse(){
	int p = 0;
	bool n = 0;
	for(int i = 0;i<(int)s.size();i++){
		//debug(i);
		char c = s[i];
		if(!n && c >= '0' && c <= '9'){
			p = i;
			n = 1;
		}
		else if(n && !(c >= '0' && c <= '9')){
			cnt++;
			val[cnt] = stoi(s.substr(p,i-p));
			if(adj[dq.back()].first == 0){adj[dq.back()].first = cnt;}
			else{adj[dq.back()].second = cnt;}
			n = 0;
		}
		if(c == '('){
			cnt++;
			if(!dq.empty() && adj[dq.back()].first == 0){adj[dq.back()].first = cnt;}
			else if(!dq.empty()){adj[dq.back()].second = cnt;}
			dq.push_back(cnt);
		}
		else if(c == ')'){
			dq.pop_back();
		}
	}
	if(n){val[++cnt] = stoi(s.substr(p,s.size()-p));}
}
void dfs(int u){
	if(val[u] != 0){
		for(int i = 0;i<=x;i++){
			dp[u][i] = val[u]+i;
		}
		return;
	}
	if(adj[u].first != 0){dfs(adj[u].first);}
	if(adj[u].second != 0){dfs(adj[u].second);}
	for(int i = 0;i<=x;i++){
		for(int j = 0;j<=i;j++){
			int tmp = i-j+1;
			dpl[u][i] = max(dpl[u][i],min(dp[adj[u].first][j],pw[tmp]));
			dpr[u][i] = max(dpr[u][i],min(dp[adj[u].second][j],pw[tmp]));
		}
	}
	for(int i = 0;i<=x;i++){
		for(int j = 0;j<=i;j++){
			dp[u][i] = max(dp[u][i],dpl[u][j]+dpr[u][i-j]);
		}
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	getline(cin,s);
	cin >> x;
	parse();
	init();
	//for(int i = 1;i<=20;i++){debug(val[i],adj[i].first,adj[i].second);}
	memset(dp,-1,sizeof(dp));
	memset(dpl,-1,sizeof(dpl));
	memset(dpr,-1,sizeof(dpr));
	dfs(1);
	cout << dp[1][x] << "\n";
	return 0;
}
