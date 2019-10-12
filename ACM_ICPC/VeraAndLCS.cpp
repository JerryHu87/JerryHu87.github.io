#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

string a,b;int n,k,mi,mii;int freq[26];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> k >> a;
	for(int i = 0;i<a.length();i++){
		freq[a[i]-'a']++;
	}
	if(k>n){
		cout << "WRONGANSWER\n";
	}
	else{
		mi = INF;
		for(int i = 0;i<26;i++){
			if(freq[i] < mi){
				mi = freq[i];mii = i;
			}
		}
		if(mi > k){cout << "WRONGANSWER\n";return 0;}
		int t = freq[mii];
		for(int i = 0;i<k;i++){
			if(a[i] == mii+'a'){
				t--;
			}
			if(i<k-t){
				cout << a[i];
			}
			else{
				cout << (char)(mii+'a');
			}
		}
		for(int i = k;i<a.length();i++){
			cout << (char)(mii+'a');
		}
	}
	return 0;
}
