#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge{
  int dest;
  int weight;
};

vector<edge> nodes[10001];
int mintrav[10001];
bool fin[10001];

int main() {
  int c,r,d,src,dest,t;
  scanf("%d%d%d", &c, &r, &d);
  edge temp;
  for(int i = 0;i<r;i++){
    scanf("%d%d%d", &src, &dest, &temp.weight);
    temp.dest = dest;
    nodes[src].push_back(temp);
    temp.dest = src;
    nodes[dest].push_back(temp);
  }
  for(int i = 0;i<d;i++){
    scanf("%d", &t);
    fin[t] = 1;
  }
  queue<int> q;
  q.push(1);
  mintrav[1] = INT_MAX;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i = 0;i<nodes[current].size();i++){
      if(nodes[current][i].weight < mintrav[current] && nodes[current][i].weight > mintrav[nodes[current][i].dest]){
        mintrav[nodes[current][i].dest] = nodes[current][i].weight;
        q.push(nodes[current][i].dest);
      }
      else if(nodes[current][i].weight > mintrav[current] && mintrav[current] > mintrav[nodes[current][i].dest]){
        mintrav[nodes[current][i].dest] = mintrav[current];
        q.push(nodes[current][i].dest);
      }
    }
  }
  int min = INT_MAX;
  for(int i = 1;i<=c;i++){
    if(fin[i] == 1 && min > mintrav[i]){
      min = mintrav[i];
    }
  }
  cout << min << endl;
}
