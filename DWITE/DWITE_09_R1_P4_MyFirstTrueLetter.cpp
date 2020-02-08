#include <bits/stdc++.h>
using namespace std;

string a;int cnt[26];

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    for(int z= 0;z<5;z++){
        cin >> a;
        for(int i = 0;i<26;i++){cnt[i] = 0;}
        for(int i = 0;i<a.length();i++){
            cnt[a[i]-'A']++;
        }
        for(int i = 0;i<a.length();i++){
            if(cnt[a[i]-'A'] == 1){
                printf("%c\n",a[i]);break;
            }
        }
    }
    return 0;
}
