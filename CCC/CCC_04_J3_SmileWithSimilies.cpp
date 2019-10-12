#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	vector<string> adj(a);
	vector<string> noun(b);
	for (int i = 0; i < a; i++) {
		string temp;
		cin >> temp;
		adj[i] = temp;
	}
	for (int i = 0; i < b; i ++) {
		string temp;
		cin >> temp;
		noun[i] = temp;
	}
	for (unsigned int i = 0; i < adj.size(); i++) {
		for (unsigned int j = 0; j < noun.size(); j++) {
			cout << adj[i] << " as " << noun[j] << "\n";
		}
	}
	return 0;
}
