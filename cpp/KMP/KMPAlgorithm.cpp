/* 
 * File:   KMPAlgorithm.cpp
 * Author: Karlson
 *
 * Created on 31. Januar 2011, 15:58
 */

#include "KMPAlgorithm.h"
#include "FileLoader.h"

void KMPAlgorithm::calculatePrefixFunction(char* pattern, uint start, uint minLength) {
    prefixFunction[0] = 0;
    int k = start;

    for (uint q = start + 1; q < minLength; q++) {
        while (k > start && pattern[k] != pattern[q])
            k = prefixFunction[k - 1 - start] + start;
        if (pattern[k] == pattern[q]) k++;
        prefixFunction[q - start] = k - start;
    }
}

list<SubString> KMPAlgorithm::run(char* t1, char* t2) {
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

    list<SubString> currentShifts;
    uint currentLongestPrefix = 0;
    for (uint shift = 0; shift < minLength - currentLongestPrefix+1; shift++) {
        if (debug) cout << shift << endl;
        calculatePrefixFunction(minString, shift, minLength);

        int q = 0;
        for (uint textpos = 0; textpos < maxLength; textpos++) {
            while (q > 0 && minString[q + shift] != maxString[textpos])
                q = prefixFunction[q - 1];
            if (minString[q + shift] == maxString[textpos]) q++;
            if (q > currentLongestPrefix) {
                currentLongestPrefix = q;
                currentShifts.clear();
            }
            if (q == currentLongestPrefix) {
                SubString ss;
                ss.shift1 = textpos - currentLongestPrefix +1;
                ss.shift2 = shift;
                currentShifts.push_back(ss);
            }
            if (q == minLength - shift) {
                q = prefixFunction[q - 1];
            }
        }
    }
    cout << currentLongestPrefix;
    return currentShifts;
}

list<SubString> KMPAlgorithm::verify(char* t1, char* t2) {
	int L[s_length][t_length];
	list<SubString> currentShifts;

    int z = 0;
    for (uint i = 0; i < s_length; i++) {
        for (uint j = 0; j < t_length; j++) {
            if (t1[i] == t2[j]) {
                if (i == 0 || j == 0)
                    L[i][j] = 1;
                else
                    L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > z) {
                    z = L[i][j];
                    currentShifts.clear();
                }
                if (L[i][j] == z) {
                    SubString ss;
                    ss.shift1 = i - z + 1;
                    ss.shift2 = j - z + 1;

                    currentShifts.push_back(ss);
                }
            } else {
            	L[i][j]=0;
            }
        }
    }

    return currentShifts;
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


    list <SubString> result= algo.run(s, t);
    //list <SubString> result= algo.verify(s,t);
    while (!result.empty()){
        SubString arr = result.front();
        result.pop_front();
        cout << endl << arr.shift1 << " " << arr.shift2;
    }

    return 0;
}

