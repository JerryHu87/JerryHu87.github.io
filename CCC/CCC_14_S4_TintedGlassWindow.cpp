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
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

struct event{
	ll x,lo,hi,v;
};
bool cmp(const event a,const event b){
	return a.x < b.x;
}

ll n,t,ans;
vector<event> ev;
map<ll,ll> y;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> t;
	for(ll i = 0,a,b,c,d,e;i<n;i++){
		cin >> a >> b >> c >> d >> e;
		ev.push_back({a,b,d,e});
		ev.push_back({c,b,d,-e});
		if(!y.count(b)){y[b] = 0;}
		if(!y.count(d)){y[d] = 0;}
	}
	sort(ev.begin(),ev.end(),cmp);
	auto temp = y.upper_bound(ev[0].hi);temp--;
	for(auto it = y.lower_bound(ev[0].lo);it != temp;it++){
		it->second += ev[0].v;
	}
	for(ll i = 1;i<(ll)ev.size();i++){
		auto it = y.begin();
		auto it2 = y.begin();
		it2++;
		for(;it2 != y.end();){
			if(it->second >= t){ans += (ev[i].x-ev[i-1].x)*(it2->first-it->first);}
			it++;it2++;
		}
		auto ed = y.upper_bound(ev[i].hi);ed--;
		for(it = y.lower_bound(ev[i].lo);it != ed;it++){
			it->second += ev[i].v;
		}
	}
	cout << ans << "\n";
}
/*
5
ans: 2
10
ans: 2
15
ans: 4

 */
