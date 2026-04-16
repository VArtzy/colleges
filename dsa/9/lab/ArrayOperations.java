import java.util.Arrays;

public class ArrayOperations {
    int[] arr;
    int size;

    // Membuat array dengan kapasitas tertentu.
    ArrayOperations(int capacity) {
        arr = new int[capacity];
        size = 0;
    }

    // Menyisipkan nilai pada posisi tertentu.
    void insert(int pos, int val) {
        System.arraycopy(arr, pos, arr, pos + 1, size - pos);
        arr[pos] = val;
        size++;
    }

    // Menghapus nilai pada posisi tertentu.
    void delete(int pos) {
        System.arraycopy(arr, pos + 1, arr, pos, size - pos - 1);
        size--;
    }

    // Mencari nilai secara linear.
    int linearSearch(int val) {
        for (int i = 0; i < size; i++) if (arr[i] == val) return i;
        return -1;
    }

    // Mencari nilai dengan binary search.
    int binarySearch(int val) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == val) return mid;
            else if (arr[mid] < val) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    // Menampilkan isi array.
    void traversal() {
        System.out.println("Array Traversal: " + Arrays.toString(Arrays.copyOf(arr, size)));
    }
}
