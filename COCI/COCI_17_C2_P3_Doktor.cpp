#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,arr[500001],ma = -INF;long long psa[500001];vector<int> cen[1000001];pair<int,int> ans = {1,1};

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i = 1;i<=n;i++){
		cen[arr[i]+i].push_back(abs(arr[i]-i));
	}
	for(int i = 1;i<=n;i++){
		psa[i] = psa[i-1]+(arr[i] == i);
	}
	for(int i = 1;i<=n*2;i++){
		sort(cen[i].begin(),cen[i].end());
	}
	for(int i = 1;i<=n*2;i++){
		int cur = 0;
		for(int j = 0;j<cen[i].size();j++){
			cur++;
			int l = (i-cen[i][j])/2;int r = (i+cen[i][j])/2;
			if(ma < cur-(psa[r]-psa[l-1])){
				ma =cur-(psa[r]-psa[l-1]);
				ans.first = arr[l];ans.second = arr[r];
			}
		}
	}
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}
