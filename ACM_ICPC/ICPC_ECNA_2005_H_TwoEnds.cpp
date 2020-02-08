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

int n,idx = 1;
int arr[1001],dp[1001][1001][2];

int f(int l,int r,bool t){
	if(dp[l][r][t] != -1){return dp[l][r][t];}
	if(t){
		if(l == r){return -arr[l];}
		if(arr[l] >= arr[r]){return dp[l][r][1] = f(l+1,r,0)-arr[l];}
		else{return dp[l][r][1] = f(l,r-1,0)-arr[r];}
	}
	return dp[l][r][0] = max(f(l+1,r,1)+arr[l],f(l,r-1,1)+arr[r]);
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	while(n != 0){
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i<n;i++){
			cin >> arr[i];
		}
		cout << "In game " << idx++ << ", the greedy strategy might lose by as many as " << f(0,n-1,0) << " points.\n";
		cin >> n;
	}
	return 0;
}
