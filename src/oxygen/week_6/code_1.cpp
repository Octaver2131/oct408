// LeetCode: https://leetcode.cn/problems/rotate-array/

// oxygen_code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& a, int l, int r) {
        for(int i = l, j = r; i < j; i++, j--) {
            swap(a[i], a[j]);
        }
    }
};

// octaver_code
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) swap(nums[l++], nums[r--]);
    }
};
