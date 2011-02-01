package kmp;

import utilities.IAlgorithm;
import utilities.SubString;

import java.util.LinkedList;

public class KMPLCSAlgorithm implements IAlgorithm {
    public String run(String T1, String T2) {
        char[] minString, maxString;
        int minLength,maxLength;
        if (T1.length() < T2.length()) {
            minString = T1.toCharArray();
            minLength = T1.length();
            maxString = T2.toCharArray();
            maxLength = T2.length();
        } else {
            minString = T2.toCharArray();
            minLength = T2.length();
            maxString = T1.toCharArray();
            maxLength = T1.length();
        }

        LinkedList<SubString> list = new LinkedList<SubString>();
        int length;
        for (length = minLength; length > 0; length--) {
            for (int i = 0; i <= (minLength - length); i++) {
                final int[] func1 = new int[length];
                func1[0] = 0;
                int k = i;

                for (int q1 = i + 1; q1 < length + i; q1++) {
                    while (k > i && minString[k] != minString[q1])
                        k = func1[k - 1 - i] + i;
                    if (minString[k] == minString[q1]) k++;
                    func1[q1 - i] = k - i;
                }
                int q = 0;
                for (int i1 = 0; i1 < maxLength; i1++) {
                    while (q > 0 && minString[q + i] != maxString[i1])
                        q = func1[q - 1];
                    if (minString[q + i] == maxString[i1])
                        q++;
                    if (q == length) {
                        list.add(new SubString(new String(minString, i, length), i1 - length + 1, i));
                        q = func1[q - 1];
                    }
                }
            }
            if (!list.isEmpty()) {
                break;
            }
        }

        String result = "" + length;
        for (SubString ss : list) {
            if (T1.length() < T2.length()) {
                result += "\n" + ss.getShiftT2() + " " + ss.getShiftT1();
            } else {
                result += "\n" + ss.getShiftT1() + " " + ss.getShiftT2();
            }
        }

        return result;
    }
}
