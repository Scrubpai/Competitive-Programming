#include <bits/stdc++.h>
using namespace std;
string a, op, b;
int main(){
    cin >> a >> op >> b;
    if(a.size() < b.size()) swap(a, b);
    if(op == "*"){
        cout << "1";
        for(int i=1; i<(int)a.size()+b.size()-1; i++) cout << "0";
        cout << endl;
    }else{
        if(a.size()==b.size()) a[0] = '2';
        else a[a.size()-b.size()]='1';
        cout << a << endl;
    }
}