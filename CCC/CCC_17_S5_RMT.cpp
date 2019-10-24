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
#define MAXN 150001
#define SZ (ll)(ceil(sqrt(MAXN)))

ll n,m,q,sz;
ll arr[MAXN],shf[MAXN],idx[MAXN],bck[SZ],ini[MAXN];
vector<ll> lne[MAXN];
pll fl[MAXN][SZ];
bool s[MAXN][SZ];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q;
	ll sz = sqrt(n);
	for(ll i = 0;i<n;i++){
		cin >> idx[i];
		if(!s[idx[i]][i/sz]){
			fl[idx[i]][i/sz].first = i;
			s[idx[i]][i/sz] = 1;
		}
		fl[idx[i]][i/sz].second = i;
	}
	for(ll i = 0;i<n;i++){
		cin >> arr[i];
		ini[i] = lne[idx[i]].size();
		lne[idx[i]].push_back(i);
		bck[i/sz] += arr[i];
	}
	for(ll i = 0,a,b,c;i<q;i++){
		cin >> a;
		if(a == 1){
			cin >> b >> c;b--;c--;
			ll l = b/sz,r = c/sz,ans = 0;
			if(l == r){
				for(;b<=c;b++){ans += arr[lne[idx[b]][(ini[b]-shf[idx[b]]+lne[idx[b]].size())%lne[idx[b]].size()]];}
			}
			else{
				for(ll j = b;j<=(l+1)*sz-1;j++){ans += arr[lne[idx[j]][(ini[j]-shf[idx[j]]+lne[idx[j]].size())%lne[idx[j]].size()]];}
				for(ll j = l+1;j<=r-1;j++){ans += bck[j];}
				for(ll j = r*sz;j<=c;j++){ans += arr[lne[idx[j]][(ini[j]-shf[idx[j]]+lne[idx[j]].size())%lne[idx[j]].size()]];}
			}
			cout << ans << "\n";
		}
		else{
			cin >> b;
			for(ll j = 0;j<=sz;j++){
				if(!s[b][j]){continue;}
				fl[b][j].first = lne[b][(ini[fl[b][j].first]-1+lne[b].size())%lne[b].size()];
				bck[j] = bck[j]-arr[fl[b][j].second]+arr[fl[b][j].first];
				fl[b][j].second = lne[b][(ini[fl[b][j].second]-1+lne[b].size())%lne[b].size()];
			}
			shf[b] = (shf[b]+1)%lne[b].size();
		}
	}
	return 0;
}
/*
I:
5 3 7
1 2 1 2 1
1 2 3 4 5
1 1 5
2 1
2 2
2 2
2 1
1 1 5
1 1 3

O:
15
15
10

I:
5 2 5
1 2 1 2 2
1 2 3 4 5
1 1 5
2 1
1 3 5
2 2
1 1 3

O:
15
10
9

I:
3 1 7
1 1 1
114 101 109
1 1 1
2 1
1 1 1
2 1
1 1 1
2 1
1 1 1

O:
114
109
101
114
 */
