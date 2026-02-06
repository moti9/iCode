
public class Espresso extends Beverage {

    public Espresso() {
        super("Espresso");
    }

    @Override
    public double getCost() {
        return switch (getSize()) {
            case TALL -> 1.99;
            case GRANDE -> 2.49;
            case VENTI -> 2.99;
        };
    }
}
