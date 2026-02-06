public class HouseBlend extends Beverage {
    public HouseBlend() {
        super("House Blend Coffee");
    }

    @Override
    public double getCost() {
        return switch (getSize()) {
            case TALL -> 0.89;
            case GRANDE -> 1.09;
            case VENTI -> 1.29;
        };
    }
    
}
