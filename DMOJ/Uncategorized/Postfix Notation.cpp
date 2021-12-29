#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
string s, t; stack<double> st; vector<string> vec;
void solve(int tc) {
    getline(cin, s);
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == ' ') {
            vec.push_back(t);
            t = "";
        } else {
            t += s[i];
        }
    }
    vec.push_back(t);
    for (int i=0; i<(int)vec.size(); i++) {
        if (vec[i][0] >= '0' && vec[i][0] <= '9') st.push(stod(vec[i]));
        else {
            double num2 = st.top(); st.pop();
            double num1 = st.top(); st.pop();
            double ans;
            string op = vec[i];
            if (op == "*") ans = num1 * num2;
            else if (op == "/") ans = num1 / num2;
            else if (op == "+") ans = num1 + num2;
            else if (op == "-") ans = num1 - num2;
            else if (op == "%") ans = (int)num1 % (int)num2;
            else ans = pow(num1, num2);
            st.push(ans);
        }
    }
    printf("%.1f\n", st.top());
}
int32_t main() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tc = 1; /*cin >> tc;*/ for (int t = 1; t <= tc; t++) solve(t); return 0; }