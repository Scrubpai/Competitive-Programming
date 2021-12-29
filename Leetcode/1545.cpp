class Solution {
public:
    string a[25]; int len[25];    
    char findKthBit(int n, int k) {
        a[1] = "0";
        for (int i = 2; i <= n; i++) {
            string add = "";
            for (int j = a[i-1].size() - 1; j >= 0; j--) {
                if (a[i-1][j] == '0') add += '1';
                else add += '0';
            }
            a[i] = a[i-1] + '1' + add;
        }
        return a[n][k-1];
    }
};