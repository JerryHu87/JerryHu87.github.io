#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}


int n,ans;
int dp[2001];
pii arr[2001];
vector<pair<int,pii> > v;
queue<pii> q;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i = 1;i<=n;i++){
		v.push_back({arr[i].first*arr[i].first+arr[i].second*arr[i].second,{0,i}});
		for(int j = i+1;j<=n;j++){
			v.push_back({(arr[i].first-arr[j].first)*(arr[i].first-arr[j].first)+(arr[i].second-arr[j].second)*(arr[i].second-arr[j].second),{i,j}});
		}
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<(int)v.size();i++){
		if(i != 0 && v[i].first != v[i-1].first){
			while(!q.empty()){
				pii cur = q.front();q.pop();
				dp[cur.second] = max(dp[cur.second],cur.first);
			}
		}
		if(v[i].second.first == 0){
			ans = max(ans,dp[v[i].second.second]+1);
			continue;
		}
		q.push({dp[v[i].second.first]+1,v[i].second.second});
		q.push({dp[v[i].second.second]+1,v[i].second.first});
	}
	cout << ans << "\n";
	return 0;
}
/*
5
5 8
4 10
3 1
3 2
3 3
ans: 6
 */
