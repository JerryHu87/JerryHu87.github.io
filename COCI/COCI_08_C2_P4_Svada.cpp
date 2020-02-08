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

ll t,n,m,v1,v2;
pll a[100],b[100];

void check(ll f,ll l){
	v1 = 0;v2 = 0;
	for(ll i = 0;i<n;i++){
		if(a[i].first > f){continue;}
		v1 += (f-a[i].first)/a[i].second+1;
	}
	for(ll i = 0;i<m;i++){
		if(b[i].first > l){continue;}
		v2 += (l-b[i].first)/b[i].second+1;
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> t >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	cin >> m;
	for(ll i = 0;i<m;i++){
		cin >> b[i].first >> b[i].second;
	}
	ll lo = 0,hi = t,ans = 0;
	while(lo <= hi){
		ll mid = (lo+hi)/2;
		check(mid,t-mid);
		if(v1 <= v2){
			lo = mid+1;
			ans = max(ans,mid);
		}
		else{
			hi = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}
