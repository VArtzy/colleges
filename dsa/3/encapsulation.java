class Mahasiswa {
    private String nama;

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getNama() {
        return nama;
    }
}

public class Main {
    public static void main(String[] args) {
        Mahasiswa m = new Mahasiswa();
        m.setNama("Budi");
        System.out.println(m.getNama());
    }
}
