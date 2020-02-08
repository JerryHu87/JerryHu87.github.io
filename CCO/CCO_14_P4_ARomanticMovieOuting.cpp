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

int bit[3901][3901];
bool use[1801][1001];
vector<int> val;
int l,t;

void update(int x,int y,int v){
	for(;x<=3900;x+=x&-x){
		for(int z = y;z<=3900;z+=z&-z){
			bit[x][z]+=v;
		}
	}
}
int query(int x,int y){
	int sum = 0;
	for(;x>0;x-=x&-x){
		for(int z = y;z>0;z-=z&-z){
			sum += bit[x][z];
		}
	}
	return sum;
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> l >> t;
	for(int i = 0,a,b;i<t;i++){
		char c;
		cin >> c >> a >> b;
		if(a>1800){continue;}
		if(c == 'E'){
			use[a][b] = 1;
			update(1800+a-b,a+b+1,1);
		}
		else if(c == 'L'){
			use[a][b] = 0;
			update(1800+a-b,a+b+1,-1);
		}
		else{
			if(use[a][b] == 1 || use[a][b+1] == 1){
				cout << "No\n";
			}
			else{
				cout << query(1800+a-b,a+b+1)+query(1799+a-b,a+b+2) << "\n";
			}
		}
	}
	for(int i = l+1;i<=1800;i++){
		for(int j = 1;j<=1000;j++){
			if(!use[i][j]){val.push_back(query(1800+i-j,i+j+1));}
		}
	}
	sort(val.begin(),val.end());
	cout << val[0]+val[1] << "\n";
	return 0;
}
