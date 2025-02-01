
import java.util.Scanner;

public class D_Digital_string_maximization {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int tt = sc.nextInt();
            sc.nextLine();
            while (tt-- > 0) {
                String s = sc.next();
                char[] sa = s.toCharArray();
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < s.length() - 1; j++) {
                        int pv = sa[j] - '0';
                        int nv = sa[j + 1] - '0';
                        if (pv < nv - 1) {
                            sa[j] = (char) (pv - 1 + '0');
                            sa[j + 1] = (char) (pv + '0');
                        }
                    }
                }
                System.out.println(new String(sa));
            }
        }
    }
}
