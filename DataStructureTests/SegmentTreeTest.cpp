#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[100001];int mtree[400001];int gtree[400001];int ctree[400001];

void build(int cur,int lo,int hi){
	if(lo == hi){
		mtree[cur] = arr[lo];gtree[cur] = arr[lo];ctree[cur] = 1;
	}
	else{
		int mid = (lo+hi)/2;
		build(cur*2,lo,mid);build(cur*2+1,mid+1,hi);
		mtree[cur] = min(mtree[cur*2],mtree[cur*2+1]);
		gtree[cur] = gcd(gtree[cur*2],gtree[cur*2+1]);
		int temp = gcd(gtree[cur*2],gtree[cur*2+1]);
		if(gtree[cur*2] == gtree[cur*2+1]){
			ctree[cur] = ctree[cur*2]+ctree[cur*2+1];
		}
		else if(gtree[cur*2] == temp){
			ctree[cur] = ctree[cur*2];
		}
		else if(gtree[cur*2+1] == temp){
			ctree[cur] = ctree[cur*2+1];
		}
		else{
			ctree[cur] = 0;
		}
	}
}
void update(int cur,int x,int lo,int hi){
	if(lo == hi && lo == x){
		mtree[cur] = arr[x];gtree[cur] = arr[x];
	}
	else{
		int mid = (lo+hi)/2;
		x <= mid ? update(cur*2,x,lo,mid):update(cur*2+1,x,mid+1,hi);
		mtree[cur] = min(mtree[cur*2],mtree[cur*2+1]);
		gtree[cur] = gcd(gtree[cur*2],gtree[cur*2+1]);
		int temp = gcd(gtree[cur*2],gtree[cur*2+1]);
		if(gtree[cur*2] == gtree[cur*2+1]){
			ctree[cur] = ctree[cur*2]+ctree[cur*2+1];
		}
		else if(gtree[cur*2] == temp){
			ctree[cur] = ctree[cur*2];
		}
		else if(gtree[cur*2+1] == temp){
			ctree[cur] = ctree[cur*2+1];
		}
		else{
			ctree[cur] = 0;
		}
	}
}
int mquery(int cur,int l,int r,int lo,int hi){
	if(l<=lo && hi<=r){
		return mtree[cur];
	}
	else if(hi<l || lo>r){
		return INF;
	}
	int mid = (lo+hi)/2;
	return min(mquery(cur*2,l,r,lo,mid),mquery(cur*2+1,l,r,mid+1,hi));
}
int gquery(int cur,int l,int r,int lo,int hi){
	if(l<=lo && hi<=r){
		return gtree[cur];
	}
	else if(hi<l || lo>r){
		return 0;
	}
	int mid = (lo+hi)/2;
	int t1 = gquery(cur*2,l,r,lo,mid);int t2 = gquery(cur*2+1,l,r,mid+1,hi);
	if(t1 == 0){
		return t2;
	}
	else if(t2 == 0){
		return t1;
	}
	else{
		return gcd(t1,t2);
	}
}
pair<int,int> cquery(int cur,int l,int r,int lo,int hi){
	if(l<=lo && hi<=r){
		return {gtree[cur],ctree[cur]};
	}
	else if(hi<l || lo>r){
		return {0,0};
	}
	int mid = (lo+hi)/2;
	pair<int,int> t1 = cquery(cur*2,l,r,lo,mid);pair<int,int> t2 = cquery(cur*2+1,l,r,mid+1,hi);int ans = 0;int temp = 0;
	if(t1.first == 0){
		ans = t2.first;
	}
	else if(t2.first == 0){
		ans = t1.first;
	}
	else{
		ans = gcd(t1.first,t2.first);
	}
	if(ans == t1.first){
		temp += t1.second;
	}
	if(ans == t2.first){
		temp += t2.second;
	}
	return {ans,temp};

}
int main(){
	int n,m,a,b;char c;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){scanf("%d",&arr[i]);}
	build(1,1,n);
	for(int z = 1;z<=m;z++){
		scanf(" %c",&c);scanf("%d%d",&a,&b);
		if(c == 'C'){
			arr[a] = b;update(1,a,1,n);
		}
		else if(c == 'M'){
			printf("%d\n",mquery(1,a,b,1,n));
		}
		else if(c == 'G'){
			printf("%d\n",gquery(1,a,b,1,n));
		}
		else{
			printf("%d\n",cquery(1,a,b,1,n).second);
		}
	}
}
