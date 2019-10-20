#include <bits/stdc++.h>
using namespace std;

bool p[101];int m,k,a,cur;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> k >> m;
    for(int z = 0;z<m;z++){
        cin >> a;cur = 0;
        for(int i = 1;i<=k;i++){
            if(!p[i]){cur++;}
            if(cur%a == 0){p[i] = 1;cur = 0;}
        }
    }
    for(int i = 1;i<=k;i++){
        if(!p[i]){
            cout << i << "\n";
        }
    }
    return 0;
}
