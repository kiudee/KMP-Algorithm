package kmp;

import utilities.SubString;

import java.util.Collection;
import java.util.LinkedList;

public class KMPAlgorithm {

    public Collection<SubString> kmpMatcher(String P, String T) {
        LinkedList<SubString> result = new LinkedList<SubString>();
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
                result.add(new SubString(P, i - m));
                q = func[q - 1];
            }
        }
        return result;
    }

    private int[] computePrefixFunction(String P) {
        int m = P.length();
        int[] func = new int[m];
        func[0] = 0;
        int k = 0;

        for (int q = 1; q < m; q++) {
            while (k > 0 && P.charAt(k) != P.charAt(q))
                k = func[k];
            if (P.charAt(k) == P.charAt(q)) k++;
            func[q] = k;
        }
        return func;

    }

    public static void main(String[] args) {
        KMPAlgorithm algo = new KMPAlgorithm();
        Collection<SubString> result = algo.kmpMatcher("ababa", "abbabaababababb");
        for (SubString ss : result) {
            System.out.println(ss.getShiftT1());
        }
    }
}