#include <bits/stdc++.h>
using namespace std;

int s,d,l,temp;

int main() {
    scanf("%d%d",&s,&d);
    while(s>=d){
        temp = s-d;
        s = d;d = temp;l++;
    }
    cout << l+2 << "\n";
    return 0;
}
