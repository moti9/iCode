
public class Soy extends CondimentDecorator {

    public Soy(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Soy";
    }

    @Override
    public double getCost() {
        double cost = beverage.getCost();
        double surcharge = switch (beverage.getSize()) {
            case Size.TALL -> 0.15;
            case Size.GRANDE -> 0.20;
            case Size.VENTI -> 0.25;
        };
        return cost + surcharge;
    }

}
