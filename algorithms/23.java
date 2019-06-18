class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
	    if(lists == null || lists.length == 0)
		    return null;
	    int len = lists.length;
		PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(len, (x, y) -> x.val - y.val);
		ListNode head, tail;
		head = tail = new ListNode(0);
		for(ListNode node: lists) {
		    if(node != null)
		        pq.add(node);
		}
		while(pq.size() > 0) {
		    ListNode n = pq.poll();
			if(n.next != null){
			    pq.add(n.next);
			}
			tail.next = n;
			n.next = null;
			tail = tail.next;
		}
		return head.next;
	}
}
