import java.util.Scanner;

/**
 * B_Battle_Cows
 */
public class B_Battle_Cows {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            k--;

            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            int maxi = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] > arr[k]) {
                    maxi = i;
                    break;
                }
            }

            int[] pos = new int[n];
            for (int i = 0; i < n; i++) {
                pos[i] = i;
            }

            int ans = 0;
            for (int i : new int[] { 0, maxi }) {
                if (i == -1 || i == n)
                    continue;

                int temp = pos[i];
                pos[i] = pos[k];
                pos[k] = temp;

                int[] games = new int[n];
                int u = pos[0];
                for (int j = 1; j < n; j++) {
                    int v = pos[j];
                    u = (arr[u] > arr[v]) ? u : v;
                    games[u]++;
                }

                temp = pos[i];
                pos[i] = pos[k];
                pos[k] = temp;
                ans = Math.max(ans, games[k]);
            }
            System.out.println(ans);

        }
        sc.close();
    }
}