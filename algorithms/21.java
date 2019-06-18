// class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int val) {
//         this.val = val;
//     }
// }
public class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            if (l1 == null && l2 == null)
                return null;
            if (l1 == null || l2 == null)
                return l1 == null? l2: l1;
            ListNode head = null, tail = null;
            if (l1.val > l2.val) {
                head = tail = l2;
                l2 = l2.next;
                head.next = null;
            }
            else {
                head = tail = l1;
                l1 = l1.next;
                head.next = null;
            }
            while (l1 != null && l2 != null) {
                if (l1.val > l2.val) {
                    tail.next = l2;
                    l2 = l2.next;
                    tail = tail.next;
                    tail.next = null;
                    
                }
                else {
                    tail.next = l1;
                    l1 = l1.next;
                    tail = tail.next;
                    tail.next = null;
                }
            }
            if (l1 == null) {
                tail.next = l2;
            }
            else {
                tail.next = l1;
            }
            return head;
        }
}

