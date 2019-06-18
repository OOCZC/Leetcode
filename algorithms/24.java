/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
	public ListNode swapPairs(ListNode head) {
	    if(head == null || head.next == null)
		    return head;
	    ListNode first = head, second = head.next, temp;
		temp = new ListNode(0);
		temp.next = head;
		head = temp;
	    while(first != null) {
		    if (first.next == null)
			    break;
			second = first.next;
			temp.next = second;
			first.next = second.next;
			second.next = first;
			temp = first;
			first = temp.next;
		}
		return head.next;
	}

}
