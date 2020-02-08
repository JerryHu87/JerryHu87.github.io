#include<bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int arr[100001];long long bits[100001];long long bitf[100001];
int n,m,a,b;char c;

void update(int x, int v, int o){
	int d = v-o;
	for(;x<=n;x+=x&-x){bits[x]+=d;}
	for(;v<=100000;v+=v&-v){bitf[v]++;}
	if(o != 0){
		for(;o<=100000;o+=o&-o){bitf[o]--;}
	}
}
long long sum(int l,int r){
	long long sum = 0;
	for(;r>0;r-=r&-r){sum += bits[r];}
	for(;l>0;l-=l&-l){sum -= bits[l];}
	return sum;
}
long long freq(int x){
	long long sum = 0;
	for(;x>0;x-=x&-x){sum += bitf[x];}
	return sum;
}

int main(){
	scan(n);scan(m);
	for(int i = 1;i<=n;i++){
		scan(arr[i]);
		update(i,arr[i],0);
	}
	for(int i = 1;i<=m;i++){
		scanf(" %c", &c);
		if(c == 'C'){
			scan(a);scan(b);
			update(a,b,arr[a]);arr[a] = b;
		}
		else if(c == 'S'){
			scan(a);scan(b);
			cout << sum(a-1,b) << "\n";
		}
		else{
			scan(a);
			cout << freq(a) << "\n";
		}
	}
	return 0;
}
