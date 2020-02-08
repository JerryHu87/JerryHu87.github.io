#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

deque<pair<int,int> > dq;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	int n,a;long long ans = 0;
	scanf("%d",&n);
	for(int r = 1;r<=n;r++){
		scanf("%d",&a);int temp = 1;
		while(!dq.empty() && dq.back().first<=a){
			ans += dq.back().second;
			if(dq.back().first == a){temp += dq.back().second;}
			dq.pop_back();
		}
		if(!dq.empty())ans++;
		dq.push_back({a,temp});
	}
	printf("%lld\n",ans);
	return 0;
}
