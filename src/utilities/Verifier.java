package utilities;

import java.util.LinkedList;

/**
 * Verify the solution using dynamic programming to solve for LCSubstring.
 */
public class Verifier implements IAlgorithm {
    private LinkedList<SubString> generateResult(String s1, String s2) {
        int[][] L = new int[s1.length()][s2.length()];
        int z = 0;
        LinkedList<SubString> list = new LinkedList<SubString>();
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0)
                        L[i][j] = 1;
                    else
                        L[i][j] = L[i - 1][j - 1] + 1;
                    if (L[i][j] > z) {
                        z = L[i][j];
                        list.clear();
                    }
                    if (L[i][j] == z) {
                        SubString ss = new SubString(s1.substring(i - z + 1, i + 1), i - z + 1, j - z + 1);
                        list.add(ss);
                    }
                }
            }
        }

        return list;
    }

    public String run(String T1, String T2) {
        LinkedList<SubString> list = generateResult(T1, T2);
        if (list.size() == 0)
            return "No Common Substring";
        String output = "" + list.peek().getSubstring().length() + "\n";
        for (SubString ss : list) {
            output += ss.getShiftT1() + " " + ss.getShiftT2() + "\n";
        }
        return output;
    }

    public static void main(String[] args) {
        Verifier v = new Verifier();
        System.out.print(v.run("abcdabc", "abceabc"));
    }
}
