#include <bits/stdc++.h>
using namespace std;

bool sieve[1001];
int t = 0;

int main() {
    int n, k;
    scanf("%d%d",&n, &k);
    for(int i = 2;i<=n;i++){
        if(sieve[i])continue;
        for(int j = i;j<=n;j+=i){
            if(!sieve[j]){sieve[j] = 1;t++;}
            if(t == k){printf("%d\n",j);return 0;}
        }
    }
    return 0;
}
