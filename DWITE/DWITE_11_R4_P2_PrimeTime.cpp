#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int freq[10001];

int main() {
  int n,r;
  unordered_set<int> s;
 	for(int z = 0;z<5;z++) {
    scanf("%d", &n);
    for(int i = 2;i<=n;i++) {
      r = i;
      int max = (int)(sqrt(r));
		  while(r%2 == 0) {
			  freq[2]++;
			  r = r/2;
        s.insert(2);
	  	}
		  for(int j = 3;j<=max;j += 2) {
		  	while(r%j == 0) {
			  	freq[j]++;
			  	r = r/j;
          s.insert(j);
			  }
		  }
      if(r > 1) {
			  freq[r]++;
        s.insert(r);
		  }
    }
    for(int i = 2;i<=10000;i++){
      if(freq[i] > 0 && s.size() > 1){
        cout << i << "^" << freq[i] << " * ";
        s.erase(s.begin());
      }
      else if(freq[i] > 0 && s.size() == 1){
        cout << i << "^" << freq[i];
      }
      freq[i] = 0;
    }
    cout << endl;
    s.clear();
   }
   return 0;
}
