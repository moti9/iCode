
public class Whip extends CondimentDecorator {

    public Whip(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Whip";
    }

    @Override
    public double getCost() {
        double cost = beverage.getCost();
        double surcharge = switch (beverage.getSize()) {
            case Size.TALL -> 0.10;
            case Size.GRANDE -> 0.15;
            case Size.VENTI -> 0.20;
        };
        return cost + surcharge;
    }

}
