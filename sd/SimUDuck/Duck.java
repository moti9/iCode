public abstract class Duck {
    FlyBehavior flyBehavior;
    QuackBehavior quackBehavior;
    
    public Duck() {
    }

    public abstract void display();

    public  void performFly() {
        if (flyBehavior != null) {
            flyBehavior.fly();
        } else {
            System.out.println("This duck can't fly!");
        }
    }

    public void performQuack() {
        if (quackBehavior != null) {
            quackBehavior.quack();
        } else {
            System.out.println("This duck can't quack!");
        }
    }

    public void swim() {
        System.out.println("All ducks float, even decoys!");
    }

    public void setFlyBehavior(FlyBehavior fb) {
        this.flyBehavior = fb;
    }

    public void setQuackBehavior(QuackBehavior qb) {
        this.quackBehavior = qb;
    }
}
