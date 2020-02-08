#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pb push_back;
#define largestbit(x) 31-__builtin_clz(x);
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long fpow(long long  b, long long exp, long long mod){if(exp == 0) return 1;long long t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
long long divmod(long long i, long long j, long long mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}

int n,psa[513][513],grid[513][513],ans[513][513];

void fill(int x1,int y1,int x2,int y2,int v){
	for(int x = x1;x<=x2;x++){
		for(int y = y1;y<=y2;y++){
			ans[x][y] = v;
		}
	}
}
int sum(int x1,int y1,int x2,int y2){
	return psa[x2][y2]-psa[x1-1][y2]-psa[x2][y1-1]+psa[x1-1][y1-1];
}
int f(int x1,int y1,int x2,int y2){
	if(x1 == x2 && y1 == y2){return 0;}
	int xm = (x2+x1)/2,ym = (y2+y1)/2;
	int s1 = sum(x1,y1,xm,ym);
	int s2 = sum(x1,ym+1,xm,y2);
	int s3 = sum(xm+1,y1,x2,ym);
	int s4 = sum(xm+1,ym+1,x2,y2);
	int t1 = f(x1,y1,xm,ym);
	int t2 = f(x1,ym+1,xm,y2);
	int t3 = f(xm+1,y1,x2,ym);
	int t4 = f(xm+1,ym+1,x2,y2);
	vector<pii> p;
	int area = (x2-x1+1)*(y2-y1+1)/4;
	p.push_back({s1+area-s2+t3+t4,1});
	p.push_back({s1+area-s3+t2+t4,2});
	p.push_back({s1+area-s4+t2+t3,3});
	p.push_back({s2+area-s1+t3+t4,4});
	p.push_back({s2+area-s3+t1+t4,5});
	p.push_back({s2+area-s4+t1+t3,6});
	p.push_back({s3+area-s1+t2+t4,7});
	p.push_back({s3+area-s2+t1+t4,8});
	p.push_back({s3+area-s4+t1+t2,9});
	p.push_back({s4+area-s1+t2+t3,10});
	p.push_back({s4+area-s2+t1+t3,11});
	p.push_back({s4+area-s3+t1+t2,12});
	sort(p.begin(),p.end());
	if(p[0].second == 1){
		fill(x1,y1,xm,ym,0);fill(x1,ym+1,xm,y2,1);
		//f(xm+1,y1,x2,ym);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 2){
		fill(x1,y1,xm,ym,0);fill(xm+1,y1,x2,ym,1);
		//f(x1,ym+1,xm,y2);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 3){
		fill(x1,y1,xm,ym,0);fill(xm+1,ym+1,x2,y2,1);
		//f(x1,ym+1,xm,y2);f(xm+1,y1,x2,ym);
	}
	else if(p[0].second == 4){
		fill(x1,ym+1,xm,y2,0);fill(x1,y1,xm,ym,1);
		//f(xm+1,y1,x2,ym);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 5){
		fill(x1,ym+1,xm,y2,0);fill(xm+1,y1,x2,ym,1);
		//f(x1,y1,xm,ym);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 6){
		fill(x1,ym+1,xm,y2,0);fill(xm+1,ym+1,x2,y2,1);
		//f(x1,y1,xm,ym);f(xm+1,y1,x2,ym);
	}
	else if(p[0].second == 7){
		fill(xm+1,y1,x2,ym,0);fill(x1,y1,xm,ym,1);
		//f(x1,ym+1,xm,y2);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 8){
		fill(xm+1,y1,x2,ym,0);fill(x1,ym+1,xm,y2,1);
		//f(x1,y1,xm,ym);f(xm+1,ym+1,x2,y2);
	}
	else if(p[0].second == 9){
		fill(xm+1,y1,x2,ym,0);fill(xm+1,ym+1,x2,y2,1);
		//f(x1,y1,xm,ym);f(x1,ym+1,xm,y2);
	}
	else if(p[0].second == 10){
		fill(xm+1,ym+1,x2,y2,0);fill(x1,y1,xm,ym,1);
		//f(x1,ym+1,xm,y2);f(xm+1,y1,x2,ym);
	}
	else if(p[0].second == 11){
		fill(xm+1,ym+1,x2,y2,0);fill(x1,ym+1,xm,y2,1);
		//f(x1,y1,xm,ym);f(xm+1,y1,x2,ym);
	}
	else{
		fill(xm+1,ym+1,x2,y2,0);fill(xm+1,y1,x2,ym,1);
		//f(x1,y1,xm,ym);f(x1,ym+1,xm,y2);
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	cout << endl;
	*/
	return p[0].first;
}
int main(){
	//freopen("file.in","r",stdin); freopen("file.out","w",stdout);
	cin.sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			char c;
			cin >> c;
			ans[i][j] = grid[i][j] = c-'0';
			psa[i][j] = grid[i][j]+psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
		}
	}
	cout << f(1,1,n,n) << "\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}
/*
I:
4
0001
0001
0011
1110

O:
1
0001
0001
0011
1111

I:
4
1111
1111
1111
1111

O:
6
0011
0011
0111
1101

I:
8
01010001
10100011
01010111
10101111
01010111
10100011
01010001
10100000

O:
16
00000001
00000011
00000111
00001111
11110111
11110011
11110001
11110000

I:
16
1111111101001000
1111111100100110
1101111100001010
1111111110101101
0011111100000000
1111111000000001
1111010100001000
1111111100010001
1111111011101010
1011001000111100
0111011101001111
1111011001111111
0101100011110011
0000010011110101
1111001111110010
1101011111110011

O:
46
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111000000001000
1111000000001100
1111000000001101
1111000000001111
0001100011110011
0000010011110111
1111001111110010
1101011111110011

WA:
46
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111111100000000
1111000000001000
1111000000001100
1111000000001101
1111000000001111
0001100011110011
0000010011110011
1111001111110010
1101011111110011

 */
