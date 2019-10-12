#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cout << fixed;cout << setprecision();

int m,q,ma;int a[101];string p[101];pair<int,int> g[101];int dp[101];

void print(int x){
	if(g[x].first != 0){
		print(g[x].first);
	}
	for(int i = g[x].first+1;i<=g[x].second;i++){
		cout << p[i] << " ";
	}
	cout << "\n";
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> m >> q;
	for(int i = 1;i<=q;i++){
		 cin >> p[i];cin >> a[i];g[i].second = i;g[i].first = i;
	}
	memset(dp,INF,sizeof(dp));dp[0] = 0;
	for(int i = 1;i<=q;i++){
		ma = 0;
		for(int j = i;j>=i-m && j>=0;j--){
			if(ma+dp[j] < dp[i]){
				dp[i] = ma+dp[j];g[i].first = j;
			}
			if(a[j] > ma){
				ma = a[j];
			}
		}
	}
	cout << "Total Time: " << dp[q] << "\n";
	print(q);
	return 0;
}
