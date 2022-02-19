const int MM = 2e4+5;
class Solution {
public:
    int hsh[MM], dsu[MM], sz[MM]; unordered_map<int, int> mp;
    int fd(int x) { if (dsu[x] == x) return x; else return dsu[x] = fd(dsu[x]); }
    vector<int> groupStrings(vector<string>& words) {
        int n = (int)words.size(), mx = 0, cnt = n; vector<int> ans(2);
        for (int i=0; i<n; i++) {
            dsu[i] = i; sz[i] = 1;
            for (int j=0; j<(int)words[i].size(); j++) {
                hsh[i] |= (1<<(words[i][j]-'a'));
            }
            for (int j=0; j<26; j++) {
                if (hsh[i] & (1<<j)) {
                    int del = hsh[i] ^ (1<<j);
                    if (mp.count(del)) {
                        int fa = fd(i), fb = fd(mp[del]);
                        if (fa != fb) dsu[fa] = fb, sz[fb] += sz[fa], cnt--;
                    }
                    for (int k=0; k<26; k++) {
                        int rep = del | (1<<k);
                        if (rep != del && mp.count(rep)) {
                            int fa = fd(i), fb = fd(mp[rep]);
                            if (fa != fb) dsu[fa] = fb, sz[fb] += sz[fa], cnt--;
                        }
                    }
                } else {
                    int add = hsh[i] | (1<<j);
                    if (mp.count(add)) {
                        int fa = fd(i), fb = fd(mp[add]);
                        if (fa != fb) dsu[fa] = fb, sz[fb] += sz[fa], cnt--;
                    }
                }
            }
            mp[hsh[i]] = i;
        }
        for (int i=0; i<n; i++) {
            ans[1] = max(ans[1], sz[fd(i)]);
        }
        ans[0] = cnt;
        return ans;
    }
};