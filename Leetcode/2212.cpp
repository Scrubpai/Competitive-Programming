class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = (int)aliceArrows.size(), mx = 0, m = 0, ar = 0;
        for (int mask=0; mask<(1<<n); mask++) {
            int arrows = 0, tot = 0;
            for (int j=0; j<n; j++) {
                if (mask&(1<<j)) {
                    arrows += aliceArrows[j]+1;
                    tot += j;
                }
            }
            if (arrows > numArrows) continue;
            if (tot > mx) mx = tot, m = mask, ar = arrows;
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int add = 0;
            if (i==0) add = numArrows-ar;
            if (m&(1<<i)) ans.push_back(add+aliceArrows[i]+1);
            else ans.push_back(add);
        }
        return ans;
    }
};