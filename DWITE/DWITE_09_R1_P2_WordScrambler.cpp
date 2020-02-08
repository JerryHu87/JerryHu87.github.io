#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


priority_queue<string,vector<string>,greater<string> > pq;
string a;bool check;

void find(string current,int ind){
	if(current.length() == a.length()){
		pq.push(current);
	}
	else{
		for(int i = 0;i<a.length();i++){
			check = 0;
			for(int j = 0;j<ind;j++){
				if(a[i] == current[j]){check = 1;break;}
			}
			if(!check){find(current.substr(0,ind)+a[i],ind+1);}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);cin.tie(0);
	for(int z = 0;z<5;z++){
		cin >> a;
		find("",0);
		while(!pq.empty()){
			cout << pq.top() << "\n";pq.pop();
		}
	}
	return 0;
}
