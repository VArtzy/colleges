public class CircularLinkedList {
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
        if (head == null) { head = newNode; newNode.next = head; return; }
        Node curr = head;
        while (curr.next != head) curr = curr.next;
        newNode.next = head;
        head = newNode;
        curr.next = head;
    }

    // Menambah node di akhir list.
    void insertTail(int data) {
        Node newNode = new Node(data);
        if (head == null) { head = newNode; newNode.next = head; return; }
        Node curr = head;
        while (curr.next != head) curr = curr.next;
        curr.next = newNode;
        newNode.next = head;
    }

    // Menambah node pada posisi tertentu.
    void insertMiddle(int data, int pos) {
        Node newNode = new Node(data);
        if (pos == 0) { insertHead(data); return; }
        Node curr = head;
        for (int i = 0; i < pos - 1; i++) curr = curr.next;
        newNode.next = curr.next;
        curr.next = newNode;
    }

    // Menghapus node pertama.
    void deleteFirst() {
        if (head == null) return;
        if (head.next == head) { head = null; return; }
        Node curr = head;
        while (curr.next != head) curr = curr.next;
        head = head.next;
        curr.next = head;
    }

    // Menghapus node terakhir.
    void deleteLast() {
        if (head == null) return;
        if (head.next == head) { head = null; return; }
        Node curr = head;
        while (curr.next.next != head) curr = curr.next;
        curr.next = head;
    }

    // Menghapus node pada posisi tertentu.
    void deleteMiddle(int pos) {
        if (head == null) return;
        if (pos == 0) { deleteFirst(); return; }
        Node curr = head;
        for (int i = 0; i < pos - 1; i++) curr = curr.next;
        curr.next = curr.next.next;
    }

    // Menampilkan isi list.
    void print() {
        if (head == null) return;
        Node curr = head;
        do { System.out.print(curr.data + " "); curr = curr.next; } while (curr != head);
        System.out.println("(back to head: " + head.data + ")");
    }

    // Menjalankan contoh operasi circular linked list.
    public static void main(String[] args) {
        CircularLinkedList list = new CircularLinkedList();

        list.insertTail(2);
        list.insertTail(4);
        list.insertTail(5);
        System.out.print("Initial         : "); list.print();

        list.insertHead(1);
        System.out.print("Insert Head(1)  : "); list.print();

        list.insertTail(6);
        System.out.print("Insert Tail(6)  : "); list.print();

        list.insertMiddle(3, 2);
        System.out.print("Insert Middle(3): "); list.print();

        list.deleteFirst();
        System.out.print("Delete First    : "); list.print();

        list.deleteMiddle(1);
        System.out.print("Delete Middle   : "); list.print();

        list.deleteLast();
        System.out.print("Delete Last     : "); list.print();
    }
}
