import java.util.ArrayList;
import java.util.List;

public class InventoryOOP {

    static class Item {
        private int id;
        private String name;
        private int stock;

        public Item(int id, String name, int stock) {
            this.id = id;
            this.name = name;
            this.stock = stock;
        }

        public int getId() {
            return id;
        }

        public String getName() {
            return name;
        }

        public int getStock() {
            return stock;
        }

        public void updateStock(int newStock) {
            this.stock = newStock;
        }
    }

    static class Inventory {
        private List<Item> items = new ArrayList<>();

        public void addItem(int id, String name, int stock) {
            items.add(new Item(id, name, stock));
        }

        public void removeItem(int id) {
            items.removeIf(item -> item.getId() == id);
        }

        public Item findItem(int id) {
            for (Item item : items) {
                if (item.getId() == id) return item;
            }
            return null;
        }

        public void listItems() {
            System.out.println("=== INVENTORY LIST ===");
            for (Item item : items) {
                System.out.println(
                    item.getId() + " - " +
                    item.getName() + " : " +
                    item.getStock() + " pcs"
                );
            }
        }
    }

    public static void main(String[] args) {
        Inventory inv = new Inventory();

        inv.addItem(1, "Keyboard", 10);
        inv.addItem(2, "Mouse", 15);

        Item item = inv.findItem(1);
        if (item != null) {
            item.updateStock(7);
        }

        inv.removeItem(2);

        inv.listItems();
    }
}
class BankAccount { private double balance; // enkapsulasi: data dilindungi public void deposit(double amt) { // abstraksi: user cukup tahu fungsi deposit balance += amt; } public double getBalance() { return balance; } }
