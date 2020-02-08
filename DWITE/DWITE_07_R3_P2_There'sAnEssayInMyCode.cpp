#include<bits/stdc++.h>
using namespace std;

#define ll long long int
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

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	for(int z = 0;z<5;z++){
		string a,ans = "";
		getline(cin,a);
		bool c = 0;
		for(int i = 0;i<(int)a.length();i++){
			if(a[i] == '"'){
				if(i != (int)a.length()-1){
					for(int j = i+1;j<(int)a.length();j++){
						if(a[j] == '"'){
							ans += a.substr(i+1,j-i-1) + " ";
							c = 1;
							i = j+1;
							break;
						}
					}
				}
			}
			else if(a.substr(i,1) == "'"){
				if(i != (int)a.length()-1){
					for(int j = i+1;j<(int)a.length();j++){
						if(a.substr(j,1) == "'"){
							ans += a.substr(i+1,j-i-1) + " ";
							c = 1;
							i = j+1;
							break;
						}
					}
				}
			}
			else if(a[i] == '/'){
				if(i != (int)a.length()-1){
					if(a[i+1] == '/'){
						ans += a.substr(i+2);
						c = 0;
						break;
					}
					else if(a[i+1] == '*'){
						for(int j = i+2;j<(int)a.length();j++){
							if(j+1 <(int)a.length() && a[j] == '*' && a[j+1] == '/'){
								ans += a.substr(i+2,j-i-2) + " ";
								c = 1;
								i = j+2;
								break;
							}
						}
					}
				}
			}
		}
		if(c){ans = ans.substr(0,ans.length()-1);}
		cout << ans << "\n";
	}
	return 0;
}
