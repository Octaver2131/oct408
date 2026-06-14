// LeetCode: https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/

// oxygen_code
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int> a, int l, int r) {
        if (l > r) return nullptr;

        int mid = (l + r) >> 1;
        TreeNode* node = new TreeNode(a[mid]);
        node->left = dfs(a, l, mid - 1);
        node->right = dfs(a, mid + 1, r);
        return node;
    }
};

// octaver_code
