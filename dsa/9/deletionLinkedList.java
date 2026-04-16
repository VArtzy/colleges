public class LinkedList {
    Node head;

    class Node {
        int data;
        Node next;

        // Membuat node baru.
        Node(int d) { data = d; next = null; }
    }

    // Menambah node di akhir list.
    void append(int data) {
        Node newNode = new Node(data);
        if (head == null) { head = newNode; return; }
        Node last = head;
        while (last.next != null) last = last.next;
        last.next = newNode;
    }

    // Menghapus node pertama.
    void deleteFirst() {
        if (head == null) return;
        head = head.next;
    }

    // Menghapus node pada posisi tertentu.
    void deleteMiddle(int pos) {
        if (head == null) return;
        if (pos == 0) { head = head.next; return; }
        Node curr = head;
        for (int i = 0; curr != null && i < pos - 1; i++) curr = curr.next;
        if (curr == null || curr.next == null) return;
        curr.next = curr.next.next;
    }

    // Menghapus node terakhir.
    void deleteLast() {
        if (head == null) return;
        if (head.next == null) { head = null; return; }
        Node curr = head;
        while (curr.next.next != null) curr = curr.next;
        curr.next = null;
    }

    // Menampilkan isi list.
    void print() {
        Node curr = head;
        while (curr != null) { System.out.print(curr.data + " "); curr = curr.next; }
        System.out.println();
    }

    // Menjalankan contoh operasi penghapusan linked list.
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);

        System.out.print("Original  : "); list.print();

        list.deleteFirst();
        System.out.print("Del First : "); list.print();

        list.deleteMiddle(1);
        System.out.print("Del Middle: "); list.print();

        list.deleteLast();
        System.out.print("Del Last  : "); list.print();
    }
}
