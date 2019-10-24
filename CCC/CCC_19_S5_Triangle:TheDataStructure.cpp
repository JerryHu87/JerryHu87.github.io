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

ll n,k,ans,arr[3001][3001],bit[3001][3001];

void update(ll x,ll y,ll val){
	for(;x<=n;x+=x&-x){
		for(ll a = y;a<=n;a+=a&-a){
			bit[x][a] = max(bit[x][a],val);
		}
	}
}
ll query(ll x,ll y){
	ll ans = -INF;
	for(;x>0;x-=x&-x){
		for(ll a = y;a>0;a-=a&-a){
			ans = max(ans,bit[x][a]);
		}
	}
	return ans;
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	for(ll i = 1;i<=n;i++){
		for(ll j = n-i+1;j<=n;j++){
			cin >> arr[i][j];
		}
	}
	for(ll i = n;i>=1;i--){
		for(ll x = i,y = n;x<=n;x++,y--){
			update(x,y,arr[x][y]);
		}
		for(ll x = i+k-1,y = n;x<=n;x++,y--){
			ans += query(x,y);
		}
	}
	cout << ans << "\n";
	return 0;
}
/*
4 2
3
1 2
4 2 1
6 1 4 2
 */
