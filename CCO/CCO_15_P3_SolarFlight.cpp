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

struct plane{
	ll tree[8001],arr[2001];
	void build(int cur,int lo,int hi){
		if(lo == hi){tree[cur] = arr[lo];return;}
		int mid = (lo+hi)/2;
		build(cur*2,lo,mid);build(cur*2+1,mid+1,hi);
		tree[cur] = max(tree[cur*2],tree[cur*2+1]);
	}
	ll query(int cur,int l,int r,int lo,int hi){
		if(l <= lo && hi <= r){return tree[cur];}
		else if(hi < l || lo > r){return -INF;}
		int mid = (lo+hi)/2;
		return max(query(cur*2,l,r,lo,mid),query(cur*2+1,l,r,mid+1,hi));
	}
};

int n,k,x,q;
plane p[2001];
pair<ld,ll> eq[2001];
ll val[2001];
pair<ld,int> inter[2001][2001];
int st[2001],ed[2001];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> x >> k >> n >> q;
	for(int i = 1,a,b,c;i<=n;i++){
		cin >> a >> b >> c;
		eq[i].first = (ld)(b-a)/(ld)x;
		eq[i].second = a;
		val[i] = c;
	}
	for(int i = 1;i<=n;i++){
		ll ini = 0;
		for(int j = 1;j<=n;j++){
			if(eq[j].second > eq[i].second){ini += val[j];}
		}
		for(int j = 1;j<=n;j++){
			if(i == j){
				inter[i][j] = {0,ini};
				continue;
			}
			inter[i][j] = {(ld)(eq[j].second-eq[i].second)/(eq[i].first-eq[j].first),j};
		}
		sort(inter[i]+1,inter[i]+n+1);
		st[i] = 1;ed[i] = n;
		while(inter[i][st[i]].first < 0){st[i]++;}
		while(inter[i][ed[i]].first > x){ed[i]--;}
		p[i].arr[st[i]] = ini;
		for(int j = st[i]+1;j<=ed[i];){
			int idx = j;
			eq[inter[i][j].second].second > eq[i].second ? ini -= val[inter[i][j].second]:ini += val[inter[i][j].second];
			while(abs(inter[i][idx].first-inter[i][idx+1].first) < 1E-06){
				eq[inter[i][idx+1].second].second > eq[i].second ? ini -= val[inter[i][idx+1].second]:ini += val[inter[i][idx+1].second];
				idx++;
			}
			for(int z = j;z<=idx;z++){
				p[i].arr[z] = ini;
				j++;
			}
		}
		p[i].build(1,st[i],ed[i]);
	}
	for(int i = 0,a,b;i<q;i++){
		cin >> a >> b;
		int lo = st[a],hi = ed[a],l = 0,r = 0;
		while(lo <= hi){
			int mid = (lo+hi)/2;
			if(inter[a][mid].first <= b){
				lo = mid+1;
				l = max(l,mid);
			}
			else{
				hi = mid-1;
			}
		}
		lo = st[a];hi = ed[a];
		while(lo <= hi){
			int mid = (lo+hi)/2;
			if(inter[a][mid].first < b+k){
				lo = mid+1;
				r = max(r,mid);
			}
			else{
				hi = mid-1;
			}
		}
		cout << p[a].query(1,l,r,st[a],ed[a]) << "\n";
	}
	return 0;
}
