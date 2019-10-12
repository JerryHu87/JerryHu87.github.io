#include <bits/stdc++.h>
using namespace std;

int dist[5281];int n,d;int c[32];queue<int> q;

int main() {
    scanf("%d%d",&d,&n);memset(dist,0x3f3f3f3f,sizeof(dist));dist[0] = 0;
    for(int i = 0;i<n;i++){scanf("%d",&c[i]);}
    q.push(0);
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int i = 0;i<n;i++){
            if(cur+c[i]<=d && dist[cur+c[i]] > dist[cur]+1){
                dist[cur+c[i]] = dist[cur]+1;q.push(cur+c[i]);
            }
        }
    }
     dist[d] == 0x3f3f3f3f ? printf("Roberta acknowledges defeat.\n"):printf("Roberta wins in %d strokes.",dist[d]);
    return 0;
}
