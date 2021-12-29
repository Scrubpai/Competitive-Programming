class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i=1; i<=9; i++) {
            for (int j=1; j+i-1<=9; j++) {
                int num = 0, p = 1;
                for (int k=j+i-1; k>=j; k--) {
                    num += p*k;
                    p *= 10;
                }
                if (num >= low && num <= high) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};