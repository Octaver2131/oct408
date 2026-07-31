// LeetCode: https://leetcode.cn/problems/8Zf90G/

// oxygen_code
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int top = -1;
        int stack[10010];

        for (string x : tokens) {
            if (x == "+") {
                int a = stack[top--];
                int b = stack[top--];
                int c = b + a;
                stack[++top] = c;
            } else if (x == "-") {
                int a = stack[top--];
                int b = stack[top--];
                int c = b - a;
                stack[++top] = c;
            } else if (x == "*") {
                int a = stack[top--];
                int b = stack[top--];
                int c = b * a;
                stack[++top] = c;
            } else if (x == "/") {
                int a = stack[top--];
                int b = stack[top--];
                int c = b / a;
                stack[++top] = c;
            } else {
                int c = toInt(x);
                stack[++top] = c;
            }
        }
        return stack[0];
    }

    int toInt(string s) {
        int t = 0;
        int x = 1;
        int start = 0;
        if (s[0] == '-') {
            start = 1;
            x = -1;
        }

        for (int i = start; i < s.size(); i++) {
            t = t * 10;
            t += s[i] - '0';
        }

        return t * x;
    }
};

// octaver_code
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int top = -1;
        int stack[10010];

        for (string x : tokens) {
            if (x == "+") {
                int a = stack[top--];
                int b = stack[top--];
                stack[++top] = b + a;
            } else if (x == "-") {
                int a = stack[top--];
                int b = stack[top--];
                stack[++top] = b - a;
            } else if (x == "*") {
                int a = stack[top--];
                int b = stack[top--];
                stack[++top] = b * a;
            } else if (x == "/") {
                int a = stack[top--];
                int b = stack[top--];
                stack[++top] = b / a;
            } else {
                int c = toInt(x);
                stack[++top] = c;
            }
        }
        return stack[0];
    }

    int toInt(string s) {
        int t = 0;
        int x = 1;
        int start = 0;
        if (s[0] == '-') {
            start = 1;
            x = -1;
        }

        for (int i = start; i < s.size(); i++) {
            t *= 10;
            t += s[i] - '0';
        }

        return t * x;
    }
};