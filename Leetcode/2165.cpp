class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> digits(10, 0); long long tmp = num; tmp = abs(tmp);
        while (tmp) { digits[tmp%10]++; tmp/=10; }
        long long ans = 0;
        if (num == 0) return 0;
        else if (num > 0) {
            for (int i=1; i<10; i++) {
                if (digits[i]) {
                    if (!ans) {
                        digits[i]--;
                        ans = ans * 10 + i;
                        for(int j=0; j<digits[0]; j++) ans *= 10;
                    }
                    for (int j=0; j<digits[i]; j++) ans = ans*10 + i;
                }
            }
            return ans;
        } else {
            for (int i=9; i>=0; i--) {
                for (int j=0; j<digits[i]; j++) {
                    ans = ans * 10 + i;
                }
            }
            return -ans;
        }
    }
};