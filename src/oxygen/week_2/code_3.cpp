// LeetCode: https://leetcode.cn/problems/single-number/description/

// oxygen_code
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int N = 30010;
        int cnt[2 * N] = {0};

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i] + N]++;
        }

        for (int i = 0; i < 2 * N; i++) {
            if (cnt[i] == 1) return i - N;
        }

        return -1;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i; i < nums.size(); i++) res ^= i;
        return res;
    }
};

// octaver_code
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
            if (i + 1 >= nums.size() || nums[i] != nums[i + 1]) return nums[i];

        return -1;
    }
};