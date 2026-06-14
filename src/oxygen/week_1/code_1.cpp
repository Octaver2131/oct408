// LeetCode: https://leetcode.cn/problems/palindrome-number/description/

// oxygen_code
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x == 0) return true;
        else {
            long long res = 0;
            int t = x;
            while (x) {
                res = res * 10;
                res = res + x % 10;
                x = x / 10;
            }
            if (res == t) return true;
            return false;
        }
    }
};

// octaver_code
class Solution {
public:
    using ll = long long;

    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x == 0) return true;
        else {
            ll res = 0;
            int t = x;
            while (x) {
                res *= 10;
                res += x % 10;
                x /= 10;
            }
            return res == t;
        }
    }
};

