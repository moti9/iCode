import java.util.Scanner;

/**
 * C_Good_Prefixes
 */
public class C_Good_Prefixes {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n = sc.nextInt();
            long sum = 0, maxi = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int a = sc.nextInt();
                maxi = Math.max(maxi, a);
                sum += a;
                if (sum - maxi == maxi)
                    cnt += 1;
            }

            System.out.println(cnt);
        }
        sc.close();
    }
}