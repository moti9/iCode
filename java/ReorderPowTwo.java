import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ReorderPowTwo {

    public static List<Integer> getDigitFreq(int n) {
        List<Integer> cntDigits = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            cntDigits.add(0);
        }
        while (n > 0) {
            cntDigits.set(n % 10, cntDigits.get(n % 10) + 1);
            n /= 10;
        }
        return cntDigits;
    }

    public static boolean isSameDigitFreq(List<Integer> a, List<Integer> b) {
        for (int i = 0; i < 10; i++) {
            if (!a.get(i).equals(b.get(i))) {
                return false;
            }
        }
        return true;
    }

    public boolean reorderedPowerOf2(int n) {
        List<Integer> cntDigits = getDigitFreq(n);
        
        for (int i = 0; i < 32; i++) {
            int num = 1 << i;
            if (isSameDigitFreq(getDigitFreq(num), cntDigits)) {
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
