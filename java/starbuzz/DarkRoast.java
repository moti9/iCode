public class DarkRoast extends Beverage {
    private String description;

    public DarkRoast() {
        this.description = "Most excellent dark roast coffee";
    }

    @Override
    public Double cost() {
        return 0.99;
    }


    public String getDescription() {
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }
    
}
