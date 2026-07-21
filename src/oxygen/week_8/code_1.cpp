// LeetCode: https://leetcode.cn/problems/minimum-depth-of-binary-tree/

// oxygen_code

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);

        if (root->left == nullptr) return r + 1;
        if (root->right == nullptr) return l + 1;

        return min(l, r) + 1;
    }
};

// octaver_code
class Solution {
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* t) {
        if (!t) return 0;
        int l = dfs(t->left);
        int r = dfs(t->right);

        if (l == 0) return r + 1;
        if (r == 0) return l + 1;
        return min(l, r) + 1;
    }
};