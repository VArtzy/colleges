public class Searching {

    static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    static int binarySearch(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 5, 8, 12, 16, 23, 38, 45, 67, 90};
        int target = 23;

        int linearResult = linearSearch(arr, target);
        System.out.println("LINEAR SEARCH");
        System.out.println("Target: " + target);
        if (linearResult != -1) {
            System.out.println("Found at index: " + linearResult);
        } else {
            System.out.println("Not found");
        }

        int binaryResult = binarySearch(arr, target);
        System.out.println("\nBINARY SEARCH");
        System.out.println("Target: " + target);
        if (binaryResult != -1) {
            System.out.println("Found at index: " + binaryResult);
        } else {
            System.out.println("Not found");
        }
    }
}
