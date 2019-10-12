#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cin.sync_with_stdio(0);cin.tie(0);
//cout << fixed;cout << setprecision();

int t,n,i,temp;pair<int,int> arr[100001];double s;int bit[100001];

void update(int x){
	for(;x<=t;x+=x&-x){
		bit[x]++;
	}
}
int sum(int x){
	temp = 0;
	for(;x>0;x-=x&-x){
		temp+=bit[x];
	}
	return temp;
}
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int main(){
	scanf("%d",&t);arr[0].first = INF;
	for(i = 1;i<=t;i++){
		scanf("%d",&arr[i].first);arr[i].second = i;
	}
	sort(arr,arr+t+1);
	for(i = t-1;i>=0;i--){
		temp = i;
		while(i-1>=0 && arr[i].first == arr[i-1].first){i--;}
		sort(arr+i,arr+temp,cmp);
	}
	for(int i = t-1;i>=0;i--){
		s += sum(arr[i].second);update(arr[i].second);
	}
	printf("%.2f",(s/t)+1);
	return 0;
}
