class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; 

        while (fast && fast->next) {
            prev = slow;        
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) {
            prev->next = nullptr;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (left && right) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) temp->next = left;
        if (right) temp->next = right;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};
