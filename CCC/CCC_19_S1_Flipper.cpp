#include<bits/stdc++.h>
using namespace std;

int grid[2][2] = {{1,2},{3,4}};string n;int temp[2][2];

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 0;i<n.length();i++){
		if(n[i] == 'H'){
			temp[0][0] = grid[1][0];temp[0][1] = grid[1][1];temp[1][0] = grid[0][0];temp[1][1] = grid[0][1];
			grid[0][0] = temp[0][0];grid[1][0] = temp[1][0];grid[0][1] = temp[0][1];grid[1][1] = temp[1][1];
		}
		else{
			temp[0][0] = grid[0][1];temp[0][1] = grid[0][0];temp[1][0] = grid[1][1];temp[1][1] = grid[1][0];
			grid[0][0] = temp[0][0];grid[1][0] = temp[1][0];grid[0][1] = temp[0][1];grid[1][1] = temp[1][1];
		}
	}
	cout << grid[0][0] << " " << grid[0][1] << "\n" << grid[1][0] << " " << grid[1][1] << "\n";
	return 0;
}
