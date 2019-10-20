#include <bits/stdc++.h>
using namespace std;

char r[10000];

int main() {
    int n;
    char c;
    int ans = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf(" %c", &r[i]);
    }
    for(int i = 0;i<n;i++){
        scanf(" %c", &c);
        if(c == r[i]){ans++;}
    }
    printf("%d", ans);
    return 0;
}
