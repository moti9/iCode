public class Singleton {
    public static Singleton uniqueInstance;

    private Singleton() {
        System.out.println("Inside singleton class.");
    }

    public static Singleton getInstance() {
        if (uniqueInstance == null) {
            System.out.println("Initiating the singleton class.");
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
    }
    
}
