import java.util.Scanner;

/**
 * A_Anton_and_Polyhedrons
 */
public class A_Anton_and_Polyhedrons {

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int n = sc.nextInt();
            int face = 0;
            for (int i = 0; i < n; i++) {
                String s = sc.next();
                switch (s) {
                    case "Tetrahedron" -> face += 4;
                    case "Cube" -> face += 6;
                    case "Octahedron" -> face += 8;
                    case "Dodecahedron" -> face += 12;
                    case "Icosahedron" -> face += 20;
                    default -> {
                    }
                }
            }
            System.out.println(face);
        }
    }
}