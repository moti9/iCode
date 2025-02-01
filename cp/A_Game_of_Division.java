
import java.util.ArrayList;
import java.util.Scanner;

public class A_Game_of_Division {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int tt = sc.nextInt();
            while (tt-- > 0) {
                int n = sc.nextInt();
                int k = sc.nextInt();

                ArrayList<Integer> arr = new ArrayList<>();
                for (int idx = 0; idx < n; idx++) {
                    int x = sc.nextInt();
                    arr.add(x);
                }

                Boolean won = false;
                Integer index = -1;
                for (int i = 0; i < n; i++) {
                    Boolean all_div = true;
                    for (int j = 0; j < n; j++) {
                        if (i == j) {
                            continue;
                        }
                        if (Math.abs(arr.get(i) - arr.get(j)) % k == 0) {
                            all_div = false;
                            break;
                        }
                    }
                    if (all_div) {
                        won = true;
                        index = i + 1;
                        break;
                    }
                }
                if (won) {
                    System.out.println("YES");
                    System.out.println(index);
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
