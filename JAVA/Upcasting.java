class Animal{
    String name;

    public void nature() {
        System.out.println("nature");
    }
}

class Fish extends Animal {
    String color;

    @Override
    public void nature() {
        System.out.println("Aquatic Animal.");
    }
}


public class Upcasting {
    
    public static void main(String[] args) {
        Animal a = new Fish();
        a.nature();

        Fish f = new Fish();
        f.nature();
    }
}
