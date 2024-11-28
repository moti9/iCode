
import java.util.Scanner;

public class B_Comparison_String {

    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            int tt = sc.nextInt();

            while (tt-- > 0) {
                int n = sc.nextInt();
                String s = sc.next();
                int ans = 1, cnt = 1;
                for (int i = 0; i < n - 1; i++) {
                    if (s.charAt(i) == s.charAt(i + 1)) {
                        cnt += 1; 
                    }else {
                        cnt = 1;
                    }
                    ans = Math.max(ans, cnt);
                }
                System.out.println(ans + 1);
            }
        }

    }
}
