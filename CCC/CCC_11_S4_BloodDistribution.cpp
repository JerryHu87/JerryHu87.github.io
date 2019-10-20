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

int arr[2][8];
ll ans;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	for(int i = 0;i<2;i++){
		for(int j = 0;j<8;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i<8;i++){
		if(arr[0][i] > arr[1][i]){
			ans += arr[1][i];
			arr[0][i] -= arr[1][i];
			arr[1][i] = 0;
		}
		else{
			ans += arr[0][i];
			arr[1][i] -= arr[0][i];
			arr[0][i] = 0;
		}
	}
	for(int i = 0;i<8;i++){
		if(arr[1][i] == 0){continue;}
		if(i%2 == 0){
			for(int j = i-2;j>=0;j-=2){
				if(arr[0][j] == 0 || ((i == 4 || i == 5) && (j == 3 || j == 4))){continue;}
				if(arr[0][j] > arr[1][i]){
					ans += arr[1][i];
					arr[0][j] -= arr[1][i];
					arr[1][i] = 0;
				}
				else{
					ans += arr[0][j];
					arr[1][i] -= arr[0][j];
					arr[0][j] = 0;
				}
			}
		}
		else{
			for(int j = i-2;j>=0;j-=2){
				if(arr[0][j] == 0 || ((i == 4 || i == 5) && (j == 3 || j == 4))){continue;}
				if(arr[0][j] > arr[1][i]){
					ans += arr[1][i];
					arr[0][j] -= arr[1][i];
					arr[1][i] = 0;
				}
				else{
					ans += arr[0][j];
					arr[1][i] -= arr[0][j];
					arr[0][j] = 0;
				}
			}
			for(int j = i-1;j>=0;j-=2){
				if(arr[0][j] == 0 || ((i == 4 || i == 5) && (j == 3 || j == 4))){continue;}
				if(arr[0][j] > arr[1][i]){
					ans += arr[1][i];
					arr[0][j] -= arr[1][i];
					arr[1][i] = 0;
				}
				else{
					ans += arr[0][j];
					arr[1][i] -= arr[0][j];
					arr[0][j] = 0;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
