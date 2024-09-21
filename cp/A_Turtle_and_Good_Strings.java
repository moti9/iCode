import java.util.Scanner;

/**
 * A_Turtle_and_Good_Strings
 */
public class A_Turtle_and_Good_Strings {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n  = sc.nextInt();
            String s = sc.nextLine();
            if (s.charAt(0) != s.charAt(n - 1)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        sc.close();
    }
}