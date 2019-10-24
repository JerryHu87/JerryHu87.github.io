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
const ll INF = 0x3f3f3f3f*sqrt(MOD);
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

ll grid[3][3],r,c;

void solve(){
	for(ll z = 0;z<9;z++){
		for(ll i= 0;i<3;i++){
			for(ll j = 0;j<3;j++){
				if(grid[i][j] == INF){continue;}
				if(i+1<=2 && i-1>=0 && grid[i-1][j] != INF){
					grid[i+1][j] = grid[i][j]+grid[i][j]-grid[i-1][j];
				}
				if(i+1<=2 && i-1>=0 && grid[i+1][j] != INF){
					grid[i-1][j] = grid[i][j]-grid[i+1][j]+grid[i][j];
				}
				if(j+1<=2 && j-1>=0 && grid[i][j-1] != INF){
					grid[i][j+1] = grid[i][j]+grid[i][j]-grid[i][j-1];
				}
				if(j+1<=2 && j-1>=0 && grid[i][j+1] != INF){
					grid[i][j-1] = grid[i][j]-grid[i][j+1]+grid[i][j];
				}
				if(i+2<=2 && grid[i+2][j] != INF){
					grid[i+1][j] = grid[i][j]+(grid[i+2][j]-grid[i][j])/2;
				}
				if(j+2<=2 && grid[i][j+2] != INF){
					grid[i][j+1] = grid[i][j]+(grid[i][j+2]-grid[i][j])/2;
				}
				if(i-2>=0 && grid[i-2][j] != INF){
					grid[i-1][j] = grid[i][j]-(grid[i][j]-grid[i-2][j])/2;
				}
				if(j-2>=0 && grid[i][j-2] != INF){
					grid[i][j-1] = grid[i][j]-(grid[i][j]-grid[i][j-2])/2;
				}
			}
		}
	}
}
void print(){
	for(ll i = 0;i<3;i++){
		for(ll j = 0;j<3;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}
bool fill(){
	for(ll i = 0;i<3;i++){
		for(ll j = 0;j<3;j++){
			if(grid[i][j] == INF){return 0;}
		}
	}
	return 1;
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	for(ll i = 0;i<3;i++){
		for(ll j = 0;j<3;j++){
			string c;
			cin >> c;
			if(c == "X"){
				grid[i][j] = INF;
			}
			else{
				grid[i][j] = stoll(c);
			}
		}
	}
	solve();
	if(grid[1][1] == INF){
		grid[1][1] = 0;
	}
	solve();
	if(grid[0][1] == INF){
		grid[0][1] = grid[2][1]%2;
	}
	solve();
	if(grid[1][0] == INF){
		grid[1][0] = grid[1][2]%2;
	}
	solve();
	if(grid[2][1] == INF){
		grid[2][1] = grid[0][1]%2;
	}
	solve();
	if(grid[1][2] == INF){
		grid[1][2] = grid[1][0]%2;
	}
	solve();
	if(grid[0][0] == INF){
		grid[0][0] = (grid[0][2]+grid[2][0]+grid[2][2])%4;
	}
	solve();
	if(grid[0][2] == INF){
		grid[0][0] = (grid[0][0]+grid[2][0]+grid[2][2])%4;
	}
	solve();
	if(grid[2][0] == INF){
		grid[0][0] = (grid[0][0]+grid[0][2]+grid[2][2])%4;
	}
	solve();
	if(grid[2][2] == INF){
		grid[0][0] = (grid[0][0]+grid[2][0]+grid[0][2])%4;
	}
	solve();
	print();
	return 0;
}
