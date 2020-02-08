#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int z = 0;z<5;z++){
        int n,ans = 0,val;
        scanf("%d",&n);
        val = n;
        for(int i = 2;i<n;i++){
            while(val%i == 0){
                ans++;
                val /= i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
