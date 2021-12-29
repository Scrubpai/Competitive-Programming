class Solution {
public:
    deque<int> dq; vector<int> ans;
void push(int n) {
    while (!dq.empty() && dq.back() < n) dq.pop_back();
    dq.push_back(n);
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    for (int i=0; i<nums.size(); i++) {
        push(nums[i]);
        if (i+1 >= k) {
            ans.push_back(dq.front());
            if (nums[i+1-k]==dq.front()) dq.pop_front();
        }
    }
    return ans;
}
};