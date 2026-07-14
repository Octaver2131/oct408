// LeetCode: https://leetcode.cn/problems/intersection-of-two-linked-lists/

// oxygen_code

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode *q = headA;
        ListNode *p = headB;

        while (q != nullptr) {
            len1 ++;
            q = q->next;
        }
        while (p != nullptr) {
            len2 ++;
            p = p->next;
        }

        q = headA;
        p = headB;

        if (len1 > len2) {
            int k = len1 - len2;
            while (k--) {
                q = q->next;
            }
        }
        if (len2 > len1) {
            int k = len2 - len1;
            while (k--) {
                p = p->next;
            }
        }

        while (q != p && q != nullptr && p != nullptr) {
            q = q->next;
            p = p->next;
        }
        return q;
    }
};
// octaver_code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode *q = headA;
        ListNode *p = headB;

        while ((q = q->next)) len1 ++;
        while ((p = p->next)) len2 ++;

        q = headA;
        p = headB;

        int k = abs(len1 - len2);
        if (len1 > len2)
            while (k--) q = q->next;

        if (len2 > len1)
            while (k--) p = p->next;

        while (q != p && (q = q->next) && (p = p->next));

        return q;
    }
};
