class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (target > 1 && maxDoubles) {
            if (target % 2 == 1) ans += 2, target = (target-1)/2;
            else ans++, target/=2;
            maxDoubles--;
        }
        ans += (target - 1);
        return ans;
    }
};