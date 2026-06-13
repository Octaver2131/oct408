// LeetCode: https://leetcode.cn/problems/merge-two-sorted-lists/

// oxygen_code
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(-1, nullptr);
        ListNode* tail = res;
        ListNode* p = list1;
        ListNode* q = list2;

        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                tail->next = p;
                tail = tail->next;
                p = p->next;
                tail->next = nullptr;
            } else {
                tail->next = q;
                tail = tail->next;
                q = q->next;
                tail->next = nullptr;
            }
        }

        if(p) tail->next = p;
        if(q) tail->next = q;

        return res->next;
    }
};

// octaver_code
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(-1, nullptr);
        ListNode* tail = res;
        ListNode* p = list1;
        ListNode* q = list2;

        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            } else {
                tail->next = q;
                q = q->next;
            }
            tail = tail->next;
        }

        if(p) tail->next = p;
        if(q) tail->next = q;

        return res->next;
    }
};