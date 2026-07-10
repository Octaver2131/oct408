// LeetCode: https://leetcode.cn/problems/find-the-degree-of-each-vertex/

// oxygen_code
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) sum++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
// octaver_code

