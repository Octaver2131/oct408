// LeetCode: https://leetcode.cn/problems/minimum-distance-between-bst-nodes/

// oxygen_code
class Solution {
public:
    int max_val = 0x3f3f3f3f;
    bool isfirst = true;
    int pre;

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return max_val;
    }

    void dfs(TreeNode* t) {
        if (t == nullptr) return;
        dfs(t->left);
        if (isfirst) {
            isfirst = false;
            pre = t->val;
        } else {
            max_val = min(max_val, t->val - pre);
            pre = t->val;
        }
        dfs(t->right);
    }
};

// octaver_code
class Solution {
public:
    int max_val = 0x3f3f3f3f;
    bool isfirst = true;
    int pre;

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return max_val;
    }

    void dfs(TreeNode* t) {
        if (!t) return;

        dfs(t->left);

        if (isfirst) isfirst = false;
        else max_val = min(max_val, t->val - pre);
        pre = t->val;

        dfs(t->right);
    }
};
