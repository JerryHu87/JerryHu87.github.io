#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n;
ll ans;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	if(n == 1){
		cout << "0\n";
		return 0;
	}
	while(n > 1){
		int a = 0;
		for(int i = 2;i<=ceil(sqrt(n));i++){
			if(n%i == 0){
				a = max(a,max(i,n/i));
			}
		}
		if(a == 0){
			n--;
			ans += n;
		}
		else{
			n -= a;
			ans += (n/a);
		}
	}
	cout << ans+1 << "\n";
	return 0;
}
/*
15
ans: 9
2013
ans: 91
 */
