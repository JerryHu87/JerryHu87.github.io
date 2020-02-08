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
#define MAXN 10001

int t,n,k,w;
int arr[MAXN],psa[MAXN],dp[501][MAXN];

int solve(){
	for(int i = 1;i<=k;i++){
		dp[i][0] = 0;
		for(int j = 1;j<=min(n,w);j++){
			dp[i][j] = max(dp[i][j],psa[j]);
		}
		for(int j = n;j>=max(0,n-w);j--){
			dp[i][n] = max(dp[i][n],psa[n]-psa[j]+dp[i-1][j]);
		}
		for(int j = 1;j<=n;j++){
			dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
			if(j >= w){
				dp[i][j] = max(dp[i][j],dp[i-1][j-w]+psa[j]-psa[j-w]);
			}
			if(i == 1){continue;}
			for(int x = w+1;x<=2*w && j-x >= 0;x++){
				dp[i][j] = max(dp[i][j],dp[i-2][j-x]+psa[j]-psa[j-x]);
			}
		}
	}
	return dp[k][n];
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> t;
	for(int z = 0;z<t;z++){
		memset(dp,-INF,sizeof(dp));
		cin >> n >> k >> w;
		for(int i = 1;i<=n;i++){
			cin >> arr[i];
			psa[i] = arr[i]+psa[i-1];
			dp[0][i] = 0;
		}
		dp[0][0] = 0;
		cout << solve() << "\n";
	}
	return 0;
}
