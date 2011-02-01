/* 
 * File:   KMPAlgorithm.cpp
 * Author: Karlson
 *
 * Created on 31. Januar 2011, 15:58
 */
#include "KMPAlgorithm.h"
#include "FileLoader.h"

vector<int> KMPAlgorithm::calculatePrefixFunction(vector<char> pattern, int shift, int length) {
    vector<int> func(length);
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

vector<SubString> KMPAlgorithm::run(vector<char> t1, vector<char> t2) {
    vector<SubString> result;
    vector<char> *minString, *maxString;
    bool t1IsMin = false;
    if (t1.size() < t2.size()) {
        t1IsMin = true;
        minString = &t1;
        maxString = &t2;
    } else {
        maxString = &t1;
        minString = &t2;
    }

    int length;
    for (length = minString->size(); length > 0; length--) {
        bool found = false;
        for (int shift = 0; shift <= (minString->size() - length); shift++) {
            vector <int> prefix = calculatePrefixFunction(*minString, shift, length);

            int q = 0;
            for (int i1 = 0; i1 < maxString->size(); i1++) {
                while (q > 0 && (*minString)[q + shift] != (*maxString)[i1])
                    q = prefix[q - 1];
                if ((*minString)[q + shift] == (*maxString)[i1]) q++;
                if (q == length) {
                    if (debug) {
                        SubString ss;
                        if (t1IsMin) {
                            ss.shift1 = i1 - length + 1;
                            ss.shift2 = shift;
                        } else {
                            ss.shift1 = shift;
                            ss.shift2 = i1 - length + 1;
                        }
                        result.push_back(ss);
                    } else {
                        cout << endl << i1 - length +1 << " " << shift;
                    }
                    q = prefix[q - 1];
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
    if (argc != 3){
        cout<< "Error: 2 Arguments expected!";
        exit(1);
    }
    FileLoader fileLoader;
    vector<char> s = fileLoader.load(argv[1]);
    vector<char> t = fileLoader.load(argv[2]);
    
    KMPAlgorithm algo;
    vector<SubString> result = algo.run(s, t);
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

