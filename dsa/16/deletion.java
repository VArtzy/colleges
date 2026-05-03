public class Deletion {

    static int[] deleteElement(int[] arr, int position) {
        int[] newArr = new int[arr.length - 1];

        for (int i = 0; i < position; i++) {
            newArr[i] = arr[i];
        }

        for (int i = position; i < newArr.length; i++) {
            newArr[i] = arr[i + 1];
        }

        return newArr;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int position = 2;

        System.out.println("ARRAY DELETION");

        System.out.print("Before: ");
        for (int x : arr) System.out.print(x + " ");

        System.out.println("\nDeleting element at index " + position + " value: " + arr[position]);

        arr = deleteElement(arr, position);

        System.out.print("After: ");
        for (int x : arr) System.out.print(x + " ");
    }
}
