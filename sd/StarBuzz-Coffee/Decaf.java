
public class Decaf extends Beverage {

    public Decaf() {
        super("Decaf Coffee");
    }

    @Override
    public double getCost() {
        return switch (getSize()) {
            case TALL -> 1.05;
            case GRANDE -> 1.25;
            case VENTI -> 1.45;
        };
    }

}
