#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pins[30001];
unsigned long long dp[30001][501];
unsigned long long psa[30001];

int main() {
  int t,n,k,w;
  scanf("%d", &t);
  for(int z = 0;z<t;z++){
    scanf("%d%d%d", &n, &k, &w);
    scanf("%d", &pins[0]);
    psa[0] = pins[0];
    for(int i = 1;i<n;i++){
      scanf("%d", &pins[i]);
      psa[i] = psa[i-1]+pins[i];
    }
    unsigned long long max = 0;
    for(int i = 0;i<w;i++){
      dp[i][0] = psa[i];
    }
    for(int i = w;i<n;i++){
      if(psa[i]-psa[i-w] > dp[i][0]){
        dp[i][0] = psa[i]-psa[i-w];
      }
      else{
        dp[i][0] = dp[i-1][0];
      }
    }
    for(int i = 0;i<n;i++){
      for(int j = 0;j<k;j++){
        if(i-w >= 0 && j-1>= 0 && dp[i-w][j-1] + psa[i]-psa[i-w] > dp[i][j]){
          dp[i][j] =  dp[i-w][j-1] + psa[i] - psa[i-w];
        } 
        if(i-1 >= 0 && dp[i-1][j] >= dp[i][j]){
          dp[i][j] = dp[i-1][j];
        }
        if(dp[i][j] > max){
          max = dp[i][j];
        }
      }
    }
    cout << max << "\n";
    for(int i = 0;i<n;i++){
      psa[i] = 0;
      pins[i] = 0;
      for(int j = 0;j<k;j++){
        dp[i][j] = 0;
      }
    }
  }
  return 0;
}
