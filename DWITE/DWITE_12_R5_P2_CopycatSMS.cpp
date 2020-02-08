#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    for(int z = 0;z<5;z++){
        string a;
        getline(cin,a);
        bool d = 0;
        for(int i = 1;i<(int)a.length();i++){
            bool c = 0;
            int cnt = i;
            for(int j = 0;j<(int)a.length()-i;j++){
                if(a[cnt++] != a[j]){
                    c = 1;
                    break;
                }
            }
            if(!c){
               cout << a.substr(0,i) << a << "\n";
               d = 1;
               break;
            }
        }
        if(!d){
            cout << a << a << "\n";
        }
    }
    return 0;
}
