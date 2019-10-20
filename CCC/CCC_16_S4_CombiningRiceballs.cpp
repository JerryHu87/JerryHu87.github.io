#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

bool dp[401][401],sol[401][401];
int n,ans;
int arr[401],psa[401];

bool f(int l,int r){
	if(l>=r){
		return dp[l][r] = 1;
	}
	else if(sol[l][r]){
		if(dp[l][r]){ans = max(ans,psa[r]-psa[l-1]);}
		return dp[l][r];
	}
	sol[l][r] = 1;
	int p1 = l,p2 = r;
	while(p1<=p2){
		while(psa[r]-psa[p2-1] < psa[p1]-psa[l-1]){
			p2--;
		}
		if(psa[r]-psa[p2-1] == psa[p1]-psa[l-1] && f(p1+1,p2-1) && f(l,p1) && f(p2,r)){
			ans = max(ans,psa[r]-psa[l-1]);
			return dp[l][r] = 1;
		}
		p1++;
	}
	return 0;
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
		ans = max(ans,arr[i]);
		psa[i] = psa[i-1]+arr[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			dp[i][j] = f(i,j);
		}
	}	cout << ans << "\n";
	return 0;
}
