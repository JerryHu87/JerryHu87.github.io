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

int n,k,ans;int vis[250][250][250];

void Find(int s,int p,int mi){
	if(vis[s][p][mi] == 0){
		if(p == s){
			vis[s][p][mi] = 1;
		}
		else if(p == 1){
			vis[s][p][mi] = 1;
		}
		else{
			int x = 0;
			for(int i = mi;i<=s/p;i++){
				Find(s-i,p-1,i);x += vis[s-i][p-1][i];
			}
			vis[s][p][mi] = x;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	Find(n,k,1);
	printf("%d\n",vis[n][k][1]);
	return 0;
}
