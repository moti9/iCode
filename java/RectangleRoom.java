import java.util.Scanner;

public class RectangleRoom {

    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // bottom-left
        int x5 = Math.max(ax1, bx1);
        int y5 = Math.max(ay1, by1);
        // top-right
        int x6 = Math.min(ax2, bx2);
        int y6 = Math.min(ay2, by2);

        // check for no intersection
        if (x5 > x6 || y5 > y6) {
            return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        }
        int l = x6 - x5;
        int b = y6 - y5;
        int intersectionArea = l * b;
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);
        return areaA + areaB - intersectionArea;
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int ax1 = scanner.nextInt();
            int ay1 = scanner.nextInt();
            int ax2 = scanner.nextInt();
            int ay2 = scanner.nextInt();
            int bx1 = scanner.nextInt();
            int by1 = scanner.nextInt();
            int bx2 = scanner.nextInt();
            int by2 = scanner.nextInt();

            RectangleRoom room = new RectangleRoom();
            int area = room.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
            System.out.println(area);
        }
        
    }
    
}
