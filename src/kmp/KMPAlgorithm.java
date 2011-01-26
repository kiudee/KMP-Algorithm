package kmp;

import utilities.SubString;

import java.util.LinkedList;

public class KMPAlgorithm {

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
                list.add(new SubString(P, i - m, currentShift));
                q = func[q - 1];
            }
        }
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
}