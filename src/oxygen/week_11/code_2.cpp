// LeetCode: https://leetcode.cn/problems/find-pivot-index/

// oxygen_code
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.size(); i++) {
            right += nums[i];
        }

        if (left == right) return 0;

        for (int i = 1; i < nums.size(); i++) {
            left += nums[i - 1];
            right -= nums [i];
            if (left == right) return i;
        }
        return -1;
    }
};


// octaver_code
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        for (int i = 0; i < n; i++)
            if (2 * pre[i] + nums[i] == pre[n])
                return i;
        return -1;
    }
};
