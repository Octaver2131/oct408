// LeetCode: https://leetcode.cn/problems/balanced-binary-tree/

// oxygen_code
class Solution {
public:
    bool res = true;

    bool isBalanced(TreeNode* root) {
        check(root);
        return res;
    }

    int check(TreeNode* t) {
        if (t == nullptr) return 0;
        int l = check(t->left);
        int r = check(t->right);
        if (abs(l - r) > 1) res = false;
        return max(l, r) + 1;
    }
};

// octaver_code