public class DecoyDuck extends Duck {

    public DecoyDuck() {
        flyBehavior = new FlyNoWay();
        quackBehavior = new Quack();
    }

    @Override
    public void display() {
        System.out.println("I'm a decoy duck!");
    }
    
    @Override
    public void swim() {
        // Decoy ducks do not swim
        System.out.println("Decoy ducks don't swim.");
    }
    
}
