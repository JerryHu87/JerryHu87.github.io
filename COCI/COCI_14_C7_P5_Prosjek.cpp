#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[300001];long long psa[300001];int ans,n,k;

bool check(int x){
	long long mi = 1e18+1;
	for(int i = 1;i<=n;i++){
		psa[i] = psa[i-1]+arr[i]-x;
		if(i>=k)mi = min(mi,psa[i-k]);
		if(psa[i]>=mi)return 1;
	}
	return 0;
}
int main(){
	int l = 1;int h = INF;
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++){scanf("%d",&arr[i]);arr[i] *= 1000;}
	while(l <= h){
		int m = l + (h-l)/2;
		if(check(m)){
			ans = m;l = m+1;
		}
		else{
			h = m-1;
		}
	}
	printf("%.3f\n",ans/1000.0);
	return 0;
}
