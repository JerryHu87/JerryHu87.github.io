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

ll bit[3001][3001],n,ans;

void update(ll x,ll y,ll v){
	y++;
	for(;y<=3001;y+=y&-y){
		bit[x][y]+=v;
	}
}
ll sum(ll x,ll y){
	y++;
	ll sum = 0;
	for(;y>0;y-=y&-y){
		sum += bit[x][y];
	}
	return sum;
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(ll i = 0,a,b,c,d;i<n;i++){
		cin >> a >> b >> c >> d;
		if(a == 1){
			update(b+c,c,d);
		}
		else{
			ll temp = sum(b+c,c+d)-sum(b+c,c-1);
			ans = (ans%MOD+temp%MOD)%MOD;
		}
	}
	cout << ans%MOD << "\n";
	return 0;
}
