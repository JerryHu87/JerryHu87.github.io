#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n,p,c,q,a,b;vector<pair<int,int> > arr;

bool cmp(const pair<int,int> a,const pair<int,int> b){
	return a.second < b.second;
}
int main(){
	scanf("%d%d",&n,&p);q = 1;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(i == p){c = a;}
		else if(a >= b){arr.push_back({a,b});}
	}
	sort(arr.begin(),arr.end(),cmp);
	for(int i = 0;i<arr.size();i++){
		if(c >= arr[i].second){
			q++;c+=(arr[i].first-arr[i].second);
		}
	}
	printf("%d\n%d\n",c,q);
	return 0;
}
