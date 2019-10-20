#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int poss[25][25];
bool cat[25][25];

int main() {
  int r, c,k, cr, cc;;
  scanf("%d%d", &r, &c);
  scanf("%d", &k);
  for(int i = 0;i<k;i++){
    scanf("%d%d", &cr, &cc);
    cat[cr-1][cc-1] = 1;
  }
  for(int i = 0;i<r;i++){
    if(cat[i][0]){break;}
    poss[i][0] = 1;
  }
  for(int i = 0;i<c;i++){
    if(cat[0][i]){break;}
    poss[0][i] = 1;
  }
  for(int i = 1;i<max(r,c);i++){
    for(int j = i;j<c;j++){
      if(!cat[i-1][j]){
        poss[i][j] += poss[i-1][j];
      }
      if(!cat[i][j-1]){
        poss[i][j] += poss[i][j-1];
      }
    }
    for(int j = i+1;j<r;j++){
      if(!cat[j-1][i]){
        poss[j][i] += poss[j-1][i];
      }
      if(!cat[j][i-1]){
        poss[j][i] += poss[j][i-1];
      }
    }
  }
  printf("%d\n", poss[r-1][c-1]);
}
