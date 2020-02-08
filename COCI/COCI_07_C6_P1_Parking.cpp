#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[101];

int main() {
  int a,b,c,start,end;
  scanf("%d%d%d", &a, &b, &c);
  for(int i = 0;i<=100;i++){
    arr[i] = 0;
  }
  for(int z = 0;z<3;z++){
    scanf("%d%d", &start, &end);
    for(int i = start;i<end;i++){
      arr[i]++;
    }
  }
  int total = 0;
  for(int i = 1;i<=100;i++){
    if(arr[i] == 1){
      total += a;
    }
    else if(arr[i] == 2){
      total = total + 2*b;
    }
    else if(arr[i] == 3){
      total = total + 3*c;
    }
  }
  cout << total << endl;
  return 0;
}
