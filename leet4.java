public class leet4 {
    public static String longestPalindrome(String s) {
        String ans = "";
        for (int i = 0; i < s.length(); i++) {
            String current = s.substring(i, i + 1);
            for (int j = 1; j < s.length(); j++) {
                if (i - j >= 0 && i + j < s.length()) {
                    if (s.substring(i - j, i - j + 1).equals(s.substring(i + j, i + j + 1))) {
                        current = s.substring(i - j, i - j + 1) + current + s.substring(i + j, i + j + 1);
                    } else
                        break;
                }
            }
            if (current.length() > ans.length())
                ans = current;
        }

        for (int i2 = 0; i2 < s.length() - 1; i2++) {
            String current2 = "";
            if (s.substring(i2, i2 + 1).equals(s.substring(i2 + 1, i2 + 2)))
                current2 = s.substring(i2, i2 + 2);
            for (int k = 1; k < s.length(); k++) {
                if (i2 - k >= 0 && i2 + 1 + k < s.length()) {
                    if (s.substring(i2 - k, i2 - k + 1).equals(s.substring(i2 + 1 + k, i2 + 1 + k + 1))) {
                        current2 = s.substring(i2 - k, i2 - k + 1) + current2 + s.substring(i2 + 1 + k, i2 + 1 + k + 1);
                    } else
                        break;
                }
            }
            if (current2.length() > ans.length())
                ans = current2;
        }
        return ans;
    }

    public static void main(String[] args) {
        String test = "abbcd";
        longestPalindrome(test);
        System.out.println(longestPalindrome(test));
    }
}