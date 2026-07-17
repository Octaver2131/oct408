// LeetCode: https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/

// oxygen_code
class Solution {
public:
    int pre = INT_MIN;
    int cnt = 0;
    int most_number = -1;
    vector<int> res;
    bool isFirst = true;

    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return res;
        dfs(root);
        if (cnt > most_number) {
            res.clear();
            res.push_back(pre);
        } else if (cnt == most_number) {
            res.push_back(pre);
        }
        return res;
    }

    void dfs(TreeNode* t) {
        if (t == nullptr) return;
        dfs(t->left);

        if(pre != t->val) {
            if (!isFirst) {
                if (cnt > most_number) {
                    res.clear();
                    res.push_back(pre);
                    most_number = cnt;
                } else if (cnt == most_number) {
                    res.push_back(pre);
                }
            }
            pre = t->val;
            cnt = 1;
            isFirst = false;
        } else {
            cnt++;
        }

        dfs(t->right);
    }
};

// octaver_code
class Solution {
public:
    vector<int> res;
    int base, cnt, maxCount;

    void update(int x) {
        if (x == base) {
            cnt++;
        } else {
            cnt = 1;
            base = x;
        }
        if (cnt == maxCount) {
            res.push_back(base);
        }
        if (cnt > maxCount) {
            maxCount = cnt;
            res = vector<int> {base};
        }
    }

    void dfs(TreeNode* t) {
        if (!t) return;

        dfs(t->left);
        update(t->val);
        dfs(t->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};

