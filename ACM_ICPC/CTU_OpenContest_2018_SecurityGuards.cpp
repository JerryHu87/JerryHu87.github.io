#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

int psa[5002][5002];
int n,q;

void init(){
	for(int i = 1;i<=5001;i++){
		for(int j = 1;j<=5001;j++){
			psa[i][j] += psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
		}
	}
}
bool check(int x,int y,int v){
	int sx = max(0,x-v-1);
	int sy = max(0,y-v-1);
	int bx = min(5001,x+v);
	int by = min(5001,y+v);
	//debug(sx,sy,bx,by);
	return psa[bx][by]-psa[sx][by]-psa[bx][sy]+psa[sx][sy] > 0;
}
int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	scan(n);scan(q);
	for(int i = 0,a,b;i<n;i++){
		cin >> a >> b;
		a++;b++;
		psa[a][b]++;
	}
	init();
	for(int i = 0,a,b;i<q;i++){
		scan(a);scan(b);
		a++;b++;
		int lo = 0,hi = 5001;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			//debug(a,b,lo,mid,hi);
			if(check(a,b,mid) > 0){hi = mid-1;}
			else{lo = mid+1;}
		}
		cout << hi+1 << "\n";
	}
	return 0;
}
