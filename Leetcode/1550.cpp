class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] % 2 == 1 && arr[i-1] % 2 == 1 && arr[i-2] % 2 == 1) return true;
        }
        return 0;
    }
};