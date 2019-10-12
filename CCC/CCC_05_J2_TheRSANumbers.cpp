#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,ans;
    scanf("%d%d", &a,&b);
    ans = 0;
    for(int i = a;i<=b;i++){
        int divisor = 0;
        for(int j = 1;j<=i;j++){
            if(i%j == 0){
                divisor++;
            }
        }
        if(divisor == 4){
            ans++;
        }
    }
    cout << "The number of RSA numbers between " << a << " and " << b << " is " << ans << endl;
    return 0;
}
