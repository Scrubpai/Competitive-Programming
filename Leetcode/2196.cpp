/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int MM = 1e5+5;
class Solution {
public:
    bool vis[MM]; int lft[MM], rit[MM];
    TreeNode* buildtree(int rt) {
        TreeNode* root = new TreeNode(rt);
        if (lft[rt]) root->left = buildtree(lft[rt]);
        if (rit[rt]) root->right = buildtree(rit[rt]);
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = (int)descriptions.size();
        for (int i=0; i<n; i++) {
            int p = descriptions[i][0], c = descriptions[i][1], l = descriptions[i][2];
            vis[c] = 1;
            if (l) lft[p] = c;
            else rit[p] = c;
        }
        int rt = -1;
        for (int i=0; i<n; i++) {
            if (!vis[descriptions[i][0]]) { rt = descriptions[i][0]; break; }
        }
        TreeNode* root = buildtree(rt);
        return root;
    }
};