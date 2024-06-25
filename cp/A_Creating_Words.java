import java.util.Scanner;


/**
 * A_Creating_Words
 */
public class A_Creating_Words {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tt = sc.nextInt();

        while (tt-- > 0) {
            String a = sc.next();
            String b = sc.next();
            StringBuilder sbA = new StringBuilder(a);
            StringBuilder sbB = new StringBuilder(b);

            char af = a.charAt(0);
            char bf = b.charAt(0);
            sbA.setCharAt(0, bf);
            sbB.setCharAt(0, af);
            System.out.println(sbA.toString() + " " + sbB.toString());
        }

        sc.close();
    }
}