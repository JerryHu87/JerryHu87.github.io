#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for(;(c>47&&c<58);c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

ll n,l,tot,ma;
ll arr1[101],arr2[101],dp[101][101][501];
ld ans = INF*INF;

ll f(ll i,ll j,ll u){
	if(j == 0 && u == 0){return 0;}
	if(i < 0 || j < 0 || u < 0){return INF;}
	if(dp[i][j][u] != -1){return dp[i][j][u];}
	return dp[i][j][u] = min(f(i-1,j-1,u-arr1[i])+arr2[i],f(i-1,j,u));
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cout << setprecision(3);cout << fixed;
	memset(dp,-1,sizeof(dp));
	cin >> n >> l;
	for(ll i = 0;i<n;i++){
		cin >> arr1[i];
		ma += arr1[i];
	}
	for(ll i = 0;i<n;i++){
		cin >> arr2[i];
		tot += arr2[i];
	}
	for(ll i = 0;i<502;i++){
		ld temp = min(f(n-1,l,i),f(n-1,n-l,i));
		if(temp != INF && temp != -1){ans = min(ans,((ld)(temp*(tot-temp))/(ld)(i*(ma-i))));}
	}
	ans = (round(ans*1000))/1000;
	cout << ans << "\n";
	return 0;
}
/*
3 1
3 2 1
1 2 3
ans: 0.556
3 2
2 2 2
3 3 3
ans: 2.250
 */
