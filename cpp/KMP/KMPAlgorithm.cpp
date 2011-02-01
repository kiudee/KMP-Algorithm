/* 
 * File:   KMPAlgorithm.cpp
 * Author: Karlson
 *
 * Created on 31. Januar 2011, 15:58
 */
#include "KMPAlgorithm.h"

vector<char> KMPAlgorithm::toCharVector(string s) {
    vector<char> result(s.length());
    for (int i = 0; i < s.length(); i++) {
        result[i] = s[i];
    }

    return result;
}

void KMPAlgorithm::run(string t1, string t2) {
    vector<char> minString, maxString;
    bool t1IsMin = false;
    if (t1.length() < t2.length()) {
        t1IsMin = true;
        minString = toCharVector(t1);
        maxString = toCharVector(t2);
    } else {
        maxString = toCharVector(t1);
        minString = toCharVector(t2);
    }

    int length;
    for (length = minString.size(); length > 0; length--) {
        bool found = false;
        for (int i = 0; i <= (minString.size() - length); i++) {
            vector <int> func1(length);
            func1[0] = 0;
            int k = i;

            for (int q1 = i + 1; q1 < length + i; q1++) {
                while (k > i && minString[k] != minString[q1])
                    k = func1[k - 1 - i] + i;
                if (minString[k] == minString[q1]) k++;
                func1[q1 - i] = k - i;
            }
            int q = 0;
            for (int i1 = 0; i1 < maxString.size(); i1++) {
                while (q > 0 && minString[q + i] != maxString[i1])
                    q = func1[q - 1];
                if (minString[q + i] == maxString[i1]) q++;
                if (q == length) {
                    if (!found) {
                        cout << length;
                        found = true;
                    }
                    if (t1IsMin) {
                        cout << "\n" << i1 - length + 1 << " " << i;
                    } else {
                        cout << "\n" << i << " " << i1 - length + 1;
                    }
                    q = func1[q - 1];
                }
            }
        }
        if (found) return;
    }
}

vector<SubString> KMPAlgorithm::debugrun(string t1, string t2) {
    vector<SubString> result;
    vector<char> minString, maxString;
    bool t1IsMin = false;
    if (t1.length() < t2.length()) {
        t1IsMin = true;
        minString = toCharVector(t1);
        maxString = toCharVector(t2);
    } else {
        maxString = toCharVector(t1);
        minString = toCharVector(t2);
    }

    int length;
    for (length = minString.size(); length > 0; length--) {
        bool found = false;
        for (int i = 0; i <= (minString.size() - length); i++) {
            vector <int> func1(length);
            func1[0] = 0;
            int k = i;

            for (int q1 = i + 1; q1 < length + i; q1++) {
                while (k > i && minString[k] != minString[q1])
                    k = func1[k - 1 - i] + i;
                if (minString[k] == minString[q1]) k++;
                func1[q1 - i] = k - i;
            }
            int q = 0;
            for (int i1 = 0; i1 < maxString.size(); i1++) {
                while (q > 0 && minString[q + i] != maxString[i1])
                    q = func1[q - 1];
                if (minString[q + i] == maxString[i1]) q++;
                if (q == length) {
                    SubString ss;
                    if (t1IsMin) {
                        ss.shift1 = i1 - length + 1;
                        ss.shift2 = i;
                    } else {
                        ss.shift1 = i;
                        ss.shift2 = i1 - length + 1;
                    }
                    result.push_back(ss);
                    q = func1[q - 1];
                    found = true;
                }
            }
        }
        if (found) {
            maxLength = length;
            return result;
        }
    }
}

vector<SubString> verify(string s1, string s2) {
    int L[s1.size()][s2.size()];
    int z = 0;
    vector<SubString> list;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0)
                    L[i][j] = 1;
                else
                    L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > z) {
                    z = L[i][j];
                    list.clear();
                }
                if (L[i][j] == z) {
                    SubString ss;
                    ss.shift1 = i - z + 1;
                    ss.shift2 = j - z + 1;
                    list.push_back(ss);
                }
            }
        }
    }
}

void KMPAlgorithm::sort(vector<SubString>& v) {

}

int main(int argc, char** argv) {
    string s = "bbbabbabba";
    string t = "baabababab";
    KMPAlgorithm algo;
    vector<SubString> result = algo.debugrun(s, t);
    cout << algo.getMaxLength();
    for (int i = 0; i < result.size(); i++) {
        SubString ss = result[i];
        cout << endl << ss.shift1 << " " << ss.shift2;
    }
    cout << endl;

    vector<SubString> solution = verify(s, t);
    for (int i = 0; i < solution.size(); i++) {
        SubString ss = solution[i];
        cout << endl << ss.shift1 << " " << ss.shift2;
    }

    return 0;
}

