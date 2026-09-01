// LeetCode: https://leetcode.cn/problems/palindrome-linked-list/

// oxygen_code
class Solution {
public:
    int a[100010];
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* p = head;
        while(p != nullptr) {
            a[cnt++] = p->val;
            p = p->next;
        }

        for (int l = 0, r = cnt - 1; l < r; l++, r--)
            if(a[l] != a[r])return false;

        return true;
    }
};

// octaver_code
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* q = head;
        ListNode* t = nullptr;

        while (q) {
            ListNode* p = new ListNode(q->val);
            p->next = t;
            t = p;
            q = q->next;
        }

        while (head && t) {
            if (head->val != t->val) return false;
            head = head->next;
            t = t->next;
        }

        return true;
    }
};