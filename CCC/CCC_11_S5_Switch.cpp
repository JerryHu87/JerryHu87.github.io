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

int n,st;
unordered_map<int,int> dis;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 0,t;i<n;i++){
		cin >> t;
		st |= (t<<i);
	}
	queue<int> q;
	dis[st] = 0;
	q.push(st);
	while(!q.empty()){
		int u = q.front();q.pop();
		bool c = 0;
		for(int j = 0;j<n;j++){
			if((u&(1<<j)) == 0){
				int t = u,p = 0,idx = -1;
				t |= (1<<j);
				for(int z = 0;z<n;z++){
					if((t&(1<<z)) > 0){p++;}
					else{p = 0;}
					if(p == 4 && (t&(1<<z)) > 0){idx = z;}
				}
				if(idx != -1){
					t &= (~(1<<idx));
					for(int r = idx-1;r>=0 && (t&(1<<r)) > 0;r--){t &= (~(1<<r));}
					for(int r = idx+1;r<n && (t&(1<<r)) > 0;r++){t &= (~(1<<r));}
				}
				if(!dis.count(t)){
					dis[t] = dis[u]+1;
					if(t == 0){
						c = 1;
						break;
					}
					q.push(t);
				}
			}
		}
		if(c){break;}
	}
	cout << dis[0] << "\n";
	return 0;
}
