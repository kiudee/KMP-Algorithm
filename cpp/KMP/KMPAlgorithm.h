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
typedef unsigned int uint;

class KMPAlgorithm {
public:
    void run(char* t1, char* t2);
    uint s_length, t_length;

private:
    static const bool debug = true;
    uint* prefixFunction;

    void calculatePrefixFunction(char* pattern, uint shift, uint length);
};

