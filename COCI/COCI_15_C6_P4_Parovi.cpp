#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
void scan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for(;(c>47&&c<58);c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000000;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

int n;
ll ans = 1;
int tot[21][21];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			for(int a = i;a<=j;a++){
				for(int b = a+1;b<=j;b++){
					if(gcd(a,b) == 1){tot[i][j]++;}
				}
			}
		}
	}
	for(int i = 0;i<(1<<(n-1));i++){
		int l = 1,cnt = 0;
		ll cur = 1;
		for(int j = 1;j<n;j++){
			if(((1<<(j-1))&i) > 0){
				cur = (cur*fpow(2,tot[l][j],MOD))%MOD;
				l = j+1;
				cnt++;
			}
		}
		cur = (cur*fpow(2,tot[l][n],MOD))%MOD;
		(cnt&1) > 0 ? ans = (ans-cur)%MOD:ans = (ans+cur)%MOD;
	}
	ans = (ans-1+MOD)%MOD;
	cout << abs(ans) << "\n";
	return 0;
}
/*
2
ans: 1
3
ans: 5
4
ans: 21
 */
