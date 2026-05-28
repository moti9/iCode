

public abstract class Pizza {
    String name;
    Dough dough;
    Sauce sauce;
    Veggies veggies[];
    Cheese cheese;
    Clams clam;
    Pepperoni pepperoni;

    abstract void prepare();

    void bake() {
        System.out.println("Bake for 25 minutes at 350");
    }

    void cut() {
        System.out.println("Cut the pizza into diagonal slices");
    }

    void box() {
        System.out.println("Place pizza in official PizzaStore box");
    }

    String getName() {
        return this.name;
    }

    void setName(String name) {
        this.name = name;
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append("_-_-_-_-_-_ " + this.name + " _-_-_-_-_-_\n");
        if (this.dough != null) {
            result.append(this.dough + "\n");
        }
        if (this.sauce != null) {
            result.append(this.sauce + "\n");
        }
        if (this.cheese != null) {
            result.append(this.cheese + "\n");
        }
        if (this.clam != null) {
            result.append(this.clam + "\n");
        }
        if (this.pepperoni != null) {
            result.append(this.pepperoni + "\n");
        }
        for (Veggies veggie : this.veggies) {
            result.append(veggie + "\n");
        }

        return result.toString();
    }
}
    
