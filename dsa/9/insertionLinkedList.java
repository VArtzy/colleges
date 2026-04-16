public class LinkedList {
    Node head;

    class Node {
        int data;
        Node next;

        // Membuat node baru.
        Node(int d) { data = d; next = null; }
    }

    // Menambah node di awal list.
    void insertHead(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Menambah node di akhir list.
    void insertTail(int data) {
        Node newNode = new Node(data);
        if (head == null) { head = newNode; return; }
        Node curr = head;
        while (curr.next != null) curr = curr.next;
        curr.next = newNode;
    }

    // Menambah node pada posisi tertentu.
    void insertMiddle(int data, int pos) {
        Node newNode = new Node(data);
        if (pos == 0) { newNode.next = head; head = newNode; return; }
        Node curr = head;
        for (int i = 0; curr != null && i < pos - 1; i++) curr = curr.next;
        if (curr == null) return;
        newNode.next = curr.next;
        curr.next = newNode;
    }

    // Menampilkan isi list.
    void print() {
        Node curr = head;
        while (curr != null) { System.out.print(curr.data + " "); curr = curr.next; }
        System.out.println();
    }

    // Menjalankan contoh operasi penyisipan linked list.
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insertTail(2);
        list.insertTail(4);
        list.insertTail(5);
        System.out.print("Initial       : "); list.print();

        list.insertHead(1);
        System.out.print("Insert Head(1): "); list.print();

        list.insertTail(6);
        System.out.print("Insert Tail(6): "); list.print();

        list.insertMiddle(3, 2);
        System.out.print("Insert Mid(3) : "); list.print();
    }
}
