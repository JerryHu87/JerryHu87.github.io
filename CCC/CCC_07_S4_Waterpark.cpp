#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> parents[10000];
bool visited[10000];
int poss[10000];

void findprob(int current){
  visited[current] = 1;
  for(int i = 0;i<parents[current].size();i++){
    if(visited[parents[current][i]] == 0){findprob(parents[current][i]);}
    poss[current] += poss[parents[current][i]];
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int src,dest;
  scanf("%d%d", &src, &dest);
  while(src != 0 && dest != 0){
    parents[dest].push_back(src);
    scanf("%d%d", &src, &dest);
  }
  poss[1] = 1;
  findprob(n);
  cout << poss[n] << endl;
}
