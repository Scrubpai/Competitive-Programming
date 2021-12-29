class Solution {
public:
    set<int> st;
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size(); st.insert(bulbs[0]);
        for (int i = 1; i < n; i++) {
            int cur = bulbs[i];
            auto it = st.upper_bound(cur);
            if (it != st.end() && *it - cur == K + 1) {
              //  cout << pos[idx] << " " << cur << endl;
                return i + 1;
            }
            if (it != st.begin()) it--;
            if (cur - *it == K + 1) {
            //    cout << pos[idx] << " " << cur << endl;
                return i + 1;
            }
            st.insert(cur);
        }
        return -1;
    }
};