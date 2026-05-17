import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        HashMap<String, String> mahasiswa = new HashMap<>();
        mahasiswa.put("231001", "Andi - IPK 3.75");
        mahasiswa.put("231002", "Budi - IPK 3.62");
        mahasiswa.put("231003", "Citra - IPK 3.88");
        mahasiswa.put("231004", "Dewi - IPK 3.54");
        mahasiswa.put("231005", "Eka - IPK 3.43");

        HashMap<String, ArrayList<String>> graph = new HashMap<>();
        graph.put("A", new ArrayList<>());
        graph.put("B", new ArrayList<>());
        graph.put("C", new ArrayList<>());
        graph.put("D", new ArrayList<>());

        graph.get("A").add("B");
        graph.get("A").add("C");
        graph.get("B").add("A");
        graph.get("B").add("D");
        graph.get("C").add("A");
        graph.get("C").add("D");
        graph.get("D").add("B");
        graph.get("D").add("C");

        System.out.println("=== STRUKTUR DATA AWAL PROYEK ===");
        System.out.println("Jumlah data mahasiswa: " + mahasiswa.size());
        System.out.println("Jumlah node graph: " + graph.size());

        System.out.println("\nData Mahasiswa Awal:");
        for (Map.Entry<String, String> entry : mahasiswa.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }

        System.out.println("\nData Rute Awal:");
        for (Map.Entry<String, ArrayList<String>> entry : graph.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}
