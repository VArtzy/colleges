import java.util.Arrays;

public class Comparison {
    static final int SIZE = 1000;

    // Membandingkan operasi array dan ArrayList.
    public static void main(String[] args) {
        ArrayOperations arrOps = new ArrayOperations(SIZE + 10);
        ArrayListOperations alOps = new ArrayListOperations();

        int[] baseData = {10, 20, 30, 40, 50};
        for (int val : baseData) {
            arrOps.arr[arrOps.size++] = val;
            alOps.list.add(val);
        }

        arrOps.traversal();
        alOps.traversal();
        System.out.println();

        System.out.println("Pencarian 30 dalam Array: Ditemukan di indeks " + arrOps.linearSearch(30));
        System.out.println("Pencarian 30 dalam ArrayList: Ditemukan di indeks " + alOps.search(30));
        System.out.println();

        arrOps.insert(2, 25);
        alOps.add(2, 25);
        System.out.println("Array setelah penyisipan 25: " + Arrays.toString(Arrays.copyOf(arrOps.arr, arrOps.size)));
        System.out.println("ArrayList setelah penyisipan 25: " + alOps.list);
        System.out.println();

        arrOps.delete(2);
        alOps.delete(2);
        System.out.println("Array setelah penghapusan indeks 2: " + Arrays.toString(Arrays.copyOf(arrOps.arr, arrOps.size)));
        System.out.println("ArrayList setelah penghapusan indeks 2: " + alOps.list);
        System.out.println();

        ArrayOperations bigArr = new ArrayOperations(SIZE + 10);
        ArrayListOperations bigAl = new ArrayListOperations();
        for (int i = 0; i < SIZE; i++) { bigArr.arr[bigArr.size++] = i; bigAl.list.add(i); }

        long t1 = System.nanoTime();
        bigArr.linearSearch(999);
        long t2 = System.nanoTime();
        bigAl.search(999);
        long t3 = System.nanoTime();

        long t4 = System.nanoTime();
        bigArr.insert(500, 777);
        long t5 = System.nanoTime();
        bigAl.add(500, 777);
        long t6 = System.nanoTime();

        long t7 = System.nanoTime();
        bigArr.delete(500);
        long t8 = System.nanoTime();
        bigAl.delete(500);
        long t9 = System.nanoTime();

        System.out.println(" Operasi          Array (ms)      ArrayList (ms) ");
        System.out.printf(" Pencarian         %-14.4f  %-14.4f %n", (t2-t1)/1e6, (t3-t2)/1e6);
        System.out.printf(" Penyisipan        %-14.4f  %-14.4f %n", (t5-t4)/1e6, (t6-t5)/1e6);
        System.out.printf(" Penghapusan       %-14.4f  %-14.4f %n", (t8-t7)/1e6, (t9-t8)/1e6);
    }
}
