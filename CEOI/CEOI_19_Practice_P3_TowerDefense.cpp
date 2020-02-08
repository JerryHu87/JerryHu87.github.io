#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll,ll>

pll f,l;
ll d;

int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	//cout << setprecision(2);cout << fixed;
	cin >> f.first >> f.second >> l.first >> l.second >> d;
	ll d1 = abs(f.first-l.first),d2 = abs(f.second-l.second);
	if(d1+d2 == d){
		cout << "0\n";
	}
	else if(d1+d2 > d || (l.first == f.first && l.second == f.second) || abs(l.first-f.first)+abs(f.second-l.second) == 1 || ((d-d1-d2)&1) == 1){
		cout << "impossible\n";
	}
	else{
		if(abs(f.first-l.first) == 1 && abs(f.second-l.second) == 1){
			d -= 2;
			if(d == 2){
				cout << "impossible\n";
				return 0;
			}
		}
		if(f.first == l.first || f.second == l.second){cout << d-d1-d2-1 << "\n";}
		else{cout << d-d1-d2 << "\n";}
		if(f.first == l.first){
			pll p1 = {f.first,max(f.second,l.second)-1},p2 = {f.first,max(f.second,l.second)-1};
			cout << p1.first << " " << p1.second << "\n";
			p1.first--;p2.first++;
			for(int i = 0;i<(d-d1-d2-2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.first--;p2.first++;
			}
		}
		else if(f.second == l.second){
			pll p1 = {max(f.first,l.first)-1,f.second},p2 = {max(f.first,l.first)-1,f.second};
			cout << p1.first << " " << p1.second << "\n";
			p1.second--;p2.second++;
			for(int i = 0;i<(d-d1-d2-2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.second--;p2.second++;
			}
		}
		else if(f.first < l.first && f.second > l.second){
			pll p1 = {l.first-1,l.second},p2 = {l.first,l.second+1};
			for(int i = 0;i<(d-d1-d2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.second--;p2.first++;
			}
		}
		else if(f.first > l.first && f.second > l.second){
			pll p1 = {l.first+1,l.second},p2 = {l.first,l.second+1};
			for(int i = 0;i<(d-d1-d2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.second--;p2.first--;
			}
		}
		else if(f.first > l.first && f.second < l.second){
			pll p1 = {l.first+1,l.second},p2 = {l.first,l.second-1};
			for(int i = 0;i<(d-d1-d2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.second++;p2.first--;
			}
		}
		else{
			pll p1 = {l.first-1,l.second},p2 = {l.first,l.second-1};
			for(int i = 0;i<(d-d1-d2)/2;i++){
				cout << p1.first << " " << p1.second << "\n" << p2.first << " " << p2.second << "\n";
				p1.second++;p2.first++;
			}
		}
	}
	return 0;
}
