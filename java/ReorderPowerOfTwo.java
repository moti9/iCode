import java.util.ArrayList;
import java.util.Scanner;

public class ReorderPowerOfTwo {

    public static boolean isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }

    public static void swap(StringBuilder sb, int i, int j) {
        char temp = sb.charAt(i);
        sb.setCharAt(i, sb.charAt(j));
        sb.setCharAt(j, temp);
    }

    public static void allPermutations(int index, StringBuilder sb, ArrayList<String> result) {
        if (index == sb.length() - 1) {
            result.add(sb.toString());
            return;
        }
        for (int i = index; i < sb.length(); i++) {
            swap(sb, index, i);
            allPermutations(index + 1, sb, result);
            swap(sb, index, i);
        }
    }

    public boolean reorderedPowerOf2(int n) {
        String num = String.valueOf(n);
        ArrayList<String> permutations = new ArrayList<>();
        StringBuilder sb = new StringBuilder(num);
        allPermutations(0, sb, permutations);
        for (String perm : permutations) {
            if (perm.charAt(0) == '0') {
                continue;
            }
            if (isPowerOfTwo(Integer.parseInt(perm))) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            boolean result = new ReorderPowerOfTwo().reorderedPowerOf2(n);
            System.out.println(result);
        }
    }
}
