import java.util.*;

public class Bfs {

    public ArrayList<Integer> bfsTraversal(int n, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> bfs = new ArrayList<>();

        boolean vis[] = new boolean[n];

        Queue<Integer> q = new LinkedList<>();

        q.add(0);
        vis[0] = true;

        while (!q.isEmpty()) {
            int node = q.poll();
            bfs.add(node);

            for (Integer it : adj.get(node)) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.add(it);
                }
            }
        }

        return bfs;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        Bfs bf = new Bfs();

        ArrayList<Integer> ans = bf.bfsTraversal(n, adj);

        for (int i = 0; i < n; i++) {
            System.out.print(ans.get(i) + " ");
        }

        sc.close();

    }
}
