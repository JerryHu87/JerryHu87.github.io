#include <bits/stdc++.h>

using namespace std;

long long n,k,ans;

int main() {
    cin >> n >> k;
    for(long long i = 0;i<=k;i++){
        ans += n*pow(10,i);
    }
    cout << ans << "\n";
    return 0;
}
