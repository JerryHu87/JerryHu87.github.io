#include<bits/stdc++.h>
using namespace std;

#define largestbit(x) 31-__builtin_clz(x);
long long int arr[200001],st[20][200001];int n,q,lg;

void build(){
	for(int i = 1;i<=n;i++){st[0][i] = arr[i];}
	for(int i = 1;i<=lg;i++){
		for(int j = 1;j+(1<<(i-1))<=n;j++){
			st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}
}
long long int query(int l,int r){
	int temp = largestbit(r-l+1);
	return min(st[temp][l],st[temp][r+1-(1<<temp)]);
}

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	lg = (double)log(n)/(double)log(2)+1;
	for(int i = 1;i<=n;i++){
		cin >> arr[i];
	}
	build();
	for(int i = 0;i<q;i++){
		long long int a;int b,c;
		cin >> a >> b >> c;
		while(b<=c){
			int lo = b,hi = c;
			while(lo<=hi){
				int mid = (lo+hi)/2;
				if(query(b,mid) <= a){
					hi = mid-1;
				}
				else{
					lo = mid+1;
				}
			}
			if(arr[lo] > a || lo > c){break;}
			a = a%arr[lo];
			b = lo+1;
		}
		cout << a << "\n";
	}
	return 0;
}
