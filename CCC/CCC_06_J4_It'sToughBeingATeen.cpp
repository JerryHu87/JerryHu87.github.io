#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  int src, dest;
  vector<int> parents[8];
  bool visited[8];
  vector<int> l;
  parents[7].push_back(1);
  parents[4].push_back(1);
  parents[1].push_back(2);
  parents[4].push_back(3);
  parents[5].push_back(3);
  scanf("%d", &src);
  scanf("%d", &dest);
  for(int i = 1;i<=7;i++){
    visited[i] = 0;
  }
  while(src != 0 && dest != 0){
    parents[dest].push_back(src);
    scanf("%d", &src);
    scanf("%d", &dest);
  }
  for(int z = 0;z<7;z++){
    for(int i = 1;i<=7;i++){
      bool check = 0;
      for(int j = 0;j<parents[i].size();j++){
        if(visited[parents[i][j]] == 1){
          check = 0;
        }
        else{
          check = 1;
          break;
        }
      }
      if((check == 0 || parents[i].empty()) && visited[i] == 0){
        l.push_back(i);
        visited[i] = 1;
        break;
      }
    }
  }
  if(l.size() == 7){
    for(int i = 0;i<l.size();i++){
      cout << l[i] << " ";
    }
  }
  else{
    cout << "Cannot complete these tasks. Going to bed." << endl;
  }
}
