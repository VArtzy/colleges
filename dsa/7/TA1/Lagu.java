package TA1;

public class Lagu {
    private String judul;
    private String artis;
    private double durasi;

    // Database lagu terpusat
    private static Lagu[] daftarLagu = new Lagu[20];
    private static int jumlahLagu = 0;

    // Static Block untuk menyimpan 5 data lagu awal secara otomatis
    static {
        simpanLagu(new Lagu("Bohemian Rhapsody", "Queen", 5.9));
        simpanLagu(new Lagu("Yellow", "Coldplay", 4.5));
        simpanLagu(new Lagu("Hati-Hati di Jalan", "Tulus", 4.0));
        simpanLagu(new Lagu("Perfect", "Ed Sheeran", 4.2));
        simpanLagu(new Lagu("Monokrom", "Tulus", 3.4));
    }

    public Lagu(String judul, String artis, double durasi) {
        this.judul = judul;
        this.artis = artis;
        this.durasi = durasi;
    }

    public static void simpanLagu(Lagu laguBaru) {
        if (jumlahLagu < daftarLagu.length) {
            daftarLagu[jumlahLagu] = laguBaru;
            jumlahLagu++;
        }
    }

    public static Lagu[] getDaftarLagu() { return daftarLagu; }
    public static int getJumlahLagu() { return jumlahLagu; }

    public String getJudul() { return judul; }
    public String getArtis() { return artis; }
    public double getDurasi() { return durasi; }

    public void tampilkanInfo() {
        System.out.printf("Judul: %-20s | Artis: %-15s | Durasi: %.2f menit%n", judul, artis, durasi);
    }
}