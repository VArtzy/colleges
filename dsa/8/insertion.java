public class Insertion {

    static int[] insertElement(int[] arr, int element, int position) {
        int[] newArr = new int[arr.length + 1];

        for (int i = 0; i < position; i++) {
            newArr[i] = arr[i];
        }

        newArr[position] = element;

        for (int i = position; i < arr.length; i++) {
            newArr[i + 1] = arr[i];
        }

        return newArr;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int element = 25;
        int position = 2;

        System.out.println("ARRAY INSERTION");

        System.out.print("Before: ");
        for (int x : arr) System.out.print(x + " ");

        arr = insertElement(arr, element, position);

        System.out.print("\nAfter inserting " + element + " at index " + position + ": ");
        for (int x : arr) System.out.print(x + " ");
    }
}
