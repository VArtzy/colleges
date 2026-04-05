/*
 * TUGAS KELOMPOK - PLAYLIST ARRAY
 * Anggota Kelompok:
 * 1. FARREL NIKOSON - 2902704895
 * 2. ASYSYIFA ISHARUL JANNAH - 2902704251
 * 3. MARVELL DARREN - 2902704251
 * 4. ANDRE WIJAYA - 2902704850
 * 5. RAYNARD MARVELLIN - 2902693191
 */

import java.util.Scanner;

// Class Lagu untuk menyimpan detail lagu
class Lagu {
    private String judul;
    private String artis;
    private double durasi;

    public Lagu(String judul, String artis, double durasi) {
        this.judul = judul;
        this.artis = artis;
        this.durasi = durasi;
    }

    public String getJudul() {
        return judul;
    }

    public String getArtis() {
        return artis;
    }

    public double getDurasi() {
        return durasi;
    }

    public void tampilkanInfo() {
        System.out.println("Judul: " + judul + " | Artis: " + artis + " | Durasi: " + durasi + " menit");
    }
}

// Class PlaylistArray untuk menyimpan detail lagu lagu yang dimasukkan pengguna
public class PlaylistArray {
    private Lagu[] playlist;
    private int jumlahLagu; // Menandai posisi index saat ini

    public PlaylistArray() {
        this.playlist = new Lagu[10]; // Kapasitas maksimum 10
        this.jumlahLagu = 0;
    }

    // Untuk menampilkan lagu yang ada di playlist dan sudah mengurutkan berdasarkan durasi
    public void tampilkanSemuaLagu() {
        // Panggil fungsi sorting 
        urutkanLaguBerdasarkanDurasi();

        System.out.println("\n=== DAFTAR PLAYLIST (Terurut Berdasarkan Durasi) ===");
        if (jumlahLagu == 0) {
            System.out.println("Playlist kosong.");
        } else {
            for (int i = 0; i < jumlahLagu; i++) {
                System.out.print((i + 1) + ". ");
                playlist[i].tampilkanInfo();
            }
        }
    }

    // penyisipan yang berfungsi untuk menambahkan lagu
    public void tambahLagu(Scanner input) {
        if (jumlahLagu >= 10) {
            System.out.println("\n[Gagal] Playlist sudah penuh! Maksimal hanya 10 lagu."); //memberikan notifikasi bahwa lagu yang berada di playlist sudah maksimal
            return;
        }

        System.out.println("\n--- Tambah Lagu Baru ---");
        System.out.print("Masukkan Judul Lagu : ");
        String judul = input.nextLine();
        System.out.print("Masukkan Nama Artis : ");
        String artis = input.nextLine();
        System.out.print("Masukkan Durasi (menit) : ");
        double durasi = input.nextDouble();
        input.nextLine(); // Membersihkan buffer

        Lagu laguBaru = new Lagu(judul, artis, durasi);
        playlist[jumlahLagu] = laguBaru;
        jumlahLagu++;

        System.out.println("[Berhasil] Lagu '" + judul + "' telah ditambahkan.");
    }

    // Deletion (penghapusan) untuk menghapus lagu pada playlist
    public void hapusLagu(Scanner input) {
        System.out.print("\nMasukkan judul lagu yang ingin dihapus :");
        String judul = input.nextLine();
        int index = -1;

        // Cari index lagu (Linear Search)
        for (int i = 0; i < jumlahLagu; i++) {
            if (playlist[i].getJudul().equalsIgnoreCase(judul)) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            System.out.println("[Gagal] Lagu tidak ditemukan!");
            return;
        }

        // Geser array ke kiri untuk menjaga kerapatan data
        for (int i = index; i < jumlahLagu - 1; i++) {
            playlist[i] = playlist[i + 1];
        }

        playlist[jumlahLagu - 1] = null; // Mengosongkan index terakhir
        jumlahLagu--; // Mengurangi counter jumlah lagu

        System.out.println("[Berhasil] Lagu '" + judul + "' berhasil dihapus.");
    }

    // Helper: sort playlist alphabetically by judul (for binary search)
    private void urutkanBerdasarkanJudul() {
        for (int i = 0; i < jumlahLagu - 1; i++) {
            for (int j = 0; j < jumlahLagu - i - 1; j++) {
                if (playlist[j].getJudul().compareToIgnoreCase(playlist[j + 1].getJudul()) > 0) {
                    Lagu temp        = playlist[j];
                    playlist[j]      = playlist[j + 1];
                    playlist[j + 1]  = temp;
                }
            }
        }
    }

    // Method untuk melakukan pencaharian
    public void cariLagu(Scanner input) {
        System.out.print("\nMasukkan judul lagu yang dicari : ");
        String judulCari = input.nextLine().trim();

        urutkanBerdasarkanJudul();

        int left  = 0;
        int right = jumlahLagu - 1;
        int hasil = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = playlist[mid].getJudul().compareToIgnoreCase(judulCari);

            if (cmp == 0) {
                hasil = mid;   // found
                break;
            } else if (cmp < 0) {
                left = mid + 1;  // search right half
            } else {
                right = mid - 1; // search left half
            }
        }

        if (hasil != -1) {
            System.out.println("\n[Lagu Ditemukan]:");
            playlist[hasil].tampilkanInfo();
        } else {
            System.out.println("Lagu tidak ditemukan.");
        }
    }

    // Method untuk mengurutkan lagu berdasarkan durasi
    public void urutkanLaguBerdasarkanDurasi() {
        if (jumlahLagu <= 1) {
            return;
        }

        for (int i = 0; i < jumlahLagu - 1; i++) {
            for (int j = 0; j < jumlahLagu - i - 1; j++) {
                if (playlist[j].getDurasi() > playlist[j + 1].getDurasi()) {
                    Lagu temp = playlist[j];
                    playlist[j] = playlist[j + 1];
                    playlist[j + 1] = temp;
                }
            }
        }
    }

    // Method utama
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        PlaylistArray app = new PlaylistArray();
        int pilihan;

        do {
            System.out.println("\n=== MENU PLAYLIST MUSIK ===");
            System.out.println("1. Tampilkan semua lagu");
            System.out.println("2. Tambah lagu baru");
            System.out.println("3. Hapus lagu berdasarkan judul");
            System.out.println("4. Cari lagu berdasarkan judul");
            System.out.println("5. Keluar");
            System.out.print("Pilih menu: ");

            pilihan = input.nextInt();
            input.nextLine(); // Membersihkan buffer newline

            switch (pilihan) {
                case 1:
                    app.tampilkanSemuaLagu();
                    break;
                case 2:
                    app.tambahLagu(input);
                    break;
                case 3:
                    app.hapusLagu(input);
                    break;
                case 4:
                    app.cariLagu(input);
                    break;
                case 5:
                    System.out.println("Terima kasih! Program selesai.");
                    break;
                default:
                    System.out.println("Pilihan tidak tersedia.");
            }
        } while (pilihan != 5);

        input.close();
    }
}
