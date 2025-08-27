
import java.util.Scanner;


public class MaximalSquare {

    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int dp[][] = new int[n + 1][m + 1];
        int sqSize = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = 1 + Math.min(dp[i][j + 1], Math.min(dp[i + 1][j], dp[i][j]));
                    sqSize = Math.max(sqSize, dp[i + 1][j + 1]);
                }
            }
        }
        return sqSize * sqSize;
    }
    
    public static void main(String[] args) {
        try(Scanner scanner = new Scanner(System.in)) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            char[][] matrix = new char[n][m];
            for(int i = 0; i < n; i++) {
                String row = scanner.next();
                matrix[i] = row.toCharArray();
            }

            MaximalSquare ms = new MaximalSquare();
            int result = ms.maximalSquare(matrix);
            System.out.println(result);
        }
    }
}
