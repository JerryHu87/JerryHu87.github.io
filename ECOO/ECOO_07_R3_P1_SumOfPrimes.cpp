#include<bits/stdc++.h>
using namespace std;


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
//cin.sync_with_stdio(0);cin.tie(0);

bool sieve[10000001];long long arr[664578];long long x,l,h,idx,m,high,temp,num;vector<int> poss;bool c;

void init(){
	sieve[0] = 1;sieve[1] = 1;
	for(int i = 2;i<=10000000;i+=2){sieve[i] = 1;}
	for(int i = 3;i<=10000000;i++){
		if(sieve[i]){continue;}
		arr[idx] = i;idx++;
		for(int j = i*2;j<=10000000;j+=i){
			sieve[j] = 1;
		}
	}
}

int main(){
	init();
	for(int z= 0;z<5;z++){
		scanf("%lld",&x);
		if(!sieve[x]){
			printf("%lld = %lld\n",x,x);
		}
		else if(x%2 == 0){
			for(int i = 664577;i>=0;i--){
				if(x-arr[i] < 0){continue;}
				if(arr[i] <= x-arr[i] && !sieve[x-arr[i]]){
					printf("%lld = %lld + %lld\n",x,arr[i],x-arr[i]);
					break;
				}
			}
		}
		else{
			idx = 0;poss.clear();c = 0;
			while(arr[idx]*3<=x){
				poss.push_back(arr[idx]);idx++;
			}
			for(int j = poss.size()-1;j>=0;j--){
				temp = x-(poss[j]*3);num = poss[j];
				if(temp == 0){
					printf("%lld = %lld + %lld + %lld\n",x,num,num,num);
					break;
				}
				for(int i = 5000;i>=0;i--){
					if(i<=temp-i && !sieve[num+i] && !sieve[num+(temp-i)]){
						printf("%lld = %lld + %lld + %lld\n",x,num,num+i,num+(temp-i));c = 1;
						break;
					}
				}
				if(c){break;}
			}
		}
	}
	return 0;
}
