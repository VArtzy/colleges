package TA1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("====================================");
        System.out.println("    SISTEM MANAJEMEN PLAYLIST       ");
        System.out.println("====================================");
        System.out.print("Username: "); String uIn = sc.nextLine();
        System.out.print("Password: "); String pIn = sc.nextLine();

        if (Admin.autentikasi(uIn, pIn)) {
            Admin admin = new Admin(uIn);
            admin.logIn();
            admin.lihatPlaylistAdmin(); // Langsung tampilkan setelah login

            while (true) {
                System.out.print("\nTambah lagu baru? (y/n): ");
                if (sc.nextLine().equalsIgnoreCase("n")) break;

                System.out.print("Judul: "); String jdl = sc.nextLine();
                System.out.print("Artis: "); String art = sc.nextLine();
                System.out.print("Durasi: "); double dur = sc.nextDouble();
                sc.nextLine(); // clear buffer
                
                admin.tambahLagu(jdl, art, dur);
            }
        } else {
            Member member = new Member(uIn);
            member.logIn();
            member.lihatPlaylist(); // Langsung tampilkan setelah login

            while (true) {
                System.out.println("\n1. Lihat | 2. Cari | 3. Rata-rata | 4. Keluar");
                System.out.print("Pilih menu: ");
                int opt = sc.nextInt(); sc.nextLine();

                if (opt == 1) member.lihatPlaylist();
                else if (opt == 2) {
                    System.out.print("Cari judul: ");
                    member.cariLagu(sc.nextLine());
                }
                else if (opt == 3) member.hitungRataDurasi();
                else break;
            }
        }
        System.out.println("\nProgram selesai. Terima kasih.");
        sc.close();
    }
}