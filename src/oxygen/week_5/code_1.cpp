// LeetCode: https://leetcode.cn/problems/reverse-linked-list/description/

// oxygen_code
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* res = new ListNode(-1, nullptr);
        ListNode* q = head -> next;

        while (head != nullptr) {
            head->next = res->next;
            res->next = head;

            head = q;
            if(q) q = q->next;
        }
        return res->next;
    }
};

// octaver_code

