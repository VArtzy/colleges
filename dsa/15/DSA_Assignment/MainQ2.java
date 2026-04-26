import java.util.Scanner;

class Node {
    String kode, judul, penulis;
    Node next;

    Node(String k, String j, String p) {
        kode = k;
        judul = j;
        penulis = p;
    }
}

class LinkedList {
    Node head;
    int count = 0;

    void tambah(String k, String j, String p) {
        Node baru = new Node(k,j,p);
        if(head == null) head = baru;
        else {
            Node t = head;
            while(t.next != null) t = t.next;
            t.next = baru;
        }
        count++;
    }

    void hapus() {
        if(head == null) System.out.println("Tidak ada data untuk dihapus.");
        else if(head.next == null) head = null;
        else {
            Node t = head;
            while(t.next.next != null) t = t.next;
            t.next = null;
        }
        count--;
    }

    void tampil() {
        Node t = head;
        while(t != null) {
            System.out.println(t.kode+" "+t.judul+" "+t.penulis);
            t = t.next;
        }
        System.out.println("Total: "+count);
    }
}

public class MainQ2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList l = new LinkedList();
        l.tambah("BK1","A","B");
        l.tambah("BK2","C","D");
        l.tampil();
    }
}
