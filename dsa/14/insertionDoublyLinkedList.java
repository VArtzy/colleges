class Node {
    int data;
    Node prev, next;
    Node(int d) { data = d; }
}

class DLL {
    Node head;

    void insertFront(int d) {
        Node n = new Node(d);
        n.next = head;
        if (head != null) head.prev = n;
        head = n;
    }

    void insertEnd(int d) {
        Node n = new Node(d);
        if (head == null) { head = n; return; }
        Node t = head;
        while (t.next != null) t = t.next;
        t.next = n;
        n.prev = t;
    }

    void insertAfter(int key, int d) {
        Node t = head;
        while (t != null && t.data != key) t = t.next;
        if (t == null) return;
        Node n = new Node(d);
        n.next = t.next;
        n.prev = t;
        if (t.next != null) t.next.prev = n;
        t.next = n;
    }

    void insertBefore(int key, int d) {
        Node t = head;
        while (t != null && t.data != key) t = t.next;
        if (t == null) return;
        Node n = new Node(d);
        n.prev = t.prev;
        n.next = t;
        if (t.prev != null) t.prev.next = n;
        else head = n;
        t.prev = n;
    }

    void insertAt(int pos, int d) {
        if (pos == 0) { insertFront(d); return; }
        Node t = head;
        for (int i = 0; i < pos - 1 && t != null; i++) t = t.next;
        if (t == null) return;
        Node n = new Node(d);
        n.next = t.next;
        n.prev = t;
        if (t.next != null) t.next.prev = n;
        t.next = n;
    }

    void print() {
        Node t = head;
        while (t != null) {
            System.out.print(t.data + " ");
            t = t.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        DLL l = new DLL();
        l.insertFront(2);
        l.insertFront(1);
        l.insertEnd(4);
        l.insertAfter(2, 3);
        l.insertBefore(1, 0);
        l.insertAt(3, 9);
        l.print();
    }
}
