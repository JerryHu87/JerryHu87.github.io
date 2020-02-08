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
#define MAXN (1<<23)+1

ll n,k,a;
deque<pll> dq;
deque<ll> crawl;
ll p[MAXN];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> k >> a;
	dq.push_back({1,a});
	for(ll i = 2;i<=k;i++){
		cin >> a;
		if(a == 0){
			ll temp = dq.front().second;
			p[i] = dq.front().first;
			dq.clear();
			dq.push_back({i,temp});
			continue;
		}
		p[i] = 0;
		while(!dq.empty() && dq.back().second >= a){dq.pop_back();}
		dq.push_back({i,a});
	}
	for(ll i = k+1;i<=n;i++){
		cin >> a;
		while(!dq.empty() && dq.front().first+k<i){dq.pop_front();}
		if(a == 0){
			ll temp = dq.front().second;
			p[i] = dq.front().first;
			dq.clear();
			dq.push_back({i,temp});
			continue;
		}
		while(!dq.empty() && dq.front().second+a<=dq.back().second){dq.pop_back();}
		p[i] = dq.front().first;
		dq.push_back({i,dq.front().second+a});
	}
	ll mi = LLONG_MAX;
	vector<ll> pot;
	while(!dq.empty()){
		if(dq.front().second < mi && dq.front().first+k>n){
			mi = dq.front().second;
			pot.clear();
			pot.push_back(dq.front().first);
		}
		else if(dq.front().second == mi && dq.front().first+k > n){
			pot.push_back(dq.front().first);
		}
		dq.pop_front();
	}
	cout << mi << "\n";
	ll ma = -1,ans = 0;
	for(ll i:pot){
		ll idx = i;
		while(idx != 0){
			crawl.push_back(idx);
			idx = p[idx];
		}
		if((int)crawl.size() > ma){
			ans = i;
			ma = crawl.size();
		}
		crawl.clear();
	}
	while(ans != 0){
		crawl.push_back(ans);
		ans = p[ans];
	}
	while(!crawl.empty()){
		cout << crawl.back() << " ";
		crawl.pop_back();
	}
	cout << "\n";
	return 0;
}
/*
16 4
4 5 3 12 2 6 3 6 5 5 16 1 10 9 13 12
ans:
20
3 5 9 12 14

16 2
4 13 6 6 4 1 7 1 0 15 3 0 8 11 5 8
ans:
32
1 3 5 6 8 9 11 12 13 15

10 10
0 0 0 0 0 0 0 0 0 0
ans:
0
1 2 3 4 5 6 7 8 9 10
 */
