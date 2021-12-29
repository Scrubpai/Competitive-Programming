class Solution {
public:
    vector<int> idx[10]; int cnt[10];
    bool anagram(string a, string b) {
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        return a == b;
    }
    bool isTransformable(string s, string t) {
        if (!anagram(s, t)) return 0;
        for (int i = 0; i < s.size(); i++) idx[s[i] - '0'].push_back(i);
        for (int i = 0; i < t.size(); i++) {
            int cur = t[i] - '0';
            for (int j = 0; j < cur; j++) {
                if (cnt[j] < idx[j].size() && idx[j][cnt[j]] < idx[cur][cnt[cur]]) return 0;
            }
            cnt[cur]++;
        }
        return 1;
    }
};