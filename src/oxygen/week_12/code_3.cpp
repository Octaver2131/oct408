// LeetCode: https://leetcode.cn/problems/diameter-of-binary-tree/

// oxygen_code
class Solution {
public:
    int res = -1;
    int diameterOfBinaryTree(TreeNode* root) {
        int t = dfs(root);
        return res;
    }

    int dfs(TreeNode* t) {
        if (t == nullptr) return 0;

        int l = dfs(t->left);
        int r = dfs(t->right);

        res = max(res, l + r);
        return max(l, r) + 1;
    }
};

// octaver_code
