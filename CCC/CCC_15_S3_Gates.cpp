#include<bits/stdc++.h>
using namespace std;


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cin.sync_with_stdio(0);cin.tie(0);

set<int> s;int g,p,t;bool c = 0;

int main(){
	scanf("%d%d",&g,&p);
	for(int i = 1;i<=g;i++){s.insert(i*-1);}
	for(int i = 0;i<p;i++){
		scanf("%d",&t);
		if(s.lower_bound(t*-1) == s.end()){
			cout << i << endl;c = 1;
			break;
		}
		s.erase(s.lower_bound(t*-1));
	}
	if(!c)printf("%d\n",p);
	return 0;
}
