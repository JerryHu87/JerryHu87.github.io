#include <bits/stdc++.h>
using namespace std;

bool sieve[1001];
vector<int> a;

void init(){
    for(int i = 2;i<=1000;i++){
        if(sieve[i])continue;
        for(int j = i*2;j<=1000;j+=i){
            sieve[j] = 1;
        }
    }
}
void factor(int num){
    int temp = num;
    for(int i = 2;i<=sqrt(num);i++){
        while(temp%i == 0){
            a.push_back(i);temp/=i;
        }
    }
    if(temp > 1){
        a.push_back(temp);
    }
}

int main() {
    init();int n;
    for(int z = 0;z<5;z++){
        scanf("%d",&n);
        factor(n);
        int ans = 0;
        for(int i = 0;i<a.size();i++){
            if(!sieve[a[i]])ans++;
        }
        if(ans == 2)printf("semiprime\n");
        else printf("not\n"); 
        a.clear();
    }
    return 0;
}
