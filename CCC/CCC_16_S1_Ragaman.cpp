#include <bits/stdc++.h>
using namespace std;

int arr[26];int arr2[26];string a,b;int num;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i = 0;i<a.length();i++){arr[a[i]-'a']++;}
    for(int i = 0;i<b.length();i++){
        if(b[i] == '*'){
            num++;
        }
        else{
            arr2[b[i]-'a']++;
        }
    }
    int diff = 0;
    for(int i = 0;i<26;i++){
        diff += abs(arr[i]-arr2[i]);
    }
    diff == num ? printf("A\n"):printf("N\n");
    return 0;
}
