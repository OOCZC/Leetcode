class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
	    if(head == null || k <= 1)
		    return head;
	    ListNode temp = new ListNode(0);
		temp.next = head;
		head = temp;
		ListNode first = head.next, tail = head.next;
		while(first != null){
		    for(int i = 0; i < k; ++i){
			    if(tail != null){
				    tail = tail.next;
				}
				else
				    return head.next;
			}
			temp.next = reverse(first, k);
			temp = first;
			first.next = tail;
			first = tail;
		}
	    return head.next;
	}
	
	private ListNode reverse(ListNode head, int k){  // 返回翻转后的头结点
	    if(head == null || k <= 1)
		    return head;
	    ListNode tail = head.next, temp;
		for (int i = 0; i < k - 1; ++i) {
			temp = tail.next;
			tail.next = head;
			head = tail;
			tail = temp;
		}
		return head;
	}

}
