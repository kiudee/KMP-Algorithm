package kmp;

import utilities.IAlgorithm;
import utilities.SubString;

import java.util.LinkedList;

public class KMPLCSAlgorithm implements IAlgorithm {
    public String run(String T1, String T2) {
        KMPAlgorithm kmp;
        String minString, maxString;
        if (T1.length() < T2.length()) {
            minString = T1;
            maxString = T2;
        } else {
            minString = T2;
            maxString = T1;
        }
        kmp = new KMPAlgorithm(maxString, minString);

        LinkedList<SubString> list = new LinkedList<SubString>();
        int length;
        for (length = minString.length(); length > 0; length--) {
            for (int i = 0; i <= (minString.length() - length); i++) {
                kmp.kmpMatcher(list, i, length);
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
