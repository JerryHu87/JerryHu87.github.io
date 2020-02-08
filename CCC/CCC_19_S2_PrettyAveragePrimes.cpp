#include<bits/stdc++.h>
using namespace std;

bool sieve[2000001];int t,n,idx;int arr[148933
];

void init(){
	sieve[0] = 1;sieve[1] = 1;
	for(int i = 2;i<=2000000;i++){
		if(sieve[i]){continue;}
		else{arr[idx] = i;idx++;}
		for(int j = i*2;j<=2000000;j+=i){
			sieve[j] = 1;
		}
	}
}

int main(){
	init();
	scanf("%d",&t);
	for(int i = 0;i<t;i++){
		scanf("%d",&n);
		for(int j = 0;j<148933;j++){
			if(n*2-arr[j] >= 0 && n*2-arr[j] <= 2000000 && !sieve[n*2-arr[j]]){
				printf("%d %d\n",arr[j],n*2-arr[j]);break;
			}
		}
	}
	return 0;
}
