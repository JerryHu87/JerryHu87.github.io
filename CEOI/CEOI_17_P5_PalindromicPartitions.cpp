#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
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

int n;
ll pw[1000001];
string a;

void init(){
	pw[0] = 1;
	for(int i = 1;i<=1000000;i++){
		pw[i] = pw[i-1]*131;
	}
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	init();
	for(int z = 0;z<n;z++){
		cin >> a;
		ll p1 = 0,p2 = a.size()-1,lh = 0,rh = 0,p = 0,ans = 1;
		while(p1<p2){
			lh += a[p1]*pw[p];rh = rh*131+a[p2];
			p++;p1++;p2--;
			if(lh == rh){
				ans += 2;
				lh = 0;rh = 0;p = 0;
				if(p1 > p2){ans--;}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
