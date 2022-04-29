const int MM = 1e5+5;
#define lc (rt<<1)
#define rc (rt<<1|1)
class Solution {
public:
    struct node { int l, r, pre, suf, ans; } seg[4*MM];
    void pushup(int rt, string &s) {
        seg[rt].ans = max(seg[lc].ans, seg[rc].ans);
        seg[rt].pre = seg[lc].pre; seg[rt].suf = seg[rc].suf;
        int l = seg[rc].l, r = seg[lc].r;
        if (s[l] == s[r]) { 
            seg[rt].ans = max(seg[rt].ans, seg[lc].suf + seg[rc].pre);
            if (seg[lc].pre == seg[lc].r - seg[lc].l + 1) seg[rt].pre += seg[rc].pre;
            if (seg[rc].suf == seg[rc].r - seg[rc].l + 1) seg[rt].suf += seg[lc].suf;
        }
    }
    void build(int l, int r, int rt, string &s) {
        seg[rt].l = l; seg[rt].r = r;
        if (l == r) { seg[rt].pre = seg[rt].suf = seg[rt].ans = 1; return; }
        int mid = (l+r)/2;
        build(l, mid, lc, s); build(mid+1, r, rc, s); pushup(rt, s);
    }
    void update(int p, int rt, string &s) {
        if (seg[rt].l == seg[rt].r) return;
        int mid = (seg[rt].l + seg[rt].r) / 2;
        if (p <= mid) update(p, lc, s);
        else update(p, rc, s);
        pushup(rt, s);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = (int)queryIndices.size(), n = (int)s.size(); vector<int> ans;
        build(0, n-1, 1, s);
        for (int i=0; i<k; i++) {
            s[queryIndices[i]] = queryCharacters[i];
            update(queryIndices[i], 1, s);
            ans.push_back(seg[1].ans);
        }
        return ans;
    }
};