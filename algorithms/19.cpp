class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || n <= 0)
            return nullptr;
        ListNode *first, *second, *temp;
        int count = n;
        for (first = head; first -> next != nullptr && count > 0; --count) {
            first = first -> next;
        }
        if (count > 1)
            return nullptr;
        if (count == 1) {
            temp = head;
            head = head -> next;
            delete temp;
        }
        else {
            for (second = head; first -> next != nullptr;) {
                second = second -> next;
                first = first -> next;
            }
            temp = second -> next;
            second -> next = temp -> next;
            delete temp;
        }
        return head;
    }

};
