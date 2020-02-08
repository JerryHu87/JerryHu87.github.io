#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[1000000];int dp[1000001];int maxv[1000002];int n,nl,l,h,m,L = 0;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 0;i<n;i++){
		l = 1;h = L;
		while(l<=h){
			m = (l+h)/2;
			if(arr[maxv[m]] < arr[i]){
				l = m+1;
			}
			else{
				h = m-1;
			}
		}
		nl = l;
		dp[i] =  maxv[nl-1];
		maxv[nl] = i;
		L = max(L,nl);
	}
	printf("%d\n",L);
	return 0;
}
