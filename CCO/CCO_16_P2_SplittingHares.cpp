#include<bits/stdc++.h>
using namespace std;

#define ll long long int
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

struct point{
	int x,y,v;
};
int n;
ll ans = LLONG_MIN;
point arr[4001];
pdd temp[20001],ev[20001];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n;
	for(int i = 0,a,b,c;i<n;i++){
		cin >> a >> b >> c;
		arr[i] = {a,b,c};
	}
	for(int i = 0;i<n;i++){
		int idx = 0;
		for(int j = 0;j<n;j++){
			if(i == j){continue;}
			ld ang = atan2(arr[j].y-arr[i].y,arr[j].x-arr[i].x);
			temp[idx++] = {ang,(ld)arr[j].v};
			if(ang <= 0){temp[idx++] = {ang+2*PI,(ld)arr[j].v};}
			temp[idx++] = {ang+PI+1E-05,(ld)-arr[j].v};
		}
		sort(temp,temp+idx);
		int evs = 0;
		ll cur = arr[i].v;
		for(int j = 0;j<idx;j++){
			if(temp[j].first <= 0){
				cur += temp[j].second;
				continue;
			}
			if(evs == 0|| abs(ev[evs-1].first-temp[j].first) >= 1E-06){
				ev[evs++] = temp[j];
			}
			else{
				ev[evs-1].second += temp[j].second;
			}
		}
		for(int j = 0;j<evs;j++){
			/*
			e.a = e.a/PI*180;
			debug(arr[i].x,arr[i].y,e.a,cur,e.v);
			e.a = e.a*180/PI;
			*/
			ans = max(cur,ans);
			cur += ev[j].second;
		}
		ans = max(cur,ans);
	}
	cout << ans << "\n";
	return 0;
}
/*
6
1 8 4
1 4 6
7 7 2
4 10 -3
4 6 -9
4 2 8
ans: 18
 */
