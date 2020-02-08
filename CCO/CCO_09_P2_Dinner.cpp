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

int n,k,tot;
int dp[2][101][101];
string s;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> k >> s;
	memset(dp,-1,sizeof(dp));
	for(int i = 0;i<n;i++){
		bool tmp = (s[i] == 'G');
		dp[tmp][i][i] = 1;
		if(i >= 1 && s[i] != s[i-1]){tot++;}
	}
	for(int len = 1;len<=n;len++){
		for(int i = 0;i+len<n;i++){
			int j = i+len;
			for(int k = i;k<j;k++){
				int lv = dp[0][i][k],rv = dp[0][k+1][j];
				if(lv != -1 && rv != -1){
					dp[0][i][j] = max(dp[0][i][j],lv+rv);
				}
				lv = dp[1][i][k],rv = dp[1][k+1][j];
				if(lv != -1 && rv != -1){
					dp[1][i][j] = max(dp[1][i][j],lv+rv);
				}
			}
			if(dp[0][i][j] >= k){dp[1][i][j] = max(dp[1][i][j],0);}
			if(dp[1][i][j] >= k){dp[0][i][j] = max(dp[0][i][j],0);}
		}
	}
	(dp[0][0][n-1] >= k || dp[1][0][n-1] >= k) ? cout << (tot+1)/2+1<< "\n":cout << "-1\n";
	return 0;
}
