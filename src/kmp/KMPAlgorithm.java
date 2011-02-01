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

    public void kmpMatcher(LinkedList<SubString> list, int shift, int length) {
        int[] func = computePrefixFunction(shift, length);
        int q = 0;
        for (int i = 0; i < stringLength; i++) {
            while (q > 0 && pattern[q + shift] != string[i])
                q = func[q - 1];
            if (pattern[q + shift] == string[i])
                q++;
            if (q == length) {
                list.add(new SubString(new String(pattern, shift, length), i - length + 1, shift));
                q = func[q - 1];
            }
        }
    }


    public static void main(String[] args) {
        KMPAlgorithm kmp = new KMPAlgorithm("abbabaababababb", "ababa");
        LinkedList<SubString> list = new LinkedList<SubString>();
        kmp.kmpMatcher(list, 1, 4);
        for (SubString ss : list) {
            System.out.println(ss.getShiftT1() + " " + ss.getShiftT2());
        }
    }
}