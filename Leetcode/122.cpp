class Solution {
public:
    int ans;
int maxProfit(vector<int>& prices) {
    int last = prices[0];
    for (int i=1; i<prices.size(); i++) {
        if (prices[i] <= prices[i-1]) {
            ans += (prices[i-1] - last);
            last = prices[i];
        } else if ((prices[i] >= last && i==prices.size()-1)) {
            ans += prices[i] - last;
        } else if (prices[i] < last) last = prices[i];

      //  cout << last << nl;
    }
    return ans;
}
};