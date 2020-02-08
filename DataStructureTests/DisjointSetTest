#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge{
  int src;
  int dest;
};

int p[100001];
int r[100001];
vector<edge> connections;
vector<int> ans;

int Find(int x){
  if(p[x] != x){
    p[x] = Find(p[x]);
  }
  return p[x];
}
void Link(int x, int y){
  if(r[x] > r[y]){
    p[y] = x;
  }
  else{
    p[x] = y;
    if(r[x] == r[y]){
      r[y]++;
    }
  }
}
void Union(int x, int y){
  Link(Find(x),Find(y));
}

int main() {
  int n,m;
  scanf("%d%d", &n,&m);
  edge temp;
  for(int i = 0;i<m;i++){
    scanf("%d%d", &temp.src,&temp.dest);
    connections.push_back(temp);
  }
  for(int i = 1;i<=n;i++){
    p[i] = i;
    r[i] = 0;
  }
  for(int i = 0;i<connections.size();i++){
    if(Find(connections[i].src) != Find(connections[i].dest)){
      Union(connections[i].src,connections[i].dest);
      ans.push_back(i+1);
      if(ans.size() == n-1){
        break;
      }
    }
  }
  if(ans.size() == n-1){
    for(int i = 0;i<ans.size();i++){
      cout << ans[i] << endl;
    }
  }
  else{
    cout << "Disconnected Graph" << endl;
  }
  return 0;
}
