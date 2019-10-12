#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

pair<long long,long long> arr[400001];long long n;int k;long long p[800001];long long dp[800001];int cnt;map<long long,int> m;vector<long long> nodes[400001];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);cnt = 1;
	cin >> n >> k;
	for(int i = 0;i<k;i++){
		cin >> arr[i].first >> arr[i].second;p[cnt++] = arr[i].first;p[cnt++] = arr[i].second;
	}
	sort(p,p+cnt+1);
	for(int i = 1;i<cnt;i++){m[p[i]] = i;}
	for(int i = 0;i<k;i++){nodes[m[arr[i].second]].push_back(arr[i].first);}
	for(int i = 1;i<=cnt;i++){
		dp[i] = max(dp[i-1],dp[i]);int temp = m[p[i]];
		for(int j = 0;j<nodes[temp].size();j++){
			dp[i] = max(dp[i],dp[m[nodes[temp][j]]]+abs(p[i]-nodes[temp][j])+1);
		}
	}
	cout << n-dp[cnt] << "\n";
	return 0;
}
