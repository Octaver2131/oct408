// LeetCode: https://leetcode.cn/problems/course-schedule/

// oxygen_code
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& need) {
        int g[2010][2010] = {0};
        int q[2010] = {0};
        int in[2010] = {0};
        int front = 0;
        int rear = 0;

        int row = need.size();
        for (int i = 0; i < row; i++) {
            int a = need[i][0];
            int b = need[i][1];
            g[b][a] = 1;
            in[a]++;
        }

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q[rear++] = i;
        }

        while (front < rear) {
            int t = q[front++];
            for (int i = 0; i < n; i++) {
                if (g[t][i] == 1) {
                    in[i]--;
                    if (in[i] == 0) q[rear++] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (in[i] != 0) return false;
        }

        return true;
    }
};

// octaver_code
