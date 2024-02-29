import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class findEmail {

    public static void findEmailFromLists(ArrayList<String> strs) {
        Pattern pattern = Pattern.compile("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
        Set<String> uniqueEmails = new HashSet<>();

        for (String str : strs) {
            Matcher matcher = pattern.matcher(str);
            while (matcher.find()) {
                uniqueEmails.add(matcher.group());
            }
        }

        List<String> sortedEmails = new ArrayList<>(uniqueEmails);
        Collections.sort(sortedEmails);

        String outputStr = String.join(";", sortedEmails);
        System.out.println(outputStr);
    }

    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        // ArrayList<String> strs = new ArrayList<>();
        // for (int i = 0; i < n; i++) {
        // strs.add(sc.nextLine());
        // }

        // findEmailFromLists(strs);

        // // for (int i = 0; i < n; i++) {
        // // System.out.println(strs.get(i));
        // // }
        // sc.close();

        Scanner sc = new Scanner(System.in);
        String format = "([a-zA-Z0-9\\_\\.\\-]+)@([a-zA-Z0-9\\-\\.]+)(\\.[a-zA-Z]+)(/\\S*)?";
        Pattern pattern = Pattern.compile(format);
        ArrayList<String> links = new ArrayList<String>();
        int testcase = sc.nextInt();
        String dec = sc.nextLine();
        for (int i = 0; i < testcase; i++) {
            String assessed = sc.nextLine();
            Matcher match = pattern.matcher(assessed);
            while (match.find()) {
                match.groupCount();
                if (links.contains(match.group(1) + '@' + match.group(2) + match.group(3)) == false) {
                    links.add(match.group(1) + '@' + match.group(2) + match.group(3));
                }
            }
        }
        Collections.sort(links);
        for (int j = 0; j < links.size(); j++) {
            if (j == links.size() - 1) {
                System.out.println(links.get(j));
            } else {
                System.out.print(links.get(j) + ";");
            }
        }

        sc.close();
    }
}