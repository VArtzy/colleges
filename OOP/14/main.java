// Abstract Product
interface Button {
    void render();
}

// Concrete Products 
class HoverButton implements Button {
    @Override
    public void render() {
        System.out.println("HoverButton: warna background berubah saat mouse diarahkan");
    }
}

class ClickButton implements Button {
    @Override
    public void render() {
        System.out.println("ClickButton: dua warna background berubah saat diklik");
    }
}

// Abstract Factory 
interface ButtonFactory {
    Button createButton();
}

// Concrete Factories 
class HoverButtonFactory implements ButtonFactory {
    @Override
    public Button createButton() {
        return new HoverButton();
    }
}

class ClickButtonFactory implements ButtonFactory {
    @Override
    public Button createButton() {
        return new ClickButton();
    }
}

public class Main {
    public static void main(String[] args) {

        ButtonFactory hoverFactory = new HoverButtonFactory();
        Button hoverButton = hoverFactory.createButton();
        hoverButton.render();

        ButtonFactory clickFactory = new ClickButtonFactory();
        Button clickButton = clickFactory.createButton();
        clickButton.render();
    }
}
