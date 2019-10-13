#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


bool grid[30][8];
bool temp[30][8];
unordered_set<long long> us;

int main(){
	int r,c;
	long long ans;
	scanf("%d%d", &r, &c);
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			scanf("%d", &grid[i][j]);
		}
	}
	ans = 0;
	for(int i = 0;i<c;i++){
		ans += (grid[r-1][i]*pow(10,i));
	}
	us.insert(ans);
	for(int z = r-1;z>0;z--){
		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				temp[i][j] = grid[i][j];
			}
		}
		for(int i = z;i<r;i++){
			for(int j = 0;j<c;j++){
				if(temp[i][j] ^ temp[i-1][j]){
					temp[i][j] = 1;
				}
				else{
					temp[i][j] = 0;
				}
			}
		}
		ans = 0;
		for(int i = 0;i<c;i++){
			ans += (temp[r-1][i]*pow(10,i));
		}
		us.insert(ans);
	}
	cout << us.size() << "\n";
	return 0;
}
