import java.util.Scanner;

/**
 * A_Bit
 */
public class A_Bit {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int x = 0;
        while (t != 0) {
            String s;
            s = sc.next();
            if (s.charAt(1) == '+') {
                x++;
            } else if (s.charAt(1) == '-') {
                --x;
            }
            t--;
        }
        System.out.println(x);

        sc.close();
    }
}