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

map<string,set<int> > um;
string arr[20001];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	int n,ans = 0;
	cin >> n;
	for(int z = 0;z<n;z++){
		cin >> arr[z];
		for(int i = 0;i<(int)arr[z].length();i++){
			for(int s = 1;s<=(int)arr[z].length()-i;s++){
				um[arr[z].substr(i,s)].insert(z);
			}
		}
	}
	for(int z = 0;z<n;z++){ans += um[arr[z]].size();}
	cout << ans-n << "\n";
	return 0;
}
