class Node {
    int data;
    Node prev, next;
    Node(int d) { data = d; }
}

class DLL {
    Node head;

    void push(int d) {
        Node n = new Node(d);
        n.next = head;
        if (head != null) head.prev = n;
        head = n;
    }

    void deleteBegin() {
        if (head == null) return;
        head = head.next;
        if (head != null) head.prev = null;
    }

    void deleteEnd() {
        if (head == null) return;
        Node t = head;
        while (t.next != null) t = t.next;
        if (t.prev != null) t.prev.next = null;
        else head = null;
    }

    void deleteAt(int pos) {
        if (head == null) return;
        Node t = head;
        for (int i = 0; i < pos && t != null; i++) t = t.next;
        if (t == null) return;
        if (t.prev != null) t.prev.next = t.next;
        else head = t.next;
        if (t.next != null) t.next.prev = t.prev;
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
        l.push(3); l.push(2); l.push(1); l.push(0);
        l.print();
        l.deleteBegin();
        l.print();
        l.deleteEnd();
        l.print();
        l.deleteAt(1);
        l.print();
    }
}
