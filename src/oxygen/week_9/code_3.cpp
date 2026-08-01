// LeetCode: https://leetcode.cn/problems/kth-smallest-element-in-a-bst/

// oxygen_code
class Solution {
public:
    int min_value = -1;
    int res;
    int cnt = 0;
    bool flag = false;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* t, int k) {
        if (t == nullptr || flag == true) return;
        dfs(t->left, k);
        if (t->val >min_value) {
            min_value = t->val;
            cnt++;
            if (cnt == k) {
                res = min_value;
                flag = true;
            }
        }
        dfs(t->right, k);
    }
};

// octaver_code
class Solution {
public:
    int res, i;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* t, int k) {
        if (!t) return;
        dfs(t->left, k);
        i++;
        if (i == k) {
            res = t->val;
            return;
        }
        dfs(t->right, k);
    }
};
