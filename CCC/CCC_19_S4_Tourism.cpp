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

int st[33][1000001],arr[1000001];
ll dp[1000001];
int n,lg,k,p;

void build(){
	for(int i = 1;i<=n;i++){st[0][i] = arr[i];}
	for(int i = 1;i<=lg;i++){
		for(int j = 1;j+(1<<(i-1))<=n;j++){
			st[i][j] = max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
}
ll query(int l,int r){
	int temp = largestbit(r-l+1);
	return max(st[temp][l],st[temp][r+1-(1<<temp)]);
}
void brute(){
	for(int i = 1;i<=n;i++){
		for(int j = i-1;j>=0 && j>=i-k;j--){
			if((j-1)/k != (i-1)/k || j == 0){
				dp[i] = max(dp[i],dp[j]+query(j+1,i));
			}
		}
	}
}
void gen(){
	n = rand()%30+1;
	k = rand()%n+1;
	cout << n << " " << k << "\n";
	for(int i = 1;i<=n;i++){
		arr[i] = rand()%1000;
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main(){
	//freopen("s4.sample.in","r",stdin);freopen("s4.sample.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//srand(time(0));gen();
	cin >> n >> k;
	for(int i = 1;i<=n;i++){cin >> arr[i];}
	lg = log2(n)+1;
	build();
	/*
	brute();
	cout << dp[n] << "\n";
	memset(dp,0,sizeof(dp));
	*/
	for(int i = 1;i<=n;i++){
		if(i-p == k+1){p++;}
		while(p<i-1 && dp[p]+query(p+1,i) <= dp[p+1]+query(p+2,i) && ((p == 0 && (i-1)/k == 1) || (p/k < (i-1)/k))){p++;}
		dp[i] = dp[p]+query(p+1,i);
	}
	cout << dp[n] << "\n";
}
