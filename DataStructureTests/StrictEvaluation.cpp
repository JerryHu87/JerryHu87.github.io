#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pdd pair<long double, long double>
#define pb push_back
#define largestbit(x) 31-__builtin_clz(x);
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
#define MAXN 100001

ll tree[MAXN*4],arr[MAXN];
pll lazy[MAXN*4];
ll n,q;

void build(ll u,ll lo,ll hi){
	if(lo == hi){
		tree[u] = arr[lo];
	}
	else{
		ll mid = (lo+hi)/2;
		build(u*2,lo,mid);
		build(u*2+1,mid+1,hi);
		tree[u] = min(tree[u*2],tree[u*2+1]);
	}
}
void update1(ll u,ll l,ll r,ll lo,ll hi,ll v){
	if(lazy[u].first == 0 && lazy[u].second != 0){
		tree[u] += lazy[u].second;
		if(lo != hi){
			lazy[u*2].second += lazy[u].second;
			lazy[u*2+1].second += lazy[u].second;
		}
		lazy[u] = {0,0};
	}
	else if(lazy[u].first != 0){
		tree[u] = lazy[u].first+lazy[u].second;
		if(lo != hi){
			lazy[u*2] = lazy[u];
			lazy[u*2+1] = lazy[u];
		}
		lazy[u] = {0,0};
	}
	if(l <= lo && hi <= r){
		tree[u] += v;
		if(lo != hi){
			lazy[u*2].second += v;
			lazy[u*2+1].second += v;
		}
	}
	else if(!(hi < l || r < lo)){
		ll mid = (lo+hi)/2;
		update1(u*2,l,r,lo,mid,v);
		update1(u*2+1,l,r,mid+1,hi,v);
		tree[u] = min(tree[u*2],tree[u*2+1]);
	}
}
void update2(ll u,ll l,ll r,ll lo,ll hi,ll v){
	if(lazy[u].first == 0 && lazy[u].second != 0){
		tree[u] += lazy[u].second;
		if(lo != hi){
			lazy[u*2].second += lazy[u].second;
			lazy[u*2+1].second += lazy[u].second;
		}
		lazy[u] = {0,0};
	}
	else if(lazy[u].first != 0){
		tree[u] = lazy[u].first+lazy[u].second;
		if(lo != hi){
			lazy[u*2] = lazy[u];
			lazy[u*2+1] = lazy[u];
		}
		lazy[u] = {0,0};
	}
	if(l <= lo && hi <= r){
		tree[u] = v;
		if(lo != hi){
			lazy[u*2] = {v,0};
			lazy[u*2+1] = {v,0};
		}
	}
	else if(!(hi < l || r < lo)){
		ll mid = (lo+hi)/2;
		update2(u*2,l,r,lo,mid,v);
		update2(u*2+1,l,r,mid+1,hi,v);
		tree[u] = min(tree[u*2],tree[u*2+1]);
	}
}
ll query(ll u,ll l,ll r,ll lo,ll hi){
	if(lazy[u].first == 0 && lazy[u].second != 0){
		tree[u] += lazy[u].second;
		if(lo != hi){
			lazy[u*2].second += lazy[u].second;
			lazy[u*2+1].second += lazy[u].second;
		}
		lazy[u] = {0,0};
	}
	else if(lazy[u].first != 0){
		tree[u] = lazy[u].first+lazy[u].second;
		if(lo != hi){
			lazy[u*2] = lazy[u];
			lazy[u*2+1] = lazy[u];
		}
		lazy[u] = {0,0};
	}
	if(l <= lo && hi <= r){
		return tree[u];
	}
	else if(hi < l || r < lo){
		return LLONG_MAX;
	}
	ll mid = (lo+hi)/2;
	return min(query(u*2,l,r,lo,mid),query(u*2+1,l,r,mid+1,hi));
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> q;
	for(ll i = 1;i<=n;i++){
		cin >> arr[i];
	}
	build(1,1,n);
	for(ll i = 1,a,b,c,d;i<=q;i++){
		cin >> a;
		if(a == 1){
			cin >> b >> c >> d;
			update1(1,b,c,1,n,d);
		}
		else if(a == 2){
			cin >> b >> c >> d;
			update2(1,b,c,1,n,d);
		}
		else{
			cin >> b >> c;
			cout << query(1,b,c,1,n) << "\n";
		}
	}
	return 0;
}
/*
5 3
1 2 3 4 5
2 2 5 10
1 2 5 5
3 2 5
 */
