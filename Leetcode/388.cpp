const int MM = 1e4 + 5;
class Solution {
public:
    string dep[MM]; int ans; 
    int lengthLongestPath(string input) {
        stringstream ss(input); string line;
        while (getline(ss, line)) {
            int i = 0, t = 0, n = line.size(); string cur = "";
            while (i < n && line[i] == '\t') i++, t++;
            bool flag = 0;
            for (; i < n; i++) {
                cur += line[i];
                if (line[i] == '.') flag = 1;
            }
            dep[t] = cur;
            if (flag) {
                int tmp = 0;
                for (int j = 0; j <= t; j++) tmp += dep[j].size();
                ans = max(ans, tmp + t);
            }
        }
        return ans;
    }
};