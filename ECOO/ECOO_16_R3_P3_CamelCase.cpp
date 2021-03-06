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

unordered_set<string> us;
int n,dp[2001];
string a;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a;
		us.insert(a);
	}
	for(int z = 0;z<10;z++){
		memset(dp,INF,sizeof(dp));
		dp[0] = 0;
		cin >> a;
		for(int i = 0;i<(int)a.length();i++){
			for(int j = 0;j<=i;j++){
				if(us.count(a.substr(i-j,j+1)))dp[i+1] = min(dp[i-j]+1,dp[i+1]);
			}
		}
		cout << dp[a.length()]-1 << "\n";
	}
	return 0;
}
