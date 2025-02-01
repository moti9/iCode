
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class B_Paint_a_Strip {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tt = Integer.parseInt(br.readLine());

        while (tt-- > 0) {
            int n = Integer.parseInt(br.readLine());

            Integer cnt = 1, num = 1;
            while (true) {
                if (num >= n) {
                    break;
                }
                cnt += 1;
                num = num * 2 + 2;
            }
            System.out.println(cnt);
        }
    }
}
