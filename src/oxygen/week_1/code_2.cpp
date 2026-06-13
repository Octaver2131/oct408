// LeetCode: https://leetcode.cn/problems/XltzEq/description/

// oxygen_code
class Solution {
public:
    bool isPalindrome(string s) {
        const int N = 200010;
        char a[N];
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <='9') a[cnt++] = s[i];
            else if (s[i] >= 'a' && s[i] <= 'z') a[cnt++] = s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z') a[cnt++] = s[i] + 32;
        }

        int l = 0;
        int r = cnt - 1;
        while (l < r) {
            if (a[l] != a[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};

// octaver_code
class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        for (char c : s)
            if (c >= 'A' && c <= 'Z') a += c ^ 32;
            else if (c >= 'a' && c <= 'z')a += c;
            else if (c >= '0' && c <= '9')a += c;

        int l = 0;
        int r = a.size() - 1;
        while (l < r)
            if (a[l++] != a[r--]) return false;

        return true;
    }
};