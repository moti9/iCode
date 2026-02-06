public class DarkRoast extends Beverage {
    public DarkRoast() {
        super("Dark Roast Coffee");
    }

    @Override
    public double getCost() {
        return switch (getSize()) {
            case TALL -> 0.99;
            case GRANDE -> 1.19;
            case VENTI -> 1.39;
        };
    }
    
}
