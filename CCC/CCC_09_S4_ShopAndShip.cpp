#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct edge{
  int dest;
  int weight;
};
struct pencil{
  int city;
  int price;
};

vector<edge> nodes[5001];
int dist [5001];
vector<pencil> pencils;

int main() {
  int n, t, k;
  scanf("%d", &n);
  scanf("%d", &t);
  for(int i = 0;i<t;i++){
    int src, dest, weight;
    scanf("%d", &src);
    scanf("%d", &dest);
    scanf("%d", &weight);
    edge temp;
    temp.dest = dest;
    temp.weight = weight;
    nodes[src].push_back(temp);
    temp.dest = src;
    nodes[dest].push_back(temp);
  }
  queue<int> q;
  scanf("%d", &k);
  for(int i = 0;i<k;i++){
    int city, price;
    scanf("%d", &city);
    scanf("%d", &price);
    pencil temp;
    temp.city = city;
    temp.price = price;
    pencils.push_back(temp);
  }
  for(int i = 1;i<=n;i++){
    dist[i] = INT_MAX;
  }
  int start;
  scanf("%d", &start);
  q.push(start);
  dist[start] = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    for(int i = 0;i<nodes[current].size();i++){
      if(dist[nodes[current][i].dest] > dist[current] + nodes[current][i].weight){
        dist[nodes[current][i].dest] = dist[current] + nodes[current][i].weight;
        q.push(nodes[current][i].dest);
      }
    }
  }
  int minvalue = INT_MAX;
  for(int i = 0;i<pencils.size();i++){
    if(pencils[i].price + dist[pencils[i].city] < minvalue){
      minvalue = pencils[i].price + dist[pencils[i].city];
    }
  }
  cout << minvalue << endl;
  return 0;
}
