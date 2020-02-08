#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pll pair<long,long>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

string fib[201];

string add(string a,string b){
	string temp = "";
	bool carry = 0;
	int idx = b.length()-1;
	for(int i = a.length()-1;i>=0;i--){
		int cur = a[i]-'0'+b[idx--]-'0';
		if(carry){
			cur++;
			carry = 0;
		}
		if(cur>=10){
			carry = 1;
			cur -= 10;
		}
		temp = to_string(cur) + temp;
	}
	if(carry){
		int cur = 1;
		if(idx>=0){
			cur += b[idx--]-'0';
		}
		temp = to_string(cur)+temp;
	}
	if(idx>=0){
		temp = b.substr(0,idx+1)+temp;
	}
	return temp;
}
void init(){
	fib[1] = "1";
	fib[2] = "1";
	for(int i = 3;i<=200;i++){
		fib[i] = add(fib[i-2],fib[i-1]);
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	init();
	int n;
	cin >> n;
	while(n != 0){
		cout << fib[n] << "\n";
		cin >> n;
	}
	return 0;
}
