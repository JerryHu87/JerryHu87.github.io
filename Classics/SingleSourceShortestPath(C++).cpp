#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge{
  int dest;
  int weight;
};
struct state{
  int node;
  int cost;
};
class cmp{
  public:
    int operator()(const state a, const state b){
      return a.cost > b.cost;
    }
};

vector<edge> nodes[1001];
priority_queue<state, vector<state>, cmp> pq;
int dist[1001];

int main() {
  int n, m, s, d, w;
  edge temp;
  scanf("%d%d", &n, &m);
  for(int i = 1;i<=n;i++){dist[i] = INT_MAX;}
  for(int i = 0;i<m;i++){
    scanf("%d%d%d", &s, &d, &w);
    temp.dest = d;
    temp.weight = w;
    nodes[s].push_back(temp);
    temp.dest = s;
    nodes[d].push_back(temp);
  }
  state t;
  t.node = 1;
  t.cost = 0;
  dist[1] = 0;
  pq.push(t);
  while(!pq.empty()){
    state current = pq.top();
    pq.pop();
    for(int i = 0;i<nodes[current.node].size();i++){
      if(dist[nodes[current.node][i].dest] > dist[current.node] + nodes[current.node][i].weight){
        dist[nodes[current.node][i].dest] = dist[current.node] + nodes[current.node][i].weight;
        t.node = nodes[current.node][i].dest;
        t.cost = dist[nodes[current.node][i].dest];
        pq.push(t);
      }
    }
  }
  for(int i = 1;i<=n;i++){
    if(dist[i] == INT_MAX){cout << -1 << "\n";}
    else{cout << dist[i] << "\n";}
  }
  return 0;
}
