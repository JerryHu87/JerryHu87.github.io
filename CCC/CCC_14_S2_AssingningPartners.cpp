#include <bits/stdc++.h>
using namespace std;

int n;string a[30];string b[30];unordered_map<string,string> um;bool c;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n;i++){
        cin >> b[i];
    }
    for(int i = 0;i<n;i++){
        if(a[i] == b[i]){
            c = 1;break;
        }
        if(!um.count(b[i])){
            um[a[i]] = b[i];
        }
        else if(um[b[i]] != a[i]){
            c = 1;break;
        }
    }
    c ? printf("bad\n"):printf("good\n");
    return 0;
}
