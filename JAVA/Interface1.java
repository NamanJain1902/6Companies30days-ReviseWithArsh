// import java.io.*;

interface Vehicle {
    void changeGear(int a);
    void speedUp(int a);
    void applyBrakes(int a);
}

class Bicycle implements Vehicle{

    int speed;
    int gear;

    // to change gear
    @Override
    public void changeGear(int newGear)  {
        gear = newGear;
    }
    // to change gear
    @Override
    public void speedUp(int increment)  {
        speed += increment;
    }
    // to change gear
    @Override
    public void applyBrakes(int decrement)  {
        speed -= decrement;
    }

    public void printStates()  {
        System.out.println("Speed: " + speed + " Gear: " + gear);
    }
}

class Bike implements Vehicle { 
    int speed;
    int gear;

    // to change gear
    @Override
    public void changeGear(int newGear)  {
        gear = newGear;
    }
    // to change gear
    @Override
    public void speedUp(int increment)  {
        speed += increment;
    }
    // to change gear
    @Override
    public void applyBrakes(int decrement)  {
        speed -= decrement;
    }

    public void printStates()  {
        System.out.println("Speed: " + speed + " Gear: " + gear);
    }
}

class  Interface1 {
    public static void main(String[] args)  {

        Bicycle bicycle = new Bicycle();
        bicycle.changeGear(2);
        bicycle.speedUp(3);
        bicycle.applyBrakes(1);
        System.out.println("Bicycle present state is: ");
        bicycle.printStates();

        Bike bike = new Bike();
        bike.changeGear(1);
        bike.speedUp(4);
        bike.applyBrakes(3);
        System.out.println("Bicycle present state is: ");
        bike.printStates();
    }
}
