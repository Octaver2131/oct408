// LeetCode: https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/

// oxygen_code
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = 1e5 + 10;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > n) {
                int t = nums[i] % n;
                nums[t - 1] += n;
            } else {
                if (nums[nums[i] - 1] <= n) {
                    nums[nums[i] - 1] += n;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 1 && nums[i] <= n) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

// octaver_code

