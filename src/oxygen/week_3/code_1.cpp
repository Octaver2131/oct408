// LeetCode: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

// oxygen_code
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int k = 1;
        int n = a.size();
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) a[k++] = a[i];
        }
        return k;
    }
};

// octaver_code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] ^ nums[i - 1]) nums[k++] = nums[i];
        return k;
    }
};