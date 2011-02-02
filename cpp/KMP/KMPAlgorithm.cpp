/* 
 * File:   KMPAlgorithm.cpp
 * Author: Karlson
 *
 * Created on 31. Januar 2011, 15:58
 */
#include "KMPAlgorithm.h"
#include "FileLoader.h"

void KMPAlgorithm::calculatePrefixFunction(char* pattern, uint shift, uint length) {
    prefixFunction[0] = 0;
    int k = shift;

    for (uint q = shift + 1; q < length + shift; q++) {
        while (k > shift && pattern[k] != pattern[q])
            k = prefixFunction[k - 1 - shift] + shift;
        if (pattern[k] == pattern[q]) k++;
        prefixFunction[q - shift] = k - shift;
    }
}

void KMPAlgorithm::run(char* t1, char* t2) {
    char *minString, *maxString;
    uint minLength, maxLength;
    bool t1IsMin = false;
    if (s_length < t_length) {
        t1IsMin = true;
        minString = t1;
        minLength = s_length;
        maxString = t2;
        maxLength = t_length;
    } else {
        maxString = t1;
        maxLength = s_length;
        minString = t2;
        minLength = t_length;
    }
    prefixFunction = new uint[minLength];

    uint length;
    for (length = minLength; length > 0; length--) {
        bool found = false;
        for (uint shift = 0; shift <= (minLength - length); shift++) {
            calculatePrefixFunction(minString, shift, length);

            int q = 0;
            for (uint i1 = 0; i1 < maxLength; i1++) {
                while (q > 0 && minString[q + shift] != maxString[i1])
                    q = prefixFunction[q - 1];
                if (minString[q + shift] == maxString[i1]) q++;
                if (q == length) {
                    if (!found) {
                        cout << length;
                    }
                    cout << endl << i1 - length + 1 << " " << shift;
                    q = prefixFunction[q - 1];
                    found = true;
                }
            }
        }
        if (found) {
            return;
        }
    }
}

vector<SubString> verify(vector<char> s1, vector<char> s2) {
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

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Error: 2 Arguments expected!";
        exit(1);
    }
    FileLoader fileLoader;
    char *s, *t;
    KMPAlgorithm algo;
    fileLoader.load(argv[1], s, &algo.s_length);
    fileLoader.load(argv[2], t, &algo.t_length);


    algo.run(s, t);

    return 0;
}

