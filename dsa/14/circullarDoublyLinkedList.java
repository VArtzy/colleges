class Node {
    int data;
    Node prev, next;
    Node(int d) { data = d; }
}

class CDLL {
    Node head;

    void insert(int d) {
        Node n = new Node(d);
        if (head == null) {
            n.next = n;
            n.prev = n;
            head = n;
            return;
        }
        Node last = head.prev;
        last.next = n;
        n.prev = last;
        n.next = head;
        head.prev = n;
    }

    void delete(int key) {
        if (head == null) return;
        Node t = head;
        do {
            if (t.data == key) {
                if (t.next == t) {
                    head = null;
                    return;
                }
                t.prev.next = t.next;
                t.next.prev = t.prev;
                if (t == head) head = t.next;
                return;
            }
            t = t.next;
        } while (t != head);
    }

    void print() {
        if (head == null) return;
        Node t = head;
        do {
            System.out.print(t.data + " ");
            t = t.next;
        } while (t != head);
        System.out.println();
    }

    public static void main(String[] args) {
        CDLL l = new CDLL();
        l.insert(1);
        l.insert(2);
        l.insert(3);
        l.insert(4);
        l.print();
        l.delete(3);
        l.print();
    }
}
