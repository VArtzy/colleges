import java.util.*;

public class ArrayListOperations {
    ArrayList<Integer> list = new ArrayList<>();

    // Menambah nilai pada posisi tertentu.
    void add(int pos, int val) { list.add(pos, val); }

    // Menghapus nilai pada posisi tertentu.
    void delete(int pos) { list.remove(pos); }

    // Mencari indeks dari nilai tertentu.
    int search(int val) { return list.indexOf(val); }

    // Mengurutkan isi list.
    void sort() { Collections.sort(list); }

    // Menampilkan isi list.
    void traversal() { System.out.println("ArrayList Traversal: " + list); }
}
