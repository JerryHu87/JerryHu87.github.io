#include <bits/stdc++.h>

using namespace std;

vector<int> nodes[2001];
bool vis[2001];

int main() {
    int n,m,a,b,s,d;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i = 0;i<m;i++){
        scanf("%d%d",&s,&d);
        nodes[s].push_back(d);nodes[d].push_back(s);
    }
    queue<int> q;
    q.push(a);vis[a] = 1;
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int e:nodes[cur]){
            if(!vis[e]){
                vis[e] = 1;
                q.push(e);
            }
        }
    }
    vis[b] ? printf("GO SHAHIR!\n"):printf("NO SHAHIR!\n");
    return 0;
}
