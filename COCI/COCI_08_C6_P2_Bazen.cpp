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

long double x,y,area = 250*125;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cout << setprecision(2);cout << fixed;
	cin >> x >> y;
	if(x == 0 && y == 0){
		cout << 125.00 << " " << 125.00 << "\n";
	}
	else if(x == 0 && y == 250){
		cout << 125.00 << " " << 0.00 << "\n";
	}
	else if(x == 250 && y == 0){
		cout << 0.00 << " " << 125.00 << "\n";
	}
	else if(x == 0){
		if(y>=125){
			cout << (double)(area/y) << " " << 0.00 << "\n";
		}
		else{
			cout << (double)(area/(250-y)) << " " << (double)(250-area/(250-y)) << "\n";
		}
	}
	else if(y == 0){
		if(x>=125){
			cout << 0.00 << " " << (double)(area/x) << "\n";
		}
		else{
			cout << (double)(250-area/(250-x)) << " " << (double)(area/(250-x)) << "\n";
		}
	}
	else{
		if(y>125){
			cout << (double)(250-area/y) << " " << 0.00 << "\n";
		}
		else{
			cout << 0.00 << " " << (double)(250-area/x) << "\n";
		}
	}
	return 0;
}
