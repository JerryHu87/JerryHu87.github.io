#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
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
#define MAXN 100001

int n,m,ans = INF,lo = 0,hi = pow(10,9);
int arr1[MAXN],arr2[MAXN];

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> n >> m;
	for(int i = 0;i<n;i++){cin >> arr1[i];}
	for(int i = 0;i<m;i++){cin >> arr2[i];}
	sort(arr1,arr1+n);sort(arr2,arr2+m);
	if(n == m){
		ans = 0;
		for(int i = 0;i<n;i++){
			ans = max(ans,abs(arr1[i]-arr2[i]));
		}
	}
	else if(n > m){
		while(lo <= hi){
			int mid = (lo+hi)/2,p1 = 0,p2 = 0;
			while(p1 < n && p2 < m){
				if(abs(arr1[p1]-arr2[p2]) > mid){
					p1++;
				}
				else{
					p1++;
					p2++;
				}
			}
			if(p2 == m){
				hi = mid-1;
				ans = min(ans,mid);
			}
			else{
				lo = mid+1;
			}
		}
	}
	else{
		while(lo <= hi){
			int mid = (lo+hi)/2,p1 = 0,p2 = 0;
			while(p1 < n && p2 < m){
				if(abs(arr1[p1]-arr2[p2]) > mid){
					p2++;
				}
				else{
					p2++;
					p1++;
				}
			}
			if(p1 == n){
				hi = mid-1;
				ans = min(ans,mid);
			}
			else{
				lo = mid+1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
