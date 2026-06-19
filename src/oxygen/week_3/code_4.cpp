// LeetCode: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

// oxygen_code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = new ListNode(-1, head);
        ListNode* q = p;
        ListNode* t = p;

        while (n--) {
            q = q->next;
        }

        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }

        p->next = p->next->next;
        return t->next;
    }
};

// octaver_code
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* t = new ListNode(-1, head);
        ListNode* q = t;
        ListNode* p = t;

        while (n--) q = q->next;

        while (q = q->next) p = p->next;

        p->next = p->next->next;
        return t->next;
    }
};
