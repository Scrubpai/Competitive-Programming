class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int siz = arr.size(); int cnt = 0;
        for (int i = 0; i < siz; i++) {
            for (int j = i + 1; j < siz; j++) {
                for (int k = j + 1; k < siz; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) cnt++;
                }   
            }
        }
        return cnt;
    }
};