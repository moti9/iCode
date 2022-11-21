import java.util.Scanner;

/**
 * A_Beautiful_Matrix
 */
public class A_Beautiful_Matrix {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] mat = new int[5][5];
        int x = -1, y = -1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mat[i][j] = sc.nextInt();
                if (mat[i][j] == 1) {
                    x = i + 1;
                    y = j + 1;
                }
            }
        }
        int step = Math.abs(3 - x) + Math.abs(3 - y);
        System.out.print(step);
        sc.close();
    }
}