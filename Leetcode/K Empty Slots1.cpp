const int MM = 2e4 + 5;
class Solution {
public:
    int days[MM];
    int kEmptySlots(vector<int>& bulbs, int K) {
        for (int i = 0; i < bulbs.size(); i++) {
            days[bulbs[i]] = i + 1;
        }
        int left = 1, right = left + K + 1, n = bulbs.size(), ans = MM;
        while (right <= n) {
            bool flag = 1;
            for (int i = left + 1; i < right; i++) {
                if (days[i] < days[left] || days[i] < days[right]) {
                    left = i;
                    right = i + K + 1;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans = min(ans, max(days[left], days[right]));
                cout << left << " " << right << " " << days[left] << " " << days[right] << endl;
                left = right; 
                right = left + K + 1;
            }
        }
        if (ans == MM) return -1;
        else return ans;
    }
};