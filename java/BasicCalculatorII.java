
import java.util.Scanner;
import java.util.Stack;

public class BasicCalculatorII {
    public int calculate(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }
        int n = s.length();
        Stack<Integer> stack = new Stack<>();
        int currNumber = 0;
        char lastOperator = '+';
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (Character.isDigit(c)) {
                currNumber = (currNumber * 10) + (c - '0');
            } 
            if (!Character.isDigit(c) && !Character.isWhitespace(c) || i == n - 1) {
                switch (lastOperator) {
                    case '+' -> stack.push(currNumber);
                    case '-' -> stack.push(-currNumber);
                    case '*' -> stack.push(stack.pop() * currNumber);
                    case '/' -> stack.push(stack.pop() / currNumber);
                }
                lastOperator = c;
                currNumber = 0;
            }
        }

        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }


    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)) {
            String expression = sc.nextLine();
            int result = new BasicCalculatorII().calculate(expression);
            System.out.println(result);
        }
    }
    
}
