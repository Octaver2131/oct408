// LeetCode: https://leetcode.cn/problems/sum-of-left-leaves/

// oxygen_code
class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return sum;
    }

    void dfs(TreeNode* t, int tag) {
        if (t == nullptr) return;

        if (t->left == nullptr && t->right == nullptr && tag == 0)
            sum += t->val;

        dfs(t->left, 0);
        dfs(t->right, 1);
    }
};

// octaver_code

