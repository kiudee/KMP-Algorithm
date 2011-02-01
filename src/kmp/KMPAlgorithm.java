package kmp;

import utilities.SubString;

import java.util.LinkedList;

public class KMPAlgorithm {

    private char[] string;
    private char[] pattern;
    private int    stringLength;

    public KMPAlgorithm(String string, String pattern) {
        this.string = string.toCharArray();
        this.pattern = pattern.toCharArray();
        this.stringLength = string.length();
    }

    private KMPAlgorithm() {
    }


    public static void main(String[] args) {
        KMPAlgorithm kmp = new KMPAlgorithm("abbabaababababb", "ababa");
        LinkedList<SubString> list = new LinkedList<SubString>();
        final int[] func1 = new int[4];
        func1[0] = 0;
        int k = 1;

        for (int q1 = 1 + 1; q1 < 4 + 1; q1++) {
            while (k > 1 && kmp.pattern[k] != kmp.pattern[q1])
                k = func1[k - 1 - 1] + 1;
            if (kmp.pattern[k] == kmp.pattern[q1]) k++;
            func1[q1 - 1] = k - 1;
        }
        int[] func = func1;
        int q = 0;
        for (int i = 0; i < kmp.stringLength; i++) {
            while (q > 0 && kmp.pattern[q + 1] != kmp.string[i])
                q = func[q - 1];
            if (kmp.pattern[q + 1] == kmp.string[i])
                q++;
            if (q == 4) {
                list.add(new SubString(new String(kmp.pattern, 1, 4), i - 4 + 1, 1));
                q = func[q - 1];
            }
        }
        for (SubString ss : list) {
            System.out.println(ss.getShiftT1() + " " + ss.getShiftT2());
        }
    }
}