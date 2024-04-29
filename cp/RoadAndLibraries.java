import java.util.*;

/**
 * RoadAndLibraries
 */

class Result {

    /*
     * Complete the 'roadsAndLibraries' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     * 1. INTEGER n
     * 2. INTEGER c_lib
     * 3. INTEGER c_road
     * 4. 2D_INTEGER_ARRAY cities
     */

    public static long roadsAndLibraries(int n, int c_lib, int c_road, List<List<Integer>> cities) {
        if (c_lib <= c_road) {
            return (long) n * (long) c_lib;
        }
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (List<Integer> city : cities) {
            int u = city.get(0);
            int v = city.get(1);
            graph.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            graph.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        List<Integer> cmp = new ArrayList<>();
        List<Integer> vis = new ArrayList<>(Collections.nCopies(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            if (graph.containsKey(i) && vis.get(i) == 0) {
                cmp.add(dfs(i, vis, graph));
            } else {
                cmp.add(1);
            }
        }

        long ans = 0;
        for (int cm : cmp) {
            ans += Math.min((long) (cm - 1) * (long) c_road + (long) c_lib, (long) cm * (long) c_lib);
        }
        return ans;
    }

    static int dfs(int node, List<Integer> vis, Map<Integer, List<Integer>> graph) {
        vis.set(node, 1);
        int cnt = 1;
        for (int neighbor : graph.get(node)) {
            if (vis.get(neighbor) == 0) {
                cnt += dfs(neighbor, vis, graph);
            }
        }
        return cnt;
    }

}

public class RoadAndLibraries {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tt = sc.nextInt();
        while (tt-- > 0) {
            int n, m, c_lib, c_road;
            n = sc.nextInt();
            m = sc.nextInt();
            c_lib = sc.nextInt();
            c_road = sc.nextInt();
            List<List<Integer>> cities = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int u, v;
                u = sc.nextInt();
                v = sc.nextInt();
                cities.add(Arrays.asList(u, v));
            }
            long result = Result.roadsAndLibraries(n, c_lib, c_road, cities);
            System.out.println(result);
        }

        sc.close();
    }
}