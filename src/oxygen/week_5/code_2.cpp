// LeetCode: https://leetcode.cn/problems/invert-binary-tree/description/

// oxygen_code
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode* t) {
        if (t == nullptr) return nullptr;

        TreeNode* left = dfs(t->left);
        TreeNode* right = dfs(t->right);
        t->left = right;
        t->right = left;
        return t;
    }
};

// octaver_code

