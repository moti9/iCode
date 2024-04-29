import java.util.*;;

/**
 * dfs
 */
public class Dfs {

    public static void dfs(int node, boolean vis[], ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> ls) {
        vis[node] = true;
        ls.add(node);
        for (Integer it : adj.get(node)) {
            if (!vis[it]) {
                dfs(it, vis, adj, ls);
            }
        }
    }

    public ArrayList<Integer> dfsTraversal(int n, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> ls = new ArrayList<>();
        boolean vis[] = new boolean[n];
        dfs(0, vis, adj, ls);
        return ls;
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
        Dfs df = new Dfs();
        ArrayList<Integer> ans = df.dfsTraversal(n, adj);

        for (int i = 0; i < n; i++) {
            System.out.print(ans.get(i) + " ");
        }
        sc.close();
    }
}