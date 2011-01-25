package utilities;

import java.util.LinkedList;

/**
 * Verify the solution using dynamic programming to solve for LCSubstring.
 */
public class Verifier {
    public LinkedList<String> run(String s1, String s2) {
        int[][] L = new int[s1.length()][s2.length()];
        int z = 0;
        LinkedList<String> list = new LinkedList<String>();
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 1 || j == 1)
                        L[i][j] = 1;
                    else
                        L[i][j] = L[i - 1][j - 1] + 1;
                    if (L[i][j] > z) {
                        z = L[i][j];
                        list.clear();
                    }
                    if (L[i][j] == z)
                        list.add(s1.substring(i - z + 1, i));
                }
            }
        }

        return list;
    }

    public static void main(String[] args) {
        Verifier v = new Verifier();
        LinkedList<String> list = v.run("ababcabab", "ababdabab");
        System.out.println(list.toString());
    }
}
