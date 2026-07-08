// LeetCode: https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/

// oxygen_code
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        char stack[100010];
        int top = -1;
        for (int i = 0; i < n; i++) {
            if (top == -1) stack[++top] = s[i];
            else if (stack[top] != s[i]) stack[++top] = s[i];
            else --top;
        }

        string res = "";
        for (int i = 0; i <= top; i ++) {
            res += stack[i];
        }
        return res;
    }
};

// octaver_code
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto c: s) {
            if (!res.empty() && res.back() == c) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};
