#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector<string> arr[26];int cnt[26];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	int k,n;
	cin >> k >> n;
	for(int i = 0;i<k;i++){
		string a;
		cin >> a;
		arr[a[0]-'a'].push_back(a);
	}
	for(int i = 0;i<26;i++){
		sort(arr[i].begin(),arr[i].end());
	}
	for(int i = 0;i<n;i++){
		char c;
		cin >> c;
		cout << arr[c-'a'][cnt[c-'a']++] << "\n";
		if(cnt[c-'a'] == arr[c-'a'].size()){cnt[c-'a'] = 0;}
	}
	return 0;
}
