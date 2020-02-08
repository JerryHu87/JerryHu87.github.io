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
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

queue<int> l0,l1,l2,temp;
vector<int> ans;
int n;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 0,a;i<n;i++){
		cin >> a;
		if(a%3 == 0){
			l0.push(a);
		}
		else if(a%3 == 1){
			l1.push(a);
		}
		else{
			l2.push(a);
		}
	}
	if(!l1.empty() && !l2.empty()){
		while(!l1.empty()){
			temp.push(l1.front());
			l1.pop();
		}
		if(!l0.empty()){
			temp.push(l0.front());
			l0.pop();
		}
		while(!l2.empty()){
			temp.push(l2.front());
			l2.pop();
		}
	}
	else{
		if(l1.empty()){
			while(!l2.empty()){
				temp.push(l2.front());
				l2.pop();
			}
		}
		else{
			while(!l1.empty()){
				temp.push(l1.front());
				l1.pop();
			}
		}
	}
	while(!l0.empty() || !temp.empty()){
		if(!l0.empty()){
			ans.push_back(l0.front());
			l0.pop();
		}
		if(!temp.empty()){
			ans.push_back(temp.front());
			temp.pop();
		}
		if(!temp.empty() && temp.front()%3 == 0){
			ans.push_back(temp.front());
			temp.pop();
			if(!temp.empty()){
				ans.push_back(temp.front());
				temp.pop();
			}
		}
	}
	for(int i = 1;i<(int)ans.size();i++){
		if((ans[i-1]+ans[i])%3 == 0){
			cout << "impossible\n";
			return 0;
		}
	}
	for(int i = 0;i<(int)ans.size();i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
