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

int p[MAXN],r[MAXN];

int Find(int x){
	if(p[x] != x){return p[x] = Find(p[x]);}
	return x;
}
void Link(int x,int y){
	if(r[x] < r[y]){
		p[x] = y;
	}
	else{
		p[y] = x;
		if(r[x] == r[y]){r[x]++;}
	}
}
void Union(int x,int y){
	Link(Find(x),Find(y));
}

int n,m,k;
vector<pii> c0,c1,ness,ans0,ans1;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m >> k;
	for(int i = 0,a,b,c;i<m;i++){
		cin >> a >> b >> c;
		c ? c1.push_back({a,b}):c0.push_back({a,b});
	}
	for(int i = 1;i<=n;i++){
		p[i] = i;
	}
	int cnt = 0;
	for(int i = 0;i<(int)c1.size() && cnt < n-1;i++){
		if(Find(c1[i].first) != Find(c1[i].second)){
			Union(c1[i].first,c1[i].second);
			cnt++;
		}
	}
	for(int i = 0;i<(int)c0.size() && cnt < n-1;i++){
		if(Find(c0[i].first) != Find(c0[i].second)){
			Union(c0[i].first,c0[i].second);
			cnt++;
			ness.push_back(c0[i]);
		}
	}
	for(int i = 1;i<=n;i++){
		p[i] = i;
	}
	cnt = ness.size();
	for(int i = 0;i<(int)ness.size();i++){
		Union(ness[i].first,ness[i].second);
		ans0.push_back(ness[i]);
	}
	for(int i = 0;i<(int)c0.size() && cnt < k;i++){
		if(Find(c0[i].first) != Find(c0[i].second)){
			Union(c0[i].first,c0[i].second);
			ans0.push_back(c0[i]);
			cnt++;
		}
	}
	if(cnt < k){
		cout << "no solution\n";
		return 0;
	}
	for(int i = 0;i<(int)c1.size() && cnt < n-1;i++){
		if(Find(c1[i].first) != Find(c1[i].second)){
			Union(c1[i].first,c1[i].second);
			ans1.push_back(c1[i]);
			cnt++;
		}
	}
	if(cnt < n-1){
		cout << "no solution\n";
	}
	else{
		for(int i = 0;i<(int)ans0.size();i++){
			cout << ans0[i].first << " " << ans0[i].second << " " << 0 << "\n";
		}
		for(int i = 0;i<(int)ans1.size();i++){
			cout << ans1[i].first << " " << ans1[i].second << " " << 1 << "\n";
		}
	}
	return 0;
}
