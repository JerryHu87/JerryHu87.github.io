#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    string a;
    cin >> a;
    int max = 0;
    for(int i = 0;i<a.size();i++){
        int l = i;int r = i;
        while(l>=0 && r<=a.size() && a[l] == a[r]){
            l--;r++;
        }
        if(r-l > max)max = r-l;
        l = i;r = i+1;
        while(l>=0 && r<=a.size() && a[l] == a[r]){
            l--;r++;
        }
        if(r-l > max)max = r-l;
        l = i-1;r = i;
        while(l>=0 && r<=a.size() && a[l] == a[r]){
            l--;r++;
        }
        if(r-l > max)max = r-l;
    }
    cout << max-1 << "\n";
    return 0;
}
