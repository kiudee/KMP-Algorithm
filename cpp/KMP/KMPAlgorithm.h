/* 
 * File:   KMPAlgorithm.h
 * Author: Karlson
 *
 * Created on 1. Februar 2011, 10:33
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct SubString {
    int shift1;
    int shift2;
};

class KMPAlgorithm {
public:
    vector<SubString> run(vector<char> t1, vector<char> t2);

    int getMaxLength() const {
        return maxLength;
    }
private:
    static const bool debug = true;
    int maxLength;
    vector<int> calculatePrefixFunction(vector<char> pattern, int shift, int length);
};

