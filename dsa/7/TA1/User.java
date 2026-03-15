package TA1;

public class User {
    protected String nama;

    public User(String nama) {
        this.nama = nama;
    }

    public void logIn() {
        System.out.println("\n>>> Login Berhasil! Selamat datang, " + nama);
    }
}