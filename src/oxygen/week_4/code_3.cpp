// LeetCode: https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/

// oxygen_code
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        k = k - 1;
        while (k--) {
            q = q->next;
        }

        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        return p->val;
    }
};

// octaver_code

