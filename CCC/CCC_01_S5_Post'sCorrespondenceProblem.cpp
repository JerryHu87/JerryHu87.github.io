#include<bits/stdc++.h>
using namespace std;


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

string a[41];string b[41];string tempa,tempb;vector<short> ans;
int n, m;queue<vector<short> > q;bool c;int cur = INF;

void Find(vector<int> current){
	tempa = "";tempb = "";
	for(int i =0;i<current.size();i++){
		tempa += a[current[i]];tempb += b[current[i]];
	}
	if(tempa == tempb){
		c = 1;
		if(current.size() < cur){
			ans.clear();ans.insert(ans.begin(),current.begin(),current.end());cur = current.size();
		}
		return;
	}
	if(current.size()+1<m){
		for(int i = 1;i<=n;i++){
			current.push_back(i);
			Find(current);
			current.erase(current.end()-1);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> m >> n;
	for(short i = 1;i<=n;i++){cin >> a[i];}
	for(short i = 1;i<=n;i++){cin >> b[i];}
	for(short i = 1;i<=n;i++){
		Find({i});
		if(c)break;
	}
	if(c){
		printf("%d\n",ans.size());
		for(int i = 0;i<ans.size();i++){printf("%d\n",ans[i]);}
	}
	else{
		printf("No solution.\n");
	}
	return 0;
}
