package kmp;

import utilities.SubString;

import java.util.Arrays;
import java.util.LinkedList;

public class KMPAlgorithm {

    private char[] string;
    private char[] pattern;

    public KMPAlgorithm(String string, String pattern) {
        this.string = string.toCharArray();
        this.pattern = pattern.toCharArray();
    }

    private KMPAlgorithm() {
    }

    private int[] computePrefixFunction(int shift, int length) {
        final int[] func = new int[length];
        func[0] = 0;
        int k = shift;

        for (int q = shift + 1; q < length + shift; q++) {
            while (k > shift && pattern[k] != pattern[q])
                k = func[k - 1 - shift] + shift;
            if (pattern[k] == pattern[q]) k++;
            func[q - shift] = k - shift;
        }
        return func;
    }

    private int[] computePrefixFunction(String P) {
        int m = P.length();
        int[] func = new int[m];
        func[0] = 0;
        int k = 0;

        for (int q = 1; q < m; q++) {
            while (k > 0 && P.charAt(k) != P.charAt(q))
                k = func[k - 1];
            if (P.charAt(k) == P.charAt(q)) k++;
            func[q] = k;
        }
        return func;

    }

    public void kmpMatcher(LinkedList<SubString> list, String P, String T, int currentShift) {
        int m = P.length();
        int n = T.length();
        int[] func = computePrefixFunction(P);
        int q = 0;
        for (int i = 0; i < n; i++) {
            while (q > 0 && P.charAt(q) != T.charAt(i))
                q = func[q - 1];
            if (P.charAt(q) == T.charAt(i))
                q++;
            if (q == m) {
                list.add(new SubString(P, i - m + 1, currentShift));
                q = func[q - 1];
            }
        }
    }


    public static void main(String[] args) {
        KMPAlgorithm kmp = new KMPAlgorithm("ababababca", "ababababca");
        int[] pf = kmp.computePrefixFunction(1, 5);
        System.out.println(Arrays.toString(pf));
    }
}