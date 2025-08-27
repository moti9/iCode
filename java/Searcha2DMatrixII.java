
import java.util.HashMap;
import java.util.Scanner;

public class Searcha2DMatrixII {
    public boolean searchMatrix(int[][] matrix, int target) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int[] matrix1 : matrix) {
            for (int j = 0; j < matrix1.length; j++) {
                map.put(matrix1[j], true);
            }
        }
        return map.getOrDefault(target, false);
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            Searcha2DMatrixII search = new Searcha2DMatrixII();
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[][] matrix = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = scanner.nextInt();
                }
            }
            int target = scanner.nextInt();
            boolean result = search.searchMatrix(matrix, target);
            System.out.println(result ? "true" : "false");
        }
    }

}
