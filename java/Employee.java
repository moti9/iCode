public class Employee {
    public static void main(String[] args) {
        int a = -10;
        System.out.println("This is my first program in the java.");
        System.out.println(a);

        // InnerEmployee emp = new InnerEmployee();
    }
}

/**
 * InnerEmployee
 */
class InnerEmployee {
    public static void main(String[] args) {
        System.out.println("This is the second class");
    }
}