public class StarBuzzCoffee {
    public static void main(String[] args) {
        Beverage beverage = new Espresso();
        System.out.println(beverage.getDescription() + " $" + beverage.getCost());
        beverage.setSize(Beverage.Size.GRANDE);
        System.out.println(beverage.getDescription() + " $" + beverage.getCost());
        beverage.setSize(Beverage.Size.VENTI);
        System.out.println(beverage.getDescription() + " $" + beverage.getCost());

        Beverage beverage2 = new DarkRoast();
        beverage2 = new Mocha(beverage2);
        beverage2 = new Mocha(beverage2);
        beverage2 = new Whip(beverage2);
        System.out.println(beverage2.getDescription() + " $" + beverage2.getCost());

        Beverage beverage3 = new HouseBlend();
        beverage3 = new Soy(beverage3);
        beverage3 = new Mocha(beverage3);
        beverage3 = new Whip(beverage3);
        System.out.println(beverage3.getDescription() + " $" + beverage3.getCost());

        Beverage beverage4 = new Decaf();
        beverage4 = new SteamedMilk(beverage4);
        beverage4 = new Soy(beverage4);
        System.out.println(beverage4.getDescription() + " $" + beverage4.getCost());
    }    
}
