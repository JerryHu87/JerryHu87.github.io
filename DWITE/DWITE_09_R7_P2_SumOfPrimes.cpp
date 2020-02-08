#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool sieve[100001];
int psa[100001];

void init(){
  for(int i = 2;i<=100000;i++){
    if(sieve[i] == 0){
      int start = i*2;
      for(int j = start;j<=100000;j+=i){
        sieve[j] = 1;
      }
    }
  }
}
void sum(){
  psa[0] = 0;
  for(int i = 1;i<=100000;i++){
    if(sieve[i] == 0){
      psa[i] = i + psa[i-1];
    }
    else{
      psa[i] = psa[i-1];
    }
  }
}

int main() {
  int n;
  sieve[0] = 1;
  sieve[1] = 1;
  init();
  sum();
  for(int z = 0;z<5;z++){
    scanf("%d", &n);
    cout << psa[n] << endl;
  }
}
