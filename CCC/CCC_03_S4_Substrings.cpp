#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0;i<n;i++){
    string str;
    cin >> str;
    unordered_set <string> s;
    int num = 0;
    for(int j = 1;j<str.size();j++){
      for(int r = 0;r<=str.size()-j;r++){
        s.insert(str.substr(r, j));
      }
      num += s.size();
      s.clear();
    }
    cout << num + 2 << endl;
  }
  return 0;
}
