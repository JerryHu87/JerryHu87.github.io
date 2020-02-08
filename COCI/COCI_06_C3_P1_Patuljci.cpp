#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[9],ans[7];bool c;

void Find(vector<bool> cur){
	if(c){return;}
	int v = 0,cnt = 0;
	for(int i = 0;i<9;i++){
		if(cur[i]){v += arr[i];cnt++;}
	}
	if(v == 100 && cnt == 7){
		int idx = 0;
		for(int i = 0;i<9;i++){
			if(cur[i]){ans[idx++] = arr[i];}
		}
		c = 1;
		return;
	}
	else{
		for(int i = 0;i<9;i++){
			if(!cur[i]){
				cur[i] = 1;Find(cur);cur[i] = 0;
			}
		}
	}
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	for(int i = 0;i<9;i++){scanf("%d",&arr[i]);}
	vector<bool> temp = {0,0,0,0,0,0,0,0,0};
	Find(temp);
	for(int i = 0;i<7;i++){printf("%d\n",ans[i]);}
	return 0;
}
