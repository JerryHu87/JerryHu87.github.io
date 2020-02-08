#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Connection{
  int src;
  int dest;
};
int main() {
  int k;
  scanf("%d", &k);
  if(k == 1){
    cout << "2 2" << endl;
    cout << "1 2" << endl;
    cout << "2 1" << endl;
  }
  else if(k == 2){
    cout << "4 5" << endl;
    cout << "1 2" << endl;
    cout << "2 1" << endl;
    cout << "3 4" << endl;
    cout << "4 3" << endl;
    cout << "1 4" << endl;
  }
  else{
    int nodes = 0;
    vector <Connection> c;
    vector <int> allnodes;
    while(k > 0 && k/3 > 0){
      bool check = false;
      int findmax = 3;
      int num = 3;
      nodes += 3;
      while(findmax < k){
        findmax += num;
        num++;
        nodes++;
        check = true;
      }
      if(check && findmax != k){
        num--;
        nodes--;
      }
      if(findmax > k){
        findmax -= num;
      }
      k = k%findmax;
      allnodes.push_back(nodes);
    }
    int previousnode = 1;
    bool check = false;
    Connection temp;
    while(!allnodes.empty()){
      int currentnode = allnodes[0];
      allnodes.erase(allnodes.begin());
      for(int i = previousnode;i<currentnode;i++){
        temp.src = i;
        temp.dest = i + 1;
        c.push_back(temp);
      }
      temp.src = currentnode;
      temp.dest = previousnode;
      c.push_back(temp);
      if(check){
        temp.src = currentnode;
        temp.dest = 1;
        c.push_back(temp);
      }
      previousnode = currentnode + 1;
      check = true;
    }
    for(int i = 0;i<k;i++){
      nodes += 2;
      temp.src = 1;
      temp.dest = nodes-1;
      c.push_back(temp);
      temp.src = nodes;
      temp.dest = nodes-1;
      c.push_back(temp);
      temp.src = nodes-1;
      temp.dest = nodes;
      c.push_back(temp);
    }
    cout << nodes << " " << c.size() << endl;
    while(!c.empty()){
      cout << c[0].src << " " << c[0].dest << endl;
      c.erase(c.begin());
    }
    return 0;
  }
}
