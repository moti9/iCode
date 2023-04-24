import java.util.Scanner;

/**
 * A_In_Search_of_an_Easy_Problem
 */
public class A_In_Search_of_an_Easy_Problem {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean hard = false;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (x == 1) {
                hard = true;
            }
        }
        if (hard) {
            System.out.print("HARD");
        } else {
            System.out.print("EASY");
        }
        sc.close();
    }
}