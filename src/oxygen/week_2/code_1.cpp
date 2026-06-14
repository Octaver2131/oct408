// LeetCode: https://leetcode.cn/problems/valid-parentheses/description/

// oxygen_code
class Solution {
public:
    bool isValid(string s) {
        char stack[10010];
        int top = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack[++top] = s[i];
            } else {
                if (s[i] == ')' && stack[top] == '(') top--;
                else if (s[i] == ']' && stack[top] == '[') top--;
                else if (s[i] == '}' && stack[top] == '{') top--;
                else return false;
            }
        }

        if (top == 0) return true;
        return false;
    }
};

// octaver_code
const int N = 10010;
char stk[N];

class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk[++top] = c;
            } else {
                if (c == ')' && stk[top] == '(') top--;
                else if (c == ']' && stk[top] == '[') top--;
                else if (c == '}' && stk[top] == '{') top--;
                else return false;
            }
        }

        return top == 0;
    }
};