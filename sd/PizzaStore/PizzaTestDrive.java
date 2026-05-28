import java.util.Scanner;

public class PizzaTestDrive {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        PizzaStore nyStore = new NYStylePizzaStore();
        PizzaStore chicagoStore = new ChicagoStylePizzaStore();
        PizzaStore californiaStore = new CaliforniaStylePizzaStore();

        String[] pizzaTypes = {"cheese", "pepperoni", "clam", "veggie"};
        String[] storeNames = {"NY Style", "Chicago Style", "California Style"};

        while (true) {
            System.out.println("Welcome to the Pizza Store!");
            System.out.println("Please select a pizza type:");
            for (int i = 0; i < pizzaTypes.length; i++) {
                System.out.println((i + 1) + ". " + pizzaTypes[i]);
            }
            System.out.println("0. Exit");

            int pizzaChoice = scanner.nextInt();
            if (pizzaChoice == 0) {
                break;
            }

            if (pizzaChoice < 1 || pizzaChoice > pizzaTypes.length) {
                System.out.println("Invalid choice. Please try again.");
                continue;
            }

            String selectedPizzaType = pizzaTypes[pizzaChoice - 1];

            System.out.println("Please select a store:");
            for (int i = 0; i < storeNames.length; i++) {
                System.out.println((i + 1) + ". " + storeNames[i]);
            }
            System.out.println("0. Exit");

            int storeChoice = scanner.nextInt();
            if (storeChoice == 0) {
                break;
            }

            PizzaStore selectedStore;
            switch (storeChoice) {
                case 1:
                    selectedStore = nyStore;
                    break;
                case 2:
                    selectedStore = chicagoStore;
                    break;
                case 3:
                    selectedStore = californiaStore;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
                    continue;
            }

            Pizza pizza = selectedStore.orderPizza(selectedPizzaType);
            if (pizza != null) {
                System.out.println("You ordered a " + pizza.getName() + " from " + storeNames[storeChoice - 1] + "!");
            } else {
                System.out.println("Sorry, we don't have that type of pizza.");
            }

            System.out.println("----------------------------------- Next Order -----------------------------------");
        }
        System.out.println("Thank you for visiting the Pizza Store. Goodbye!");
        scanner.close();
    }
    
}
