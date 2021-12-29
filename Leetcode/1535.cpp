class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int siz = arr.size(); int cnt = 0, win = 0;
        for (int i = 1; i < siz; i++) {
            if (arr[i] > arr[win]) {
                win = i; cnt = 1;
            } else {
                cnt++;
            }
            if (cnt == k) return arr[win];
        }
        return arr[win];
    }
};