// LeetCode: https://leetcode.cn/problems/sort-array-by-parity/

// oxygen_code
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            while (l < r && nums[l] % 2 == 0) l++;
            while (l < r && nums[r] % 2 == 1) r--;
            if (l < r) swap(nums[l], nums[r]);
        }
        return nums;
    }
};

// octaver_code
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;

        for (int x : nums)
            if (x % 2 == 0) res.push_back(x);
        for (int x : nums)
            if (x % 2 == 1) res.push_back(x);

        return res;
    }
};