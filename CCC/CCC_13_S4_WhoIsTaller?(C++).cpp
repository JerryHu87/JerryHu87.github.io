#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  vector<int> nodes[n+1];
  bool visited[n+1];
  for(int i = 1;i<=n;i++){
    visited[i] = 0;
  }
  for(int i = 0;i<m;i++){
    int src, dest;
    scanf("%d", &src);
    scanf("%d", &dest);
    nodes[src].push_back(dest);
  }
  int src, dest;
  scanf("%d", &src);
  scanf("%d", &dest);
  queue<int> q;
  q.push(src);
  while(!q.empty()){
    int current = q.front();
    q.pop();
    visited[current] = 1;
    for(int i = 0;i<nodes[current].size();i++){
      if(visited[nodes[current][i]] == 0){
        q.push(nodes[current][i]);
      }
    }
  }
  if(visited[dest]){
    cout << "yes" << endl;
    return 0;
  }
  for(int i = 1;i<n;i++){
    visited[i] = 0;
  }
  q.push(dest);
  while(!q.empty()){
    int current = q.front();
    q.pop();
    visited[current] = 1;
    for(int i = 0;i<nodes[current].size();i++){
      if(visited[nodes[current][i]] == 0){
        q.push(nodes[current][i]);
      }
    }
  }
  if(visited[src]){
    cout << "no" << endl;
  }
  else{
    cout << "unknown" << endl;
  }
  return 0;
}
