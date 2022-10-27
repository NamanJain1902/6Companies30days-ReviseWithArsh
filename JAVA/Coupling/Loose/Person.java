package Coupling.Loose;

public class Person {
    
    public static void main(String[] args) {
        Bus transport1 = new Bus();
        Train transport2 = new Train();
        ITravel travel = new Travel(transport2);
        travel.start();

        ITravel ltravel = new Travel(transport1);
        ltravel.start();
        
    }
}
