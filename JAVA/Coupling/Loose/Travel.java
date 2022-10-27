package Coupling.Loose;

public class Travel implements ITravel{
    
    private Transport transport;

    public Travel(Transport transport) {
        this.transport = transport;
    }

    @Override
    public void start() {
        transport.start();
    }
}
