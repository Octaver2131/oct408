// LeetCode: https://leetcode.cn/problems/number-of-provinces/

// oxygen_code
class Solution {
public:
    int root[210];

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        for (int i = 0; i < g.size(); i++) root[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j]) {
                    int a = find(i);
                    int b = find(j);
                    if (a != b) root[a] = b;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (root[i] == i) cnt++;
        }

        return cnt;
    }
};

// octaver_code
class Solution {
public:
    int root[210];

    int find(int x) {
        return root[x] == x ? x: find(root[x]);
    }

    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        for (int i = 0; i < g.size(); i++) root[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (g[i][j]) {
                    int a = find(i);
                    int b = find(j);
                    if (a != b) root[a] = b;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (root[i] == i) cnt++;
        }

        return cnt;
    }
};