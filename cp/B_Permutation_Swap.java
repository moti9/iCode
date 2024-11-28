import java.util.Scanner;

public class B_Permutation_Swap {

    static int __gcd(int a, int b) {
        return b == 0 ? a : __gcd(b, a % b);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int tt = sc.nextInt();
            while (tt-- > 0) {
                int n = sc.nextInt();
                int perm[] = new int[n];
                int ans = 0;
                for (int i = 0; i < n; i++) {
                    perm[i] = sc.nextInt();
                    int diff = Math.abs(perm[i] - i - 1);
                    ans = __gcd(ans, diff);
                }
                System.out.println(ans);
            }
        }
    }
}