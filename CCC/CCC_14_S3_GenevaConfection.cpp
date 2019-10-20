#include <bits/stdc++.h>
using namespace std;

int t,n,cur,temp;stack<int> a;stack<int> b;

int main() {
    cin.sync_with_stdio(0);cin.tie(0);
    cin >> t;
    for(int z = 0;z<t;z++){
        cin >> n;cur = 1;
        for(int i = 0;i<n;i++){
            cin >> temp;a.push(temp);
        }
        while(!a.empty()){
            if(a.top() == cur || (!b.empty() && b.top() == cur)){
                if(a.top() == cur){a.pop();}
                else{b.pop();}
                cur++;
            }
            else{
                b.push(a.top());a.pop();
            }
        }
        while(!b.empty() && b.top() == cur){
            b.pop();cur++;
        }
        if(a.empty() && b.empty()){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
        while(!a.empty()){a.pop();}
        while(!b.empty()){b.pop();}
    }
    return 0;
}
