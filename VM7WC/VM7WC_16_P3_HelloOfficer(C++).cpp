#include <iostream>
#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int> , vector<pair<int,int> >, greater<pair<int, int> > > pq;
vector<pair<int, int> > nodes[2001];
int dist[2001];

int main() {
  int n, m, b, q, s, d, w,z;
  scanf("%d%d%d%d", &n, &m ,&b, &q);
  for(int i = 1;i<=n;i++){dist[i] = INT_MAX;}
  for(int i = 0;i<m;i++){
    scanf("%d%d%d",&s, &d, &w);
    nodes[s].push_back(make_pair(w,d));
    nodes[d].push_back(make_pair(w,s));
  }
  pq.push(make_pair(0,b));
  dist[b] = 0;
  while(!pq.empty()){
    pair<int, int> current = pq.top();pq.pop();
    for(int i = 0;i<nodes[current.second].size();i++){
      if(dist[nodes[current.second][i].second] > dist[current.second]+nodes[current.second][i].first){
        dist[nodes[current.second][i].second] = dist[current.second]+nodes[current.second][i].first;
        pq.push(make_pair(dist[nodes[current.second][i].second], nodes[current.second][i].second));
      }
    } 
  }
  for(int i = 0;i<q;i++){
    scanf("%d" , &z);
    if(dist[z] != INT_MAX){printf("%d\n", dist[z]);}
    else{printf("-1\n");}
  }
}
