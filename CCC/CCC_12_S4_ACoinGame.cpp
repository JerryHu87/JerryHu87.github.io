#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pdd pair<long double, long double>
#define pb push_back
void scan(int &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for(;(c>47&&c<58);c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F &f, R&... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long double PI = 3.14159265359;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

ll n;
ll state[8];
map<ll,ll> m;

bool check(ll msk){
	for(ll i = 0;i<n;i++){
		state[i] = 100;
	}
	for(ll i = 0;i<64;i++){
		if((msk&(((ll)1)<<i)) > 0){
			state[i%n] = min(state[i%n],i/n+1);
		}
	}
	bool c = 1;
	if(state[0] == 100){c = 0;}
	for(ll i = 1;i<n;i++){
		if(state[i] < state[i-1] || state[i] == 100){
			c = 0;
		}
	}
	return c;
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	while(n != 0){
		queue<ll> q;
		m.clear();
		ll msk = 0;
		for(ll i = 0,a;i<n;i++){
			cin >> a;
			msk |= (((ll)1)<<((a-1)*n+i));
		}
		q.push(msk);
		m[msk] = 0;
		while(!q.empty()){
			msk = q.front();q.pop();
			//debug(msk);
			if(check(msk)){break;}
			for(ll i = 0;i<n;i++){
				ll tmp = msk;
				if(i-1 >= 0 && state[i] < state[i-1]){
					tmp &= (~(((ll)1)<<((state[i]-1)*n+i)));
					tmp |= (((ll)1)<<((state[i]-1)*n+i-1));
				}
				if(!m.count(tmp)){
					q.push(tmp);
					m[tmp] = m[msk]+1;
				}
				tmp = msk;
				if(i+1 < n && state[i] < state[i+1]){
					tmp &= (~(((ll)1)<<((state[i]-1)*n+i)));
					tmp |= (((ll)1)<<((state[i]-1)*n+i+1));
				}
				if(!m.count(tmp)){
					q.push(tmp);
					m[tmp] = m[msk]+1;
				}
			}
		}
		check(msk) ? cout << m[msk] << "\n":cout << "IMPOSSIBLE\n";
		cin >> n;
	}
	return 0;
}
