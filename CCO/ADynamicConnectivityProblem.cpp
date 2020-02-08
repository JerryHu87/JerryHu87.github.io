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

int p[500001],r[500001],arr[500001],ans[500001];
vector<int> edges[500001];
bool use[500001],vis[500001];

int Find(int x){
	if(p[x] != x){
		return p[x] = Find(p[x]);
	}
	return p[x];
}
void Link(int x,int y){
	if(r[x] > r[y]){
		p[y] = x;
	}
	else{
		p[x] = y;
		if(r[x] == r[y]){r[y]++;}
	}
}
void Union(int x,int y){
	Link(Find(x),Find(y));
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	//cin.sync_with_stdio(0);cin.tie(0);
	int n,m,k;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){p[i] = i;}
	for(int i = 0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	scanf("%d",&k);
	for(int i = 0;i<k;i++){
		scanf("%d",&arr[i]);
		use[arr[i]] = 1;
	}
	queue<int> q;
	for(int i = 0;i<n;i++){
		if(use[i]){continue;}
		if(!vis[i]){
			vis[i] = 1;
			q.push(i);
			while(!q.empty()){
				int cur = q.front();q.pop();
				for(int e:edges[cur]){
					if(!vis[e] && !use[e]){
						q.push(e);
						vis[e] = 1;
					}
				}
			}
			ans[k]++;
		}
		for(int e:edges[i]){
			if(Find(e) != Find(i) && !use[e]){Union(e,i);}
		}
	}
	for(int i = k-1;i>=0;i--){
		ans[i] = ans[i+1]+1;
		use[arr[i]] = 0;
		for(int e:edges[arr[i]]){
			if(Find(e) != Find(arr[i]) && !use[e]){
				Union(e,arr[i]);
				ans[i]--;
			}
		}
	}
	for(int i = 0;i<=k;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
