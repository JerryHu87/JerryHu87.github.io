#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<long,long>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int a,b,t,m[1000000];
vector<int> arr;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	scanf("%d",&a);
	for(int i = 1;i<=a;i++){
		scanf("%d",&t);
		m[t] = i;
	}
	scanf("%d",&b);
	for(int i = 1;i<=b;i++){
		scanf("%d",&t);
		if(m[t] == 0){
			continue;
		}
		if((int)arr.size() == 0 || arr[arr.size()-1] < m[t]){
			arr.push_back(m[t]);
			continue;
		}
		auto idx = upper_bound(arr.begin(),arr.end(),m[t]);
		arr[idx-arr.begin()] = m[t];
	}
	printf("%d\n",arr.size());
	return 0;
}
