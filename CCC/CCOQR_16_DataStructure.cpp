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
#define MAXN 100001

ll n,m,curm = INF;
ll ans;
pll ev[MAXN];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m;
	for(ll i = 1;i<=m;i++){
		cin >> ev[i].second >> ev[i].first;
	}
	sort(ev+1,ev+m+1);
	for(ll i = 1;i<=m;i++){
		if(i != 1 && ev[i].first != ev[i-1].first){
			ll tmp = curm;
			curm = min(n+1,curm+ev[i].first-ev[i-1].first);
			//if(tmp+ev[i].first-ev[i-1].first > n){}
			ans += ((n-tmp+1)*(n-tmp+2)/2)-((n-curm+1)*(n-curm+2)/2);
			curm = min(curm,ev[i].second);
		}
		else{
			curm = min(curm,ev[i].second);
		}
		//debug(i,ans);
	}
	cout << ans+(n-curm+1)*(n-curm+2)/2 << "\n";
	return 0;
}
