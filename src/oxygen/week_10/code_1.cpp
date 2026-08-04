// LeetCode: https://leetcode.cn/problems/binary-tree-paths/

// oxygen_code
class Solution {
public:
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return res;
    }

    void dfs(TreeNode* t, vector<int> &path) {
        if (t->left == nullptr && t->right == nullptr) {
            path.push_back(t->val);
            work(path);
            path.pop_back();
            return;
        }
        path.push_back(t->val);
        if (t->left) dfs(t->left, path);
        if (t->right) dfs(t->right, path);
        path.pop_back();
    }

    void work(vector<int> path) {
        string r = "";
        int n = path.size();
        for (int i = 0; i < n - 1; i++) {
            r += to_string(path[i]) + "->";
        }
        r += to_string(path[n - 1]);
        res.push_back(r);
    }
};

// octaver_code

