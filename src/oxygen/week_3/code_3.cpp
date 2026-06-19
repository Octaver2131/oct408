// LeetCode: https://leetcode.cn/problems/path-sum/

// oxygen_code
class Solution {
public:
    bool res = false;

    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return res;
    }

    void dfs(TreeNode* t, int sum, int targetSum) {
        if (t == nullptr) return;

        sum += t->val;
        if (sum == targetSum && t->left == nullptr && t->right == nullptr) {
            res = true;
        }
        dfs(t->left, sum, targetSum);
        dfs(t->right, sum, targetSum);
    }
};

// octaver_code

