// LeetCode: https://leetcode.cn/problems/container-with-most-water/

// oxygen_code
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = (r - l) * min(height[l], height[r]);

        while (l < r) {
            if (height[l] < height[r]) l++;
            else r--;
            res = max(res, (r - l) * min(height[l], height[r]));
        }
        return res;
    }
};

// octaver_code

