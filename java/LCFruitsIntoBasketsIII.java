
import java.util.Scanner;

public class LCFruitsIntoBasketsIII {

    
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        int m = (int) Math.sqrt((double)n);
        int sec = (n + m - 1) / m;
        int[] maxV = new int[sec];
        for(int i=0;i<n;i++){
            maxV[i / m] = Math.max(maxV[i / m], baskets[i]);
        }

        int cnt = 0;
        for(int i=0;i<n;i++){
            int cs;
            int isunplaced = 1;
            for(cs = 0; cs < sec; cs++){
                if(maxV[cs] < fruits[i]){
                    continue;
                }
                int flag = 0;
                maxV[cs] = 0;

                for(int j=0;j<m;j++) {
                    int pos = cs * m + j;
                    if(pos < n && fruits[i] <= baskets[pos] && flag == 0) {
                        flag = 1;
                        baskets[pos] = 0;
                    }
                    if(pos < n) {
                        maxV[cs] = Math.max(maxV[cs], baskets[pos]);
                    }
                }
                isunplaced = 0;
                break;
            }
            cnt += isunplaced;
        }
        return cnt;
    }



    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int[] fruits = new int[n];
            for (int i = 0; i < n; i++) {
                fruits[i] = sc.nextInt();
            }
            int[] baskets = new int[n];
            for (int i = 0; i < n; i++) {
                baskets[i] = sc.nextInt();
            }
            LCFruitsIntoBasketsIII solver = new LCFruitsIntoBasketsIII();
            int unplaced = solver.numOfUnplacedFruits(fruits, baskets);
            System.out.println("Number of unplaced fruits: " + unplaced);
        }
    }

}