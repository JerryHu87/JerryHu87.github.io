#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,x,l,h,a,b;long long ans;

int main(){
	scanf("%d %d",&n,&x);l = h = x;
	for(int i = 0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a>h){
			ans += (a-h);l = h;h = a;
		}
		else if(b < l){
			ans += (l-b);h = l;l = b;
		}
		else{
			l = max(l,a);h = min(h,b);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
