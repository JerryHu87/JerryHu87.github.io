#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

long long arr[100001],sum,C[100001],dp[100001][51],ans,bans;int n,k;

void gen(){
	n = rand()%35+1;
	k = rand()%n+1;
	cout << n << " " << k << endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<32;j++){
			bool temp = rand()%2;
			if(temp){
				arr[i]=(arr[i]%MOD+fpow(2,j,MOD)%MOD)%MOD;
			}
		}
		cout << arr[i] << " ";
	}
	cout << endl;
}
void brute(vector<int> cur,int pos){
	if(cur.size() == k){
		int temp = 0;
		for(int i = 0;i<cur.size();i++){
			temp = max(temp,cur[i]);
		}
		bans = (bans%MOD+temp%MOD)%MOD;
	}
	else if(pos != n){
		cur.push_back(arr[pos]);
		brute(cur,pos+1);
		cur.pop_back();
		brute(cur,pos+1);
	}
}
void init(){
	for(int i = 0;i<k-1;i++){
		C[i] = 0;
	}
	C[k-1] = 1;
	for(int i = k;i<n;i++){
		C[i] = ((((C[i-1]%MOD)*(i%MOD))%MOD)/((i-k+1)%MOD))%MOD;
	}
}

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	//srand(time(0));gen();
	cin >> n >> k;
	init();
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	dp[0][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<k;j++){
			dp[i][j] = dp[i-1][j];
			if(j>0){dp[i][j] = (dp[i][j]%MOD+dp[i-1][j-1]%MOD)%MOD;}
		}
	}
	//brute({},0);
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		//cout << C[i] << endl;
		ans = (ans%MOD+((arr[i]%MOD)*(dp[i][k-1]%MOD))%MOD)%MOD;
	}
	//if(ans != bans){cout << "NOT EQUAL.\n";}
	//cout << "ANS: " << bans << " CUR: " << ans << "\n";
	cout << ans << "\n";
	return 0;
}
