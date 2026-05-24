import java.util.*;

class Shipment {
    int id;
    String currentStatus;
    Stack<String> statusHistory;

    public Shipment(int id) {
        this.id = id;
        this.currentStatus = "CREATED";
        this.statusHistory = new Stack<>();
        this.statusHistory.push("CREATED");
    }

    public void updateStatus(String status) {
        statusHistory.push(status);
        currentStatus = status;
    }

    public void rollbackStatus() {
        if (statusHistory.size() > 1) {
            statusHistory.pop();
            currentStatus = statusHistory.peek();
            System.out.println("Rollback berhasil. Status sekarang: " + currentStatus);
        } else {
            System.out.println("Tidak bisa rollback, sudah di status awal.");
        }
    }

    public void printHistory() {
        System.out.println("History: " + statusHistory);
    }
}

class TrackingSystem {
    private HashMap<Integer, Shipment> shipmentMap;
    private Queue<Shipment> processingQueue;

    public TrackingSystem() {
        shipmentMap = new HashMap<>();
        processingQueue = new LinkedList<>();
    }

    public void addShipment(Shipment s) {
        processingQueue.add(s);
        shipmentMap.put(s.id, s);
        System.out.println("Shipment " + s.id + " ditambahkan ke queue.");
    }

    public void processShipment() {
        if (!processingQueue.isEmpty()) {
            Shipment s = processingQueue.poll();
            System.out.println("Memproses shipment ID: " + s.id +
                               " | Status: " + s.currentStatus);
        } else {
            System.out.println("Queue kosong.");
        }
    }

    public void updateStatus(int id, String status) {
        Shipment s = shipmentMap.get(id);
        if (s != null) {
            s.updateStatus(status);
            System.out.println("Status shipment " + id + " diupdate ke: " + status);
        } else {
            System.out.println("Shipment tidak ditemukan.");
        }
    }

    public void rollbackStatus(int id) {
        Shipment s = shipmentMap.get(id);
        if (s != null) {
            s.rollbackStatus();
        } else {
            System.out.println("Shipment tidak ditemukan.");
        }
    }

    public Shipment searchShipment(int id) {
        Shipment s = shipmentMap.get(id);
        if (s != null) {
            System.out.println("Ditemukan - ID: " + s.id +
                               " | Status: " + s.currentStatus);
        } else {
            System.out.println("Shipment tidak ditemukan.");
        }
        return s;
    }
}

public class Main {
    public static void main(String[] args) {
        TrackingSystem system = new TrackingSystem();

        Shipment s1 = new Shipment(101);
        Shipment s2 = new Shipment(102);

        system.addShipment(s1);
        system.addShipment(s2);

        system.processShipment();

        system.updateStatus(101, "PICKED_UP");
        system.updateStatus(101, "IN_TRANSIT");
        system.updateStatus(101, "DELIVERED"); // salah input

        system.rollbackStatus(101); // rollback ke IN_TRANSIT

        s1.printHistory();
        system.searchShipment(101);
    }
}
