import java.util.Scanner;

/**
 * B_Maximum_Multiple_Sum
 */
public class B_Maximum_Multiple_Sum {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n = sc.nextInt();
            int ans = 0, sum = 0;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j * i <= n; j++) {
                    int tsum = (j * (j + 1) * i) / 2;
                    if (tsum > sum) {
                        sum = tsum;
                        ans = i;
                    }
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}