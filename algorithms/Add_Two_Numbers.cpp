/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *l1_temp = l1, *l2_temp = l2, *head ,*head_temp;
        head_temp = head = (ListNode*) malloc(sizeof(ListNode));
        head -> next = NULL;
        while(l1_temp != NULL || l2_temp != NULL){
        // (l1_temp != NULL && l2_temp != NULL) 写法复制
            head_temp -> next = (ListNode*) malloc(sizeof(ListNode));
            head_temp = head_temp -> next;
            head_temp -> next = NULL;
            int x = (l1_temp == NULL) ? 0 : l1_temp -> val;
            int y = (l2_temp == NULL) ? 0 : l2_temp -> val;
            head_temp -> val = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            if(l1_temp != NULL) l1_temp = l1_temp -> next;
            if(l2_temp != NULL) l2_temp = l2_temp -> next;
        }
        // easy to forget
        if(carry){
            head_temp -> next = new ListNode(carry);
        }
        return head -> next;
    }
};
