class Solution {
public:
    int ans = 0, nums[26], letters[26];
    int fac(int n) {
        int ret = 1;
        for (int i = n; i >= 2; i--) ret *= i;
        return ret;
    }
    void fun(int cnt, int len, int cur) {
        if (cnt == 0) {
            int tmp = fac(len);
            for (int i = 0; i < 26; i++) {
                if (nums[i] != 26) tmp /= fac(nums[i]);
            }
            ans += tmp;
            return;
        }
        for (int i = cur; i < 26; i++) {
            if (nums[i] + 1 <= letters[i]) {
                nums[i]++;
                fun(cnt - 1, len, i);
                nums[i]--;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        for (int i = 0; i < n; i++) {
            letters[tiles[i]-'A']++;
        }
        for (int len = 1; len <= n; len++) {
            fun(len, len, 0);
        }
        return ans;
    }
};