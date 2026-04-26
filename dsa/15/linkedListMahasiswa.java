import java.util.Scanner;

class Node {
    String nama;
    int nilai;
    Node next;

    Node(String nama, int nilai) {
        this.nama = nama;
        this.nilai = nilai;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    void tambah(String nama, int nilai) {
        Node baru = new Node(nama, nilai);
        if (head == null) head = baru;
        else {
            Node temp = head;
            while (temp.next != null) temp = temp.next;
            temp.next = baru;
        }
    }

    void hapus(String nama) {
        if (head == null) return;

        if (head.nama.equals(nama)) {
            head = head.next;
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            if (temp.next.nama.equals(nama)) {
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
    }

    void update(String nama, int nilaiBaru) {
        Node temp = head;
        while (temp != null) {
            if (temp.nama.equals(nama)) {
                temp.nilai = nilaiBaru;
                return;
            }
            temp = temp.next;
        }
    }

    void tampil() {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.nama + " - " + temp.nilai);
            temp = temp.next;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList list = new LinkedList();

        int pilih;
        do {
            System.out.println("1.Tambah 2.Hapus 3.Update 4.Tampil 5.Keluar");
            pilih = sc.nextInt(); sc.nextLine();

            if (pilih == 1) {
                System.out.print("Nama: ");
                String nama = sc.nextLine();
                System.out.print("Nilai: ");
                int nilai = sc.nextInt(); sc.nextLine();
                list.tambah(nama, nilai);
            } 
            else if (pilih == 2) {
                System.out.print("Nama: ");
                list.hapus(sc.nextLine());
            } 
            else if (pilih == 3) {
                System.out.print("Nama: ");
                String nama = sc.nextLine();
                System.out.print("Nilai baru: ");
                int n = sc.nextInt(); sc.nextLine();
                list.update(nama, n);
            } 
            else if (pilih == 4) {
                list.tampil();
            }

        } while (pilih != 5);
    }
}
