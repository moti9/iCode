import java.util.Scanner;

/**
 * A_Dual_Trigger
 */

public class A_Dual_Trigger {

    static boolean checkAdj(String s, int n) {
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == '1' && s.charAt(i) == s.charAt(i + 1))
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n = sc.nextInt();
            String st = sc.next();
            int cnt1 = 0;
            // if (n == 1) {
            //     if (st == "0") {
            //         System.out.println("YES");
            //     } else {
            //         System.out.println("NO");
            //     }
            //     continue;
            // }
            // if (n == 2) {
            //     if (st == "00") {
            //         System.out.println("YES");
            //     } else {
            //         System.out.println("NO");
            //     }
            //     continue;
            // }
            for (int i = 0; i < n; i++) {
                if (st.charAt(i) == '1')
                    cnt1 += 1;
            }
            if (cnt1 % 2 == 0) {
                if (cnt1 == 2) {
                    if (checkAdj(st, n))
                        System.out.println("NO");
                    else
                        System.out.println("YES");
                } else {
                    System.out.println("YES");
                }
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
}