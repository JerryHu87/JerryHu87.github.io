#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<long,long>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

long long n,k,q,a,b,psa[2500001];pair<long long, long long> arr[2500001];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> q;
	arr[1] = {1,1};psa[1] = 1;
	long long cnt = 1,dif = k;
	for(int i = 2;cnt<n;i++){
		arr[i].first = arr[i-1].second+1;
		arr[i].second = cnt+dif;
		psa[i] = psa[i-1]+arr[i].second-arr[i].first+1;
		cnt += dif;dif *= k;
	}
	for(int i = 0;i<q;i++){
		cin >> a >> b;
		long long ia = 1,ib = 1,dis = 0;
		while(!(arr[ia].first<=a && a<=arr[ia].second)){ia++;}
		while(!(arr[ib].first<=b && b<=arr[ib].second)){ib++;}
		while(ia > ib){
			a = (a-psa[ia-1]-1)/k+psa[ia-2]+1;
			ia--;dis++;
		}
		while(ib > ia){
			b = (b-psa[ib-1]-1)/k+psa[ib-2]+1;
			ib--;dis++;
		}
		while(a != b){
			a = (a-psa[ia-1]-1)/k+psa[ia-2]+1;
			b = (b-psa[ib-1]-1)/k+psa[ib-2]+1;
			ia--;ib--;dis+=2;
		}
		cout << dis << "\n";
	}
	return 0;
}
