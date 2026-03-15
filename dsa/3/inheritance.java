class Hewan {
    void suara() {
        System.out.println("Hewan bersuara");
    }
}

class Kucing extends Hewan {
    void suaraKucing() {
        System.out.println("Meong");
    }
}

public class Main {
    public static void main(String[] args) {
        Kucing k = new Kucing();
        k.suara();       
        k.suaraKucing();
    }
}
