#include<bits/stdc++.h>
using namespace std;

#define ll long long int
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

ll dp[100001],n;
unordered_map<ll,ll> um;

void f(ll cur){
	ll temp = (ll)sqrt(cur);
	for(ll i = 1;i<temp;i++){
		if(i == 1){dp[cur] += cur-cur/2;}
		else{dp[cur] += (cur/i-cur/(i+1))*dp[i]+dp[cur/i];}
	}
	if(cur/temp == temp){dp[cur] += dp[temp];}
	else{dp[cur] += (cur/temp-cur/(temp+1))*dp[temp]+dp[cur/temp];}
}
ll g(ll cur){
	if(cur < 100001){return dp[cur];}
	else if(um.count(cur)){return um[cur];}
	um[cur] = 0;
	ll temp = (ll)sqrt(cur);
	for(ll i = 1;i<temp;i++){
		if(i == 1){um[cur] += (cur/i-cur/(i+1));}
		else{um[cur] += (cur/i-cur/(i+1))*g(i)+g(cur/i);}
	}
	if(cur/temp == temp){um[cur] += g(temp);}
	else{um[cur] += (cur/temp-cur/(temp+1))*g(temp)+g(cur/temp);}
	return um[cur];
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	dp[1] = 1;
	for(ll i = 2;i<100001;i++){f(i);}
	cout << g(n) << "\n";
	return 0;
}
