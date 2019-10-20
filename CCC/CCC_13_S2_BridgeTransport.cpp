#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[100000];
long long psa[100000];

int main() {
  int n,w;
  scanf("%d", &w);
  scanf("%d", &n);
  scanf("%d", &arr[0]);
  psa[0] = arr[0];
  for(int i = 1;i<n;i++){
    scanf("%d", &arr[i]);
    psa[i] = psa[i-1] +arr[i];
  }
  for(int i = 0;i<4;i++){
    if(psa[i] > w){
      cout << i << "\n";
      return 0;
    }
  }
  for(int j = 4;j<n;j++){
    if(psa[j]-psa[j-4] >w){
      cout << j << "\n";
      return 0;
    }
  }
  cout << n << "\n";
}
