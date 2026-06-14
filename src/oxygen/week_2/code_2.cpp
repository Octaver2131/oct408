// LeetCode: https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/

// oxygen_code
class Solution {
public:
    int max_depth = 0;

    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return max_depth;
    }

    void dfs(TreeNode* t, int cur_depth) {
        if (t == nullptr) return;
        max_depth = max(cur_depth, max_depth);
        dfs(t->left, cur_depth + 1);
        dfs(t->right, cur_depth + 1);
    }
};

// octaver_code

