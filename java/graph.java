import java.util.ArrayList;
import java.util.Scanner;

/**
 * graph
 */
public class graph {

    static void printAdjList(ArrayList<ArrayList<Integer>> adj) {
        for (int i = 0; i < adj.size(); i++) {
            System.out.print(i + ": ");
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.print(adj.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<Integer>());

        for (int i = 0; i < m; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        printAdjList(adj);

        sc.close();
    }
}