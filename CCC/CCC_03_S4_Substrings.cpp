#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
#include <string>
using namespace std;

long long int pw[100001];
long long int n,cur,num;
string str;

void init(){
    pw[0] = 1;
    for(int i = 1;i<=100000;i++){
    	pw[i] = pw[i-1]*131;
    }
}
int main() {
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	init();
	for(int i = 0;i<n;i++){
		cin >> str;
		num = 0;
		unordered_set <long long int> s;
		for(int j = 0;j<(int)str.size();j++){
			cur = 0;
			for(int r = 0;r<=(int)str.size()-j;r++){
				cur = cur+pw[r]*str[j+r];
				s.insert(cur);
			}
		}
		cout << s.size()+1 << "\n";
	}
  return 0;
}
