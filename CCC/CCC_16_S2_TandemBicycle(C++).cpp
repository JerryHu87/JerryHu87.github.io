#include <bits/stdc++.h>
using namespace std;

int n,a,b,t,ans;
int a1[101],a2[101];
int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> t >> n;
    for(int i = 0;i<n;i++){
    	cin >> a1[i];
    }
    for(int i = 0;i<n;i++){
    	cin >> a2[i];
    }
    sort(a1,a1+n);
    sort(a2,a2+n);
    if(t == 1){
    	for(int i = 0;i<n;i++){
    		ans += max(a1[i],a2[i]);
    	}
    }
    else{
    	int p = n-1;
    	for(int i = 0;i<n;i++){
    		ans += max(a1[i],a2[p]);
    		p--;
    	}
    }
    cout << ans << "\n";
    return 0;
}
