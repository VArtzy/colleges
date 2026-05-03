// FARREL NIKOSON totalDurasi() (FILE TAMBAHAN PROGRAM KEMARIN)
public class PlaylistRekursif {

    public static double totalDurasi(Lagu[] list, int n) {
        if (list == null || n <= 0) {
            return 0;
        }

        return totalDurasi(list, n - 1) + list[n - 1].getDurasi();
    }

    public static void main(String[] args) {
        Lagu[] playlist = {
            new Lagu("Perfect", "Ed Sheeran", 4.23),
            new Lagu("Shivers", "Ed Sheeran", 3.50),
            new Lagu("Fix You", "Coldplay", 4.52),
            new Lagu("Yellow", "Coldplay", 3.58),
            new Lagu("Viva La Vida", "Coldplay", 4.52)
        };

        long startTime = System.nanoTime();
        double total = totalDurasi(playlist, playlist.length);
        long endTime = System.nanoTime();

        double executionTimeMs = (endTime - startTime) / 1_000_000.0;

        System.out.println("=== ANALISIS REKURSIF PLAYLIST ===");
        System.out.println("Jumlah lagu : " + playlist.length);
        System.out.printf("Total durasi : %.2f menit%n", total);
        System.out.printf("Execution Time (totalDurasi): %.3f ms%n", executionTimeMs);
    }
}
