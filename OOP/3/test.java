class Email {
    private final String signature;

    public Email(String signature) {
        this.signature = signature;
    }

    public String constructEmail(User recipient, String body) {
        String str = "";
        str += recipient.getNiceUserName();
        str += "\n\n";
        str += body;
        str += "\n\n";
        str += signature;
        return str;
    }
}

class User {
    private String first;
    private String last;

    public User(String first, String last) {
        this.first = first;
        this.last = last;
    }

    public String firstName() {
        return first;
    }

    public String lastName() {
        return last;
    }

    public String getNiceUserName() {
        return firstName() + " " + lastName();
    }
}
