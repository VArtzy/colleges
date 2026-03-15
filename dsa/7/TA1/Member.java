// FARREL NIKOSON - 2902704895

public class Member extends User {
    public Member(String nama) {
        super(nama);
    }

    // Jika jumlah lagu 0 maka playlist kosong, jika tidak loop ke array untuk mengeprint info setiap lagu
    public void lihatPlaylist() {
        System.out.println("\n===== DAFTAR PLAYLIST MUSIK =====");
        if (Lagu.getJumlahLagu() == 0) {
            System.out.println("Playlist kosong.");
            return;
        }
        for (int i = 0; i < Lagu.getJumlahLagu(); i++) {
            System.out.print((i + 1) + ". ");
            Lagu.getDaftarLagu()[i].tampilkanInfo();
        }
    }

    // bool ketemu awal false, lalu jika menemukan judul lagu yang sama dengan query, maka tampilkan dan perbarui bool ketemu
    public void cariLagu(String judulCari) {
        boolean ketemu = false;
        for (int i = 0; i < Lagu.getJumlahLagu(); i++) {
            if (Lagu.getDaftarLagu()[i].getJudul().equalsIgnoreCase(judulCari)) {
                System.out.println("\nLagu Ditemukan:");
                Lagu.getDaftarLagu()[i].tampilkanInfo();
                ketemu = true;
                break;
            }
        }
        if (!ketemu) System.out.println("\nLagu '" + judulCari + "' tidak ditemukan.");
    }
}
