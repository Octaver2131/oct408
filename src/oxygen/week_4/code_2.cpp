// LeetCode: https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

// oxygen_code
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int l = 0;
        int r = n - 1;

        vector<int> res;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] == target) r = mid;
            else l = mid + 1;
        }

        if (nums[l] != target) return {-1, -1};

        res.push_back(l);

        l = 0;
        r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] == target) l = mid;
            else l = mid + 1;
        }

        res.push_back(r);
        return res;
    }
};

// octaver_code
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        int l = 0, r = n - 1;
        return {findL(nums, target, l, r), findR(nums, target, l, r)};
    }

    int findL(vector<int>& nums, int target, int l, int r) {
        int res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target) {
                if (nums[mid] == target) res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }


    int findR(vector<int>& nums, int target, int l, int r) {
        int res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] <= target)
            {
                if (nums[mid] == target) res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};
