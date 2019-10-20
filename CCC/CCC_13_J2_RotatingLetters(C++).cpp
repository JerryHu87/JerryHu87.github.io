#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  string temp;
  cin >> temp;
  bool check = 0;
	for(int i = 0;i<temp.size();i++) {
			if(temp[i] != 'I' && temp[i] != 'O' && temp[i] != 'S' && temp[i] != 'H' && temp[i] != 'Z' && temp[i] != 'X' && temp[i] != 'N') {
				cout << "NO" << endl;
				check = 1;
				break;
			}
		}
		if(check == 0) {
			cout << "YES" << endl;
		}
}
