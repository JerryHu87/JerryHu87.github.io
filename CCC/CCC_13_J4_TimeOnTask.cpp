#include <bits/stdc++.h>
using namespace std;

int t, c,n,ans;priority_queue<int,vector<int>,greater<int> > pq;

int main() {
    scanf("%d%d",&t,&c);
    for(int i = 0;i<c;i++){
        scanf("%d",&n);pq.push(n);
    }
    while(!pq.empty()){
        int cur = pq.top();pq.pop();
        if(t-cur>=0){
            t-=cur;ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
