class LRUCache {

    class Node {

        public Node pre;
        public Node next;
        public int key;
        public int value;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private int capacity;
    private Node head, tail;
    private HashMap<Integer, Node> hashmap;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        hashmap = new HashMap<Integer, Node>(capacity);
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head.next = tail;
        tail.pre = head;
    }

    private void unLink(Node node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }
 
    private void appendHead(Node node) {
        node.next = head.next;
        node.pre = head;
        head.next = node;
        node.next.pre = node;
    }

    public int get(int key) {
        if (hashmap.containsKey(key)) {
            Node node = hashmap.get(key);
            unLink(node);
            appendHead(node);
            return node.value;
        }
        return -1;
    }

    // need update feature
    public void put(int key, int value) {
        Node node;
        if (hashmap.containsKey(key)) {
            node = hashmap.get(key);
            node.value = value;
            unLink(node);
        }
        else if (hashmap.size() < capacity) {
            node = new Node(key, value);
            hashmap.put(key, node);
        }
        else {
            node = tail.pre;
            hashmap.remove(node.key);
            unLink(node);
            node.key = key;
            node.value = value;
            hashmap.put(key, node);
        }
        appendHead(node);
    }

}
