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

int h,k;
int arr[2001];

bool check(int dis){
	int cnt = INF;
	for(int i = 0;i<h;i++){
		int idx = i,cnt2 = 0;
		for(int j = i;j<i+h;j++){
			if(arr[idx]+dis*2 < arr[j]){
				idx = j;
				cnt2++;
			}
		}
		cnt = min(cnt,cnt2);
	}
	return cnt < k;
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> h;
	for(int i = 0;i<h;i++){
		cin >> arr[i];
	}
	sort(arr,arr+h);
	cin >> k;
	for(int i =0;i<h;i++){
		arr[i+h] = arr[i]+1000000;
	}
	int lo = 0,hi = 1000000;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		if(check(mid)){hi = mid-1;}
		else{lo = mid+1;}
	}
	cout << hi+1 << "\n";
	return 0;
}
