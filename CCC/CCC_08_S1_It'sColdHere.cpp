#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,string>, vector<pair<int,string> >, greater<pair<int,string> > > pq;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    string a;int b;
    cin >> a >> b;
    while(a != "Waterloo"){
        pq.push(make_pair(b,a));
        cin >> a >> b;
    }
    cout << pq.top().second << "\n";
    return 0;
}
