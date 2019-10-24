#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct edge{
  int index;int src;int dest;long long weight;
};

int p[100001];int r[100001];

int Find(int x){
  if(p[x] != x){
    p[x] = Find(p[x]);
  }
  return p[x];
}
void Link(int x, int y){
  if(r[y] < r[x]){
    p[y] = x;
  }
  else{
    p[x] = y;
    if(r[x] == r[y]){
      r[y]++;
    }
  }
}
void Union(int x, int y){
  Link(Find(x), Find(y));
}
bool cmp(const edge a, const edge b){
	if(a.weight != b.weight){return a.weight < b.weight;}
    else{return a.index < b.index;}
}


edge edges[200000];int ma,e,n,m,i,diff;long long d;edge temp;

int main() {
  scanf("%d%d%lld", &n, &m, &d);
  for(i = 1;i<=n;i++){
    p[i] = i;
  }
  for(i = 0;i<m;i++){
    scanf("%d%d%lld", &temp.src,&temp.dest,&temp.weight);
    temp.index = i;edges[i] = temp;
  }
  sort(edges,edges+m,cmp);
  for(i = 0;i<m;i++){
	 if(e == n-1){break;}
	 temp = edges[i];
	 if(Find(temp.src) != Find(temp.dest)){
		 Union(temp.src,temp.dest);e++;ma = temp.weight;
		 if(temp.index >= n-1){diff++;}
	 }
  }
  if(edges[i-1].index >= n-1){
	  for(i = 1;i<=n;i++){p[i] = i;}
	  for(i = 0;i<m;i++){
		  temp = edges[i];
		  if(Find(temp.src) != Find(temp.dest)){
			  if(temp.weight < ma || (temp.weight == ma && temp.index<n-1)){
				  Union(temp.src,temp.dest);
			  }
			  else if(temp.index<n-1 && temp.weight <= d){
				  diff--;break;
			  }
		  }
	  }
  }
  printf("%d\n",diff);
  return 0;
}
