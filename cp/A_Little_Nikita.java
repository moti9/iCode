import java.util.Scanner;

/**
 * A_Little_Nikita
 */
class A_Little_Nikita {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tt = sc.nextInt();

        while(tt-- > 0){
            int n = sc.nextInt();
            int m = sc.nextInt();

            int diff = n - m;
            if(diff >= 0 && diff % 2 == 0) System.out.println("Yes");
            else System.out.println("No");
        }

        sc.close();
    }    
}