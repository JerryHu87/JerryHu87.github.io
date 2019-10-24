#include<bits/stdc++.h>
using namespace std;


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cin.sync_with_stdio(0);cin.tie(0);

int n,a,b;

void find(int cnt,string pat){
	if(pat.length() == a){
		if(cnt == b)cout << pat << "\n";
	}
	else{
		if(cnt < b){
			find(cnt+1,pat+"1");
		}
		find(cnt,pat+"0");
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d%d",&a,&b);
		printf("The bit patterns are\n");
		find(0,"");
		printf("\n");
	}
	return 0;
}
