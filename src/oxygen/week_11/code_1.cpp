// LeetCode: https://leetcode.cn/problems/univalued-binary-tree/

// oxygen_code
class Solution {
public:
    bool res = true;
    bool first = true;
    int pre;

    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* t) {
        if (t == nullptr) return;

        if (first) {
            first = false;
            pre = t->val;
        } else {
            if (pre != t->val) res = false;
            pre = t->val;
        }

        dfs(t->left);
        dfs(t->right);
    }
};

// octaver_code
class Solution {
public:
    int val;
    bool tag = true;

    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        dfs(root);
        return tag;
    }

    void dfs(TreeNode* t) {
        if (!t) return;

        dfs(t->left);
        if (t->val != val) tag = false;
        dfs(t->right);
    }
};
