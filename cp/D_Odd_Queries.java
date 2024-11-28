
import java.util.Scanner;

public class D_Odd_Queries {

    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            long tt = sc.nextLong();
            while (tt-- > 0) {
                int n, q;
                n = sc.nextInt();
                q = sc.nextInt();

                long[] pref = new long[n + 1];
                for (int i = 0; i < n; i++) {
                    long num = sc.nextLong();
                    if (i == 0) {
                        pref[i + 1] = num;
                    } else {
                        pref[i + 1] = pref[i] + num;
                    }
                }

                for (int i = 0; i < q; i++) {
                    int l, r;
                    long k;
                    l = sc.nextInt();
                    r = sc.nextInt();
                    k = sc.nextLong();
                    long num = r - l + 1;
                    long sum = num * k;
                    long finalSum = sum + (pref[n] - (pref[r] - pref[l - 1]));
                    if (finalSum % 2 == 0) {
                        System.out.println("NO");
                    } else {
                        System.out.println("YES");
                    }

                }
            }
        }
    }
}
