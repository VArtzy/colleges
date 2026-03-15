package TA1;

public class Admin extends User {
    private static final String ADMIN_USER = "admin123";
    private static final String ADMIN_PASS = "passwordadmin";

    public Admin(String nama) {
        super(nama);
    }

    public static boolean autentikasi(String user, String pass) {
        return ADMIN_USER.equals(user) && ADMIN_PASS.equals(pass);
    }

    public void lihatPlaylistAdmin() {
        System.out.println("\n--- DAFTAR PLAYLIST SAAT INI (ADMIN) ---");
        for (int i = 0; i < Lagu.getJumlahLagu(); i++) {
            System.out.print((i + 1) + ". ");
            Lagu.getDaftarLagu()[i].tampilkanInfo();
        }
    }

    public void tambahLagu(String judul, String artis, double durasi) {
        Lagu laguBaru = new Lagu(judul, artis, durasi);
        Lagu.simpanLagu(laguBaru);
        System.out.println("\n[Sistem] Lagu berhasil ditambahkan!");
        lihatPlaylistAdmin(); // Tampilkan update otomatis
    }
}