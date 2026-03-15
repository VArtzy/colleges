class Main {
    public static void main(string[] args) {
        String[][] address = {{"Florence", "735-1234", "Manila"}, {"Joyce", "983-3333", "Quezon City"}, {"Becca", "456-3322", "Manila"}};
        System.out.println("Buku Alamat saya");
        for (int n = 0; n < address.length ; n++) {
            for (int m = 0; address[n].length; m++) {
              System.out.println(address[n][m]+"");
              }
            System.out.println("Name: " + address[n][0]);
            System.out.println("Tel.#: " + address[n][1]);
            System.out.println("Address: " + address[n][2]);
            System.out.println();
        }
    }
}
