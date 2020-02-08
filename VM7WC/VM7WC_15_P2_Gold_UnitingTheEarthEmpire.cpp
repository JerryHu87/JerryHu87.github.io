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

vector<ll> dq;
ll n,a,ans;

void gen(){a = rand()%100;}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> a;
	//srand(time(0));n = 10;gen();
	//cout << n << endl << a << endl;
	dq.push_back(a);
	for(ll i = 1;i<n;i++){
		//gen();cout << a << " ";
		ll temp = 0,lo = 0,hi = dq.size()-1;
		cin >> a;
		while(lo <= hi){
			ll mid = (lo+hi)/2;
			if(dq[mid] > a){
				lo = mid+1;
				temp = max(temp,mid);
			}
			else{
				hi = mid-1;
			}
		}
		ans += (dq.size()-temp);
		while(!dq.empty() && dq[dq.size()-1] < a){dq.pop_back();}
		dq.push_back(a);
		//cout << ans << endl;
	}
	cout << ans << "\n";
	return 0;
}
