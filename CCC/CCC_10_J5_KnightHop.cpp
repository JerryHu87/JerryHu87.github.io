#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point{
  int r;
  int c;
};
int main() {
  Point start,end;
  scanf("%d", &start.r);
  scanf("%d", &start.c);
  scanf("%d", &end.r);
  scanf("%d", &end.c);
  start.c -= 1;
  start.r -= 1;
  end.c -= 1;
  end.r -= 1;
  int dist[8][8];  
  for(int i = 0;i<8;i++){
    for(int j = 0;j<8;j++){
      dist[i][j] = INT_MAX;
    }
  }
  dist[start.r][start.c] = 0;
  queue<Point> q;
  q.push(start);
  while(!q.empty()){
    Point currentpoint, temp;
    currentpoint.r = q.front().r;
    currentpoint.c = q.front().c;
    q.pop();
    if(currentpoint.r + 2 < 8 && currentpoint.c+ 1 < 8 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r+2][currentpoint.c+1]){
      dist[currentpoint.r+2][currentpoint.c+1] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r+2;
      temp.c = currentpoint.c+1;
      q.push(temp);
    }
    if(currentpoint.r + 2 < 8 && currentpoint.c- 1 >= 0 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r+2][currentpoint.c-1]){
      dist[currentpoint.r+2][currentpoint.c-1] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r+2;
      temp.c = currentpoint.c-1;
      q.push(temp);
    }
    if(currentpoint.r - 2 >= 0 && currentpoint.c+ 1 < 8 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r-2][currentpoint.c+1]){
      dist[currentpoint.r-2][currentpoint.c+1] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r-2;
      temp.c = currentpoint.c+1;
      q.push(temp);
    }
    if(currentpoint.r - 2 >= 0 && currentpoint.c- 1 >= 0 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r-2][currentpoint.c-1]){
      dist[currentpoint.r-2][currentpoint.c-1] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r-2;
      temp.c = currentpoint.c-1;
      q.push(temp);
    }
    if(currentpoint.r + 1 < 8 && currentpoint.c+2 <8 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r+1][currentpoint.c+2]){
      dist[currentpoint.r+1][currentpoint.c+2] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r+1;
      temp.c = currentpoint.c+2;
      q.push(temp);
    }
    if(currentpoint.r + 1 < 8 && currentpoint.c-2 >= 0 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r+1][currentpoint.c-2]){
      dist[currentpoint.r+1][currentpoint.c-2] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r+1;
      temp.c = currentpoint.c-2;
      q.push(temp);
    }
    if(currentpoint.r - 1 >=0 && currentpoint.c+2 <8 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r-1][currentpoint.c+2]){
      dist[currentpoint.r-1][currentpoint.c+2] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r-1;
      temp.c = currentpoint.c+2;
      q.push(temp);
    }
    if(currentpoint.r - 1 >=0 && currentpoint.c-2 >= 0 && dist[currentpoint.r][currentpoint.c]+1 < dist[currentpoint.r-1][currentpoint.c-2]){
      dist[currentpoint.r-1][currentpoint.c-2] = dist[currentpoint.r][currentpoint.c] + 1;
      temp.r = currentpoint.r-1;
      temp.c = currentpoint.c-2;
      q.push(temp);
    }
  }
  cout << dist[end.r][end.c] << endl;
  return 0;
}
