#include<bits/stdc++.h>
using namespace std;

int n;int dp[1001][1001];int b[1001];int a[1001];string g,h;

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n >> g;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	cin >> h;
	for(int i= 1;i<=n;i++){
		cin >> b[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(g[i-1] != h[j-1] && ((g[i-1] == 'W' && a[i] > b[j]) || (g[i-1] == 'L' && a[i] <b[j]))){
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+a[i]+b[j]);
			}
		}
	}
	cout << dp[n][n] << "\n";
	return 0;
}
