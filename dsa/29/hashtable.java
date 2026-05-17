import java.util.HashMap;

public class Main {
    public static void main(String[] args) {

        // Create HashMap
        HashMap<Integer, String> map = new HashMap<>();

        // Insert data
        map.put(1, "Apple");
        map.put(2, "Banana");
        map.put(3, "Orange");

        // Search data
        System.out.println(map.get(2)); // Banana

        // Delete data
        map.remove(1);

        // Display HashMap
        System.out.println(map);
    }
}
