// LeetCode: https://leetcode.cn/problems/linked-list-cycle/description/

// oxygen_code
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if (head == NULL) return false;

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;

            if (fast->next) fast = fast->next;
            else return false;

            if (fast == slow) return true;
        }
        return false;
    }
};

// octaver_code
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if (head == NULL) return false;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;

            if (fast->next) fast = fast->next;
            else return false;

            if (fast == slow) return true;
        }
        return false;
    }
};