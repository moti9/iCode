public class CheesePizza extends Pizza {
    PizzaIngredientFactory ingredientFactory;

    public CheesePizza(PizzaIngredientFactory ingredientFactory) {
        this.ingredientFactory = ingredientFactory;
    }

    @Override
    void prepare() {
        System.out.println("Preparing " + this.name);
        this.dough = ingredientFactory.createDough();        
        this.sauce = ingredientFactory.createSauce();
        this.cheese = ingredientFactory.createCheese();
        System.out.println("Preparation of " + this.name + " is complete!");
    }
}
