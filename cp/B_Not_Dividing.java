
import java.util.Scanner;

public class B_Not_Dividing {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int tt = sc.nextInt();
            while (tt-- > 0) {
                int n = sc.nextInt();
                long[] arr = new long[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = sc.nextLong();
                    if (arr[i] == 1) {
                        arr[i] += 1;
                    }
                }
                for (int i = 0; i < n - 1; i++) {
                    if (arr[i + 1] % arr[i] == 0) {
                        arr[i + 1] += 1;
                    }
                }

                for (int i = 0; i < n; i++) {
                    System.out.print(arr[i] + " ");
                }
                System.out.println();
            }
        }
    }
}
