public abstract class Beverage {
    private String description = "Unknown Beverage";
    public enum Size { TALL, GRANDE, VENTI }
    private Size size = Size.TALL;

    public Beverage() {
    }

    public Beverage(String description) {
        this.description = description;
    }

    public String getDescription() {
        return this.description;
    }


    public abstract double getCost();

    public Size getSize() {
        return this.size;
    }

    public void setSize(Size size) {
        this.size = size;
    }
}