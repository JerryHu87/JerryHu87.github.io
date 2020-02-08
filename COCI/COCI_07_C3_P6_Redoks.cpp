#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int tree[10][1000005],arr[250001],lazy[1000005],temp[10];int n,m,a,b;char c;

void build(int cur,int l,int r){
	if(l == r){
		tree[arr[l]][cur] = 1;
	}
	else{
		int mid = (l+r)/2;
		build(cur*2,l,mid);build(cur*2+1,mid+1,r);
		for(int i = 0;i<10;i++){tree[i][cur] = tree[i][cur*2]+tree[i][cur*2+1];}
	}
}
void update(int cur,int l,int r, int lo,int hi){
	if(l<=lo && hi<=r){
		lazy[cur]++;
	}
	if(lazy[cur] != 0){
		for(int i = 0;i<10;i++){
			temp[(i+lazy[cur])%10] = tree[i][cur];
		}
		for(int i = 0;i<10;i++){
			tree[i][cur] = temp[i];
		}
		if(lo != hi){
			lazy[cur*2] += lazy[cur];lazy[cur*2+1] += lazy[cur];
		}
		lazy[cur] = 0;
	}
	if((hi<l || r<lo) || (l<=lo && hi<=r)){}
	else{
		int mid = (lo+hi)/2;
		update(cur*2,l,r,lo,mid);update(cur*2+1,l,r,mid+1,hi);
		for(int i = 0;i<10;i++){tree[i][cur] = tree[i][cur*2]+tree[i][cur*2+1];}
	}
}
int query(int cur,int l,int r, int lo,int hi){
	if(lazy[cur] != 0){
		for(int i = 0;i<10;i++){
			temp[(i+lazy[cur])%10] = tree[i][cur];
		}
		for(int i = 0;i<10;i++){
			tree[i][cur] = temp[i];
		}
		if(lo != hi){
			lazy[cur*2] += lazy[cur];lazy[cur*2+1] += lazy[cur];
		}
		lazy[cur] = 0;
	}
	if(l <= lo && hi <= r){
		int sum = 0;
		for(int i = 0;i<10;i++){sum += (tree[i][cur]*i);}
		return sum;
	}
	else if(hi<l || lo>r){
		return 0;
	}
	int mid = (lo+hi)/2;
	return query(cur*2,l,r,lo,mid)+query(cur*2+1,l,r,mid+1,hi);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){scanf(" %c",&c);arr[i] = c-'0';}
	build(1,1,n);
	for(int i = 0;i<m;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",query(1,a,b,1,n));update(1,a,b,1,n);
	}
	return 0;
}
