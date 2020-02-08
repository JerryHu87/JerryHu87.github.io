#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


bool sieve[200];int n,g,mi;bool c;

void init(){
  sieve[0] = 1;sieve[1] = 1;
	for(int i = 2;i<200;i++){
    if(sieve[i]){continue;}
		for(int j = i*2;j<200;j+=i){
			sieve[j] = 1;
		}
	}
}
int main(){
	init();
	for(int z = 0;z<5;z++){
		scanf("%d",&n);g = 0;c = 0;
		while(sieve[n+g] || !c){
      if(!sieve[n+g] && g != 0){c = 1;}
      g++;
    }
		mi = g;g = 0;c = 0;
		while(sieve[n-g] || !c){
      if(!sieve[n-g] && g != 0){c = 1;}
      g++;
    }
		if(g<mi){mi = -g;}
		printf("%d\n",n+mi);
	}
	return 0;
}
