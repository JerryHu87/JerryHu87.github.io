#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p[200001];
int r[200001];

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
  cin.tie(0);cin.sync_with_stdio(0);
  int n;
  char q;
  string s,d;
  int index = 0;
  for(int z = 0;z<5;z++){
    cin >> n;
    index = 0;
    unordered_map<string, int> m;
    for(int i = 0;i<n;i++){
      p[i] = i;
      r[i] = 0;
    }
    for(int i = 0;i<n;i++){
      cin >> q;
      cin >> s >> d;
      if(!m.count(s)){
        m[s] = index;
        index++;
      }
      if(!m.count(d)){
        m[d]= index;
        index++;
      }
      if(q == 'p'){
        Union(m[s],m[d]);
      }
      else{
        if(Find(m[s]) == Find(m[d])){
          printf("connected\n");
        }
        else{
          printf("not connected\n");
        }
      }
    }
  }
  return 0;
}
