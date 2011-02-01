/* 
 * File:   KMPAlgorithm.h
 * Author: Karlson
 *
 * Created on 1. Februar 2011, 10:33
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct SubString {
        int shift1;
        int shift2;
    };
class KMPAlgorithm {
public:

    
    void run(string t1, string t2);
    vector<SubString> debugrun(string t1, string t2);
    int getMaxLength() const {
        return maxLength;
    }
private:
    vector<char> toCharVector(string s);
    int maxLength;
    void sort (vector<SubString> &v);
};

