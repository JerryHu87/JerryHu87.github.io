#include <bits/stdc++.h>
using namespace std;

int n,cnt;
char c;
string s;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> s;
        c = s[0],cnt = 1;
        for(int i = 1;i<(int)s.size();i++){
            if(s[i] != s[i-1]){
                cout << cnt << " " << c << " ";
                cnt = 1,c = s[i];
            }
            else{
                cnt++;
            }
        }
        cout << cnt << " " << c << "\n";
    }
    return 0;
}
