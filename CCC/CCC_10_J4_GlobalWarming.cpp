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

int arr[20];int diff[20];int n;bool c = 0;int idx = 0;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	while(n != 0){
		for(int i = 0;i<n;i++){
			cin >> arr[i];
		}
		for(int i = 0;i<n-1;i++){
			diff[i] = arr[i+1]-arr[i];
		}
		for(int i = 1;i<=n;i++){
			c = 0;
			for(int j = i;j<n-1;j++){
				if(j%i == 0){idx = 0;}
				if(diff[j] != diff[idx]){c= 1;break;}
				idx++;
			}
			if(i == n){
				cout << n-1 << "\n";break;
			}
			else if(!c){
				cout << i << "\n";break;
			}
		}
		cin >> n;
	}
	return 0;
}
